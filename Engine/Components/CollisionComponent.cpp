#include "CollisionComponent.h"
#include "Engine.h"

namespace Ethrl {
    void CollisionComponent::Initialize() {
        auto component = m_Owner->GetComponent<RBPhysicsComponent>();
        if (component) {
            g_PhysicsSystem.SetCollisionBox(component->m_Body, Data, m_Owner);
        }
    }

    void CollisionComponent::Update() {

    }

    void CollisionComponent::OnCollisionEnter(Actor* other) {

    }

    void CollisionComponent::OnCollisionExit(Actor* other) {

    }

    bool CollisionComponent::Write(const rapidjson::Value& value) const {
        return true;
    }

    bool CollisionComponent::Read(const rapidjson::Value& value) {
        READ_DATA(value, Data.Size);
        READ_DATA(value, Data.Density);
        READ_DATA(value, Data.Friction);
        READ_DATA(value, Data.Restitution);
        READ_DATA(value, Data.IsTrigger);

        return true;
    }
}