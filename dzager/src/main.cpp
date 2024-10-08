#include <iostream>
#include <fstream>
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
	mINI::INIFile iniFile("settings.ini");
	mINI::INIStructure ini;
	iniFile.read(ini);

	float screenHeight      = parseOrDefault(ini["settings"]["screenHeight"], 1080.f);
	float dpi               = parseOrDefault(ini["settings"]["dpi"]         , 400.f);
	float sens              = parseOrDefault(ini["settings"]["sens"]        , 9.f);
	std::string startWpn    = parseOrDefault(ini["settings"]["startWpn"]    , "m16");
	std::string weaponsFile = parseOrDefault(ini["settings"]["file"]        , "weapons.json");

	float recoilFactor = screenHeight / (dpi * sens);
	
	std::cout << "screenHeight  : " << screenHeight << "\n";
	std::cout << "sens          : " << sens         << "\n";
	std::cout << "dpi           : " << dpi          << "\n";
	std::cout << "recoilFactor  : " << recoilFactor << "\n";
	std::cout << "startWpn      : " << startWpn     << "\n";
	std::cout << "weapons file  : " << weaponsFile  << "\n";

	InputController controller    = InputController(weaponsFile, startWpn);
	RecoilCompensator compensator = RecoilCompensator(recoilFactor, controller.getCurrentPattern());
	controller.registerObserver(&compensator);

	std::thread compensatorThread = std::thread(&RecoilCompensator::compensateRecoil, &compensator);
	std::thread controllerThread  = std::thread(&InputController::getInput,           &controller);

	compensatorThread.join();
	controllerThread.join();

	return 0;
}