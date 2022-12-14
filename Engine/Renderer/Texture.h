#pragma once
#include "Math\Vector2.h"
#include "Resource/Resource.h"
#include <string>

struct SDL_Texture;
struct SDL_Surface;

namespace Ethrl {
	class Renderer;

	class Texture : public Resource {
	friend class Renderer;
	public:
		Texture() = default;
		~Texture ();

		bool Create(std::string FileName, ...) override;
		bool CreateFromSurface(SDL_Surface* surface, Renderer& renderer);
		bool Load(const std::string& filename, Renderer& renderer);

		Vector2 GetSize() const;

	private:
		SDL_Texture* m_Texture = nullptr;
	};
}