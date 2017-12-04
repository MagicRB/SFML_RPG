#include "WorldLoader.hpp"

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

std::vector<std::string> split(const char *str, char c = ' ')
{
    std::vector<std::string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(std::string(begin, str));
    } while (0 != *str++);

    return result;
}

void WorldLoader::loadWorld (std::string world, TextureManager* texm, goManager* gom, modManager* mm)
{
	std::string line;

	std::ifstream file(world_folder + world);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line != "")
			{
				int i = 0;
				
				std::string operation;
				std::string arguments;

				while (line.at(i) != ' ')
				{
					operation += line.at(i);
					i++;
				}
				arguments = line.substr(i + 1, line.size() - 1);

				arguments.erase(std::remove(arguments.begin(), arguments.end(), ' '), arguments.end());

				std::vector<std::string> tokens = split(arguments.c_str(), ';');

				if (operation == ":TILE") {
					tile_defs[tokens.at(0)] = Tile();
					texm->addNewTexture(tokens.at(1));
					texm->texture_map.at(tokens.at(1)).loadFromFile("Textures/" + tokens.at(1) + ".png");
					tile_defs.at(tokens.at(0)).setTexture(texm->texture_map.at(tokens.at(1)));
				} else if (operation == ":CREATE") {
					gom->go_vector.push_back(new Tile(tile_defs.at(tokens.at(0))));
					Tile* t = dynamic_cast<Tile*>(gom->go_vector.at(gom->go_vector.size() - 1));
					t->setTilePosition(atoi(tokens.at(1).c_str()), atoi(tokens.at(2).c_str()));
				} else if (operation == ":MOD")
				{
					mm->loadMod(tokens.at(0), "Mods/");
				}
			}
		}
		file.close();
	}
}

WorldLoader::WorldLoader()
{

}

WorldLoader::~WorldLoader()
{

}