#include "GStatePlaceholder.h"
#include "Game.h"
#include "Logger.h"

GStatePlaceholder::GStatePlaceholder() :
	image(nullptr),
	animation(nullptr),
	animationClip{0, 0, 0, 0}
{

}

GStatePlaceholder::~GStatePlaceholder() {
	delete this->animation;
}

void GStatePlaceholder::load() {
	logger::debug() << "Loading STATE placeholder...";

	logger::info() << "Press SPACEBAR for the SFX.";

	this->animation = new Animation(0, 4, 32, 32, 5, 5.0);
	this->animationClip = {0, 0, 0, 0};
	this->image = Game::instance().getResource().sprite("assets/images/spritesheet.png");

	Game::instance().getAudioHandler().ChangeMusic("assets/audio/music/test_music.flac");
}

void GStatePlaceholder::unload() {
	logger::debug() << "\tUnloading STATE placeholder...";

	StateGame::unload();
}

void GStatePlaceholder::update(const double dt_) {
	const std::array<bool, GameKeys::MAX> keyStates = Game::instance().getInput();

	if(keyStates[GameKeys::SPACE] == true) {
		Game::instance().getAudioHandler().PlaySoundEffect("assets/audio/sfx/test_sfx.wav");
	}

	this->animation->Update(this->animationClip, dt_);
}

void GStatePlaceholder::render() {
	this->image->render(0, 0, &this->animationClip, true);
}
