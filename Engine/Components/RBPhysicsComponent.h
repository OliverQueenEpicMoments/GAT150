#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace Ethrl {
	class RBPhysicsComponent : public PhysicsComponent {
	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		void Initialize() override;
		void Update() override;
		virtual void ApplyForce(const Vector2& Force);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
		
	private:
		PhysicsSystem::RigidBodyData Data;
		b2Body* m_Body = nullptr;
	};
}