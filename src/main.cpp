#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "TextureManager.hpp"
#include "WorldLoader.hpp"
#include "goManager.hpp"
#include "modManager.hpp"
#include "ModdingAPI.hpp"

modManager		mm;
TextureManager  texm;
goManager		gom;
modAPI			mapi;
WorldLoader		wl;
sf::View        view(sf::Vector2f(0, 0), sf::Vector2f(10*32, 10*32/4*3));


int main()
{
	std::cout << "Welcome to SFML_RPG version 0.0000001" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	sf::RenderWindow Window(sf::VideoMode(800, 600), "My Window");

	mapi.sroGom(&gom);
	mapi.sroTexm(&texm);

	Window.setView(view);
	Window.setVerticalSyncEnabled(true);
	Window.setFramerateLimit(60);

	mm.loadMod("RPG_TEST_MOD", "Mods/", &mapi);

	wl.loadWorld("map.txt", &texm, &gom, &mm, &mapi);

	while (Window.isOpen())
	{
		sf::Event event;
		Window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			Window.close();
		} else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
		{
			Window.close();
		}
		Window.clear();
		if(gom.go_vector.size() != 0)
		{
			for (unsigned int i = 0; i < gom.go_vector.size(); i++)
			{
				gom.go_vector.at(i)->render(&Window);
			}
		}

		Window.display();
	}

	return 0;
}