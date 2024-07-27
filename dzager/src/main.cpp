#include <iostream>
#include <thread>
#include <Windows.h>
#include "mini/ini.h"
#include "offset-factory.h"
#include "recoil-compensator.h"
#include "movement-randomizer.h"

float parseOfDefault(std::string str, float dflt) {
	if (str.empty()) return dflt;
	float out;
	try {
		out = std::stof(str);
	} catch (const std::invalid_argument& e) {
		out = dflt;
	}
	return out;
}

int main() {
	mINI::INIFile file("settings.ini");
	mINI::INIStructure ini;
	file.read(ini);

	float screenHeight = parseOfDefault(ini["settings"]["screenHeight"], 1080.f);
	float dpi          = parseOfDefault(ini["settings"]["dpi"]         , 400.f);
	float sens         = parseOfDefault(ini["settings"]["sens"]        , 9.f);
	float recoilFactor = screenHeight / (dpi * sens * 2.f);
	
	std::cout << "screenHeight: " << screenHeight << "\n";
	std::cout << "sens:         " << sens << "\n";
	std::cout << "dpi:          " << dpi << "\n";
	std::cout << "recoilFactor: " << recoilFactor << "\n";

	RecoilCompensator compensator = RecoilCompensator(recoilFactor, OffsetFactory::createSoldier());
	// MovementRandomizer randomizer = MovementRandomizer();

	std::thread compensatorThread = std::thread(&RecoilCompensator::compensateRecoil, &compensator);
	// std::thread randomizerThread  = std::thread(&MovementRandomizer::doMovement, &randomizer);

	compensatorThread.join();
	// randomizerThread.join();

	return 0;
}