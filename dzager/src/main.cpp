#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <Windows.h>

#include "include/mini/ini.h"
#include "include/json/json.h"

#include "include/offset-factory.h"
#include "include/recoil-compensator.h"
#include "include/input-controller.h"

float parseOrDefault(std::string str, float dflt) {
	if (str.empty()) return dflt;
	try {
		return std::stof(str);
	} catch (const std::invalid_argument& e) {
		return dflt;
	}
}

std::string parseOrDefault(std::string str, std::string dflt) {
	if (str.empty()) return dflt;
	return str;
}

int main() {
	mINI::INIFile file("settings.ini");
	mINI::INIStructure ini;
	file.read(ini);

	float screenHeight   = parseOrDefault(ini["settings"]["screenHeight"], 1080.f);
	float dpi            = parseOrDefault(ini["settings"]["dpi"]         , 400.f);
	float sens           = parseOrDefault(ini["settings"]["sens"]        , 9.f);
	std::string startWpn = parseOrDefault(ini["settings"]["startWpn"]    , "m16");

	float recoilFactor = screenHeight / (dpi * sens);
	
	std::cout << "screenHeight  : " << screenHeight << "\n";
	std::cout << "sens          : " << sens << "\n";
	std::cout << "dpi           : " << dpi << "\n";
	std::cout << "recoilFactor  : " << recoilFactor << "\n";
	std::cout << "startWpn      : " << startWpn << "\n";

	auto weapons = read_weapons_json(R"({
	"weapons":[
		{
			"name":"m16",
			"rpm":700,
			"magSize":30,
			"recoil":15.0
		},
		{
			"name":"ak47",
			"rpm":600,
			"magSize":30,
			"recoil":19.0
		},
		{
			"name":"ak12",
			"rpm":650,
			"magSize":30,
			"recoil":15.0
		},
		{
			"name":"vector",
			"rpm":1100,
			"magSize":25,
			"recoil":30.0
		},
		{
			"name":"ak308",
			"rpm":650,
			"magSize":20,
			"recoil":22.0
		},
		{
			"name":"ak74m",
			"rpm":630,
			"magSize":30,
			"recoil":16.0
		},
		{
			"name":"g36",
			"rpm":750,
			"magSize":30,
			"recoil":16.0
		},
		{
			"name":"val",
			"rpm":850,
			"magSize":20,
			"recoil":15.0
		}
	]
})");

	OffsetFactory factory = OffsetFactory(weapons);

	std::vector<offset> pattern = factory.getWeaponPattern(startWpn);

	RecoilCompensator compensator = RecoilCompensator(recoilFactor, pattern);
	
	InputController controller = InputController(&factory);
	controller.registerObserver(&compensator);

	std::thread compensatorThread = std::thread(&RecoilCompensator::compensateRecoil, &compensator);
	std::thread controllerThread = std::thread(&InputController::getInput, &controller);

	compensatorThread.join();
	controllerThread.join();

	return 0;
}