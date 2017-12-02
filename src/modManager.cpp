#include "modManager.hpp"

void modManager::loadMod(std::string mod_name)
{
    void (*init_mod)() = NULL;


    mods.at(mod_name) = dlopen(mod_name.c_str(), RTLD_LAZY);

    dlerror();

    init_mod = (void (*)())dlsym(mods.at(mod_name), "initializeMod");

    init_mod();
}

void modManager::closeAllMods()
{
    std::map<std::string, void*>::iterator it = mods.begin();
    while(it != mods.end())
    {
        dlclose(it->second);
    }
}