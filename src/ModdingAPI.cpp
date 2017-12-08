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