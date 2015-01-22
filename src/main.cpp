#include "core/SDL_Systems.h"
#include "engine/Game.h"
#include "util/Configuration.h"
#include "util/Logger.h"

int main(int argc, char** argv) {

	// Unused for now, so avoiding compiler warnings.
	(static_cast<void>(argc));
	(static_cast<void>(argv));

	logger::debug() << "Starting sdl2-engine...";

	Configuration::Initialize();

	const bool k_systems_initialized = sdl::Initialize();

	if(k_systems_initialized) {
		Game::instance().runGame();
		delete &Game::instance();
	}
	else {
		logger::error() << "Systems were not initialized.";
	}

	sdl::Close();

	logger::debug() << "Exiting sdl2-engine...";
	return 0;
}
