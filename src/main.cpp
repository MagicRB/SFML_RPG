#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "TextureManager.hpp"
#include "TileManager.hpp"
#include "WorldLoader.hpp"
#include "goManager.hpp"

TextureManager  texm;
TileManager     tm;
goManager		gom;
WorldLoader		wl;
sf::View        view(sf::Vector2f(0, 0), sf::Vector2f(10*32, 10*32/4*3));


int main()
{
	//texm.texture_map["stone_wall"] = sf::Texture();
	//texm.texture_map.at("stone_wall").loadFromFile("Textures/stone_wall.png");

	sf::RenderWindow Window(sf::VideoMode(800, 600), "My Window");

	Window.setView(view);
	Window.setVerticalSyncEnabled(true);

	wl.loadWorld("map.txt", &texm, &gom);

	while (Window.isOpen())
	{
		sf::Event event;
		Window.pollEvent(event);
		if (event.type == sf::Event::EventType::Closed)
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
				std::cout << i << std::endl;
				gom.go_vector.at(i)->render(&Window);
			}
		}

		Window.display();
	}

	return 0;
}