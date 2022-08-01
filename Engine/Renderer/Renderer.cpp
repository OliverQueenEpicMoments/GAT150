#include "Renderer.h"
#include <SDL.h>
#include <SDL_ttf.h>

namespace Ethrl {
	

	void Renderer::Initialize() {
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
	}

	void Renderer::Shutdown() {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		TTF_Quit();
	}

	void Renderer::CreateWindow(const char* Name, int Width, int Height) {
		m_Width = Width;
		m_Height = Height;

		m_window = SDL_CreateWindow(Name, 100, 100, Width, Height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
	void Renderer::BeginFrame() {
		SDL_SetRenderDrawColor(m_renderer,m_ClearColor.R, m_ClearColor.G, m_ClearColor.B, m_ClearColor.A);
		SDL_RenderClear(m_renderer);
	}

	void Renderer::EndFrame() {
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::DrawLine(float X1, float Y1, float X2, float Y2) {
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawLineF(m_renderer, X1, Y1, X2, Y2);
	}

	void Renderer::DrawLine(const Vector2& V1, const Vector2& V2, const Color& color) {
		SDL_SetRenderDrawColor(m_renderer, color.R, color.G, color.B, color.A);
		SDL_RenderDrawLineF(m_renderer, V1.X, V1.Y, V2.X, V2.Y);
	}

	void Renderer::DrawPoint(float X, float Y) {
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		SDL_RenderDrawPointF(m_renderer, X, Y);
	}

	void Renderer::DrawPoint(const Vector2& V, const Color& color) {
		SDL_SetRenderDrawColor(m_renderer, color.R, color.G, color.B, color.A);
		SDL_RenderDrawPointF(m_renderer, V.X, V.Y);
	}
}