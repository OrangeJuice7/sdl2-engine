#pragma once

#include <SDL2/SDL_mixer.h>
#include <string>

class Music {

	public:
		/**
		* @brief The constructor.
		*
		* @param path : The path to the music file.
		*/
		explicit Music(const std::string& path);

		/**
		* @brief The destructor.
		*/
		~Music();

		/**
		* @return A pointer to the raw Mix_Music object.
		*/
		Mix_Music* MixMusic();

		/**
		* @return The path given to the constructor.
		*/
		std::string Path();

	private:
		Mix_Music* const m_mix_music; /**< Music data. */
		const std::string m_path; /**< Path to the music file. */

};
