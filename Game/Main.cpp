#include "Engine.h"
#include <iostream>

int main() {
	/*std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;*/

	Ethrl::InitializeMemory();
	Ethrl::SetFilePath("../Assets");

	// Initialize Engine
	Ethrl::g_Renderer.Initialize();
	Ethrl::g_InputSystem.Initialize();
	Ethrl::g_AudioSystem.Initialize();

	// Create Window
	Ethrl::g_Renderer.CreateWindow("Neumont", 800, 600);
	Ethrl::g_Renderer.SetClearColor(Ethrl::Color{ 100, 0, 0, 255 });

	{
		// Create Game


		// Muisc Loop
		Ethrl::g_AudioSystem.PlayAudio("Main Theme", true);

		// Images (kirby)
		std::shared_ptr<Ethrl::Texture> texture = std::make_shared<Ethrl::Texture>();
		texture->Create(Ethrl::g_Renderer, "Images/Kirby.png");

		// Create Actors
		Ethrl::Scene scene;

		Ethrl::Transform transform{ {400, 200}, 90, {2.5f, 2.5f} };
		std::unique_ptr<Ethrl::Actor> actor = std::make_unique<Ethrl::Actor>(transform);
		std::unique_ptr<Ethrl::PlayerComponent> pcomponent = std::make_unique<Ethrl::PlayerComponent>();
		actor->AddComponent(std::move(pcomponent));
		std::unique_ptr<Ethrl::SpriteComponent> scomponent = std::make_unique<Ethrl::SpriteComponent>();
		scomponent->m_Texture = texture;
		actor->AddComponent(std::move(scomponent));

		scene.Add(std::move(actor));

		float Angle = 0;

		bool Quit = false;
		while (!Quit) {
			// Update
			Ethrl::g_Time.Tick();
			Ethrl::g_InputSystem.Update();
			Ethrl::g_AudioSystem.Update();

			std::cout << Ethrl::g_Time.time << std::endl; // Time

			if (Ethrl::g_InputSystem.GetKeyState(Ethrl::Key_Escape) == Ethrl::InputSystem::State::Pressed) Quit = true;

			//Game.Update();

			// Update Scene
			Angle += 360.0f * Ethrl::g_Time.DeltaTime;
			scene.Update();

			// Render
			Ethrl::g_Renderer.BeginFrame();

			scene.Draw(Ethrl::g_Renderer); // Big kirby
			Ethrl::g_Renderer.Draw(texture, { 400, 300 }, Angle, {.15f, .15f}, {.5f, .5f}); // Spinning Kirby

			Ethrl::g_Renderer.EndFrame();
		}
		//int I = getchar();
	}

	Ethrl::g_AudioSystem.Shutdown();
	Ethrl::g_Renderer.Shutdown();
}