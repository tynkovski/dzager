#include <iostream>
#include <thread>
#include <Windows.h>
#include "mini/ini.h"
#include "offset-factory.h"
#include "recoil-compensator.h"
#include "movement-randomizer.h"

float parseOrDefault(std::string str, float dflt) {
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

	float screenHeight = parseOrDefault(ini["settings"]["screenHeight"], 1080.f);
	float dpi          = parseOrDefault(ini["settings"]["dpi"]         , 400.f);
	float sens         = parseOrDefault(ini["settings"]["sens"]        , 9.f);

	float recoilFactor = screenHeight / (dpi * sens * 2.f);
	
	std::cout << "screenHeight: " << screenHeight << "\n";
	std::cout << "sens:         " << sens << "\n";
	std::cout << "dpi:          " << dpi << "\n";
	std::cout << "recoilFactor: " << recoilFactor << "\n";

	// auto pattern = OffsetFactory::createSoldier();
	// auto pattern = OffsetFactory::createVector();
	// auto pattern = OffsetFactory::createG36();
	// auto pattern = OffsetFactory::createAk308();
	// auto pattern = OffsetFactory::createAk74m();
	// auto pattern = OffsetFactory::createVector();
	auto pattern = OffsetFactory::createAk12();
	RecoilCompensator compensator = RecoilCompensator(recoilFactor, pattern);
	std::thread compensatorThread = std::thread(&RecoilCompensator::compensateRecoil, &compensator);
	compensatorThread.join();

	// MovementRandomizer randomizer = MovementRandomizer();
	// std::thread randomizerThread  = std::thread(&MovementRandomizer::doMovement, &randomizer);
	// randomizerThread.join();

	return 0;
}