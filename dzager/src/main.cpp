#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <Windows.h>

#include "mini/ini.h"
#include "json/json.h"

#include "offset-factory.h"
#include "recoil-compensator.h"
#include "movement-randomizer.h"
#include "input-controller.h"

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

	float screenHeight         = parseOrDefault(ini["settings"]["screenHeight"], 1080.f);
	float dpi                  = parseOrDefault(ini["settings"]["dpi"]         , 400.f);
	float sens                 = parseOrDefault(ini["settings"]["sens"]        , 9.f);
	std::string defaultPattern = parseOrDefault(ini["settings"]["default"]     , "val");

	float recoilFactor = screenHeight / (dpi * sens * 2.f);
	
	std::cout << "screenHeight  : " << screenHeight << "\n";
	std::cout << "sens          : " << sens << "\n";
	std::cout << "dpi           : " << dpi << "\n";
	std::cout << "recoilFactor  : " << recoilFactor << "\n";
	std::cout << "defaultPattern: " << defaultPattern << "\n";

	// MovementRandomizer randomizer = MovementRandomizer();
	// std::thread randomizerThread  = std::thread(&MovementRandomizer::doMovement, &randomizer);

	OffsetFactory factory = OffsetFactory();
	std::vector<offset> pattern = factory.getPattern(defaultPattern);
	RecoilCompensator compensator = RecoilCompensator(recoilFactor, pattern);
	
	InputController controller = InputController(&factory);
	controller.registerObserver(&compensator);

	std::thread compensatorThread = std::thread(&RecoilCompensator::compensateRecoil, &compensator);
	std::thread consoleReaderThread = std::thread(&InputController::getInput, &controller);

	compensatorThread.join();
	consoleReaderThread.join();

	// randomizerThread.join();

	return 0;
}