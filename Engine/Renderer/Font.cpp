#include "Font.h"
#include <Core/Logger.h>
#include <SDL_ttf.h>

namespace Ethrl {
	Font::Font(const std::string& FileName, int FontSize) {
		Load(FileName, FontSize);
	}

	Font::~Font() {
		if (m_tffFont) {
			TTF_CloseFont(m_tffFont);
			m_tffFont = nullptr;
		}
	}

	bool Font::Create(std::string FileName, ...) {
		va_list args;
		va_start(args, FileName);

		int FontSize = va_arg(args, int);

		va_end(args);

		return Load(FileName, FontSize);
	}

	SDL_Surface* Font::CreateSurface(const std::string& Text, const Color& color) {
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_tffFont, Text.c_str(), c);

		if (surface == nullptr) LOG(SDL_GetError());
		return surface;
	}

	bool Font::Load(const std::string& FileName, int FontSize) {
		m_tffFont = TTF_OpenFont(FileName.c_str(), FontSize);
		if (m_tffFont == nullptr) {
			LOG("SDL Error: %s", SDL_GetError());
			return false;
		}
		return true;
	}
}