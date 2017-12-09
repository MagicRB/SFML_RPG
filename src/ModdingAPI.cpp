#include "ModdingAPI.hpp"

TextureManager* modAPI::grtTexm()
{
    return ptexm;
}

void modAPI::sroTexm(TextureManager* rtexm)
{
    ptexm = rtexm;
}

goManager* modAPI::grtGom()
{
    return pgom;
}

void modAPI::sroGom(goManager* rgom)
{
    pgom = rgom;
}

sf::RenderWindow* modAPI::grtWindow()
{
    return pwindow;
}
void modAPI::sroWindow(sf::RenderWindow* window)
{
    pwindow = window;
}

void modAPI::sorControl(std::function<void(modAPI*, sf::Event)> cor)
{
    overrideControl = cor;
}

std::function<void(modAPI*, sf::Event)>  modAPI::gorControl()
{
    return overrideControl;
}

void modAPI::steWorldFileEntry(std::function<void(modAPI*, std::string)> func)
{
    WorldFileEntryEV.push_back(func);
}

std::vector<std::function<void(modAPI*, std::string)>> modAPI::getWorldFileEntryEV()
{
    return WorldFileEntryEV;
}

modAPI::modAPI()
{

}

modAPI::~modAPI()
{

}