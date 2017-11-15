#include "TextureManager.hpp"

#include <iostream>

bool TextureManager::addNewTexture(std::string key)
{
    if (texture_map.count(key) == 0)
    {
        texture_map[key] = sf::Texture();
    }
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}