#pragma once
#include "GameObject.h"

namespace Ethrl {
	class Actor;
	class Component : public GameObject {
	public:
		Component() = default;

		virtual void Update() = 0;

		friend class Actor;

	protected:
		Actor* m_Owner = nullptr;
	};
}