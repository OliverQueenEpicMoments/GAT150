#pragma once
#include "GameObject.h"

namespace Ethrl {
	class Actor;
	class Component : public GameObject, public ISerializable {
	public:
		Component() = default;

		virtual void Initialize() override {}
		virtual void Update() = 0;

		friend class Actor;

	protected:
		Actor* m_Owner = nullptr;
	};
}