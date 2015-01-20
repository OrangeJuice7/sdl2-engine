#include "Game.h"
#include "Logger.h"
#include "Configuration.h"
#include "SDL_Systems.h"

int main(int argc, char** argv) {

	// Unused for now, so avoiding compiler warnings.
	(static_cast<void>(argc));
	(static_cast<void>(argv));

	Log(DEBUG) << "Starting sdl2-engine...";

	Configuration::Initialize();

	const bool systemsInitialized = sdl::Initialize();

	if(systemsInitialized) {
		Game::instance().runGame();
		delete &Game::instance();
	}
	else {
		Log(ERROR) << "Systems were not initialized.";
	}

	sdl::Close();

	Log(DEBUG) << "Exiting sdl2-engine...";
	return 0;
}
