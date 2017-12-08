#include "modManager.hpp"

#include <iostream>

void modManager::loadMod(std::string mod_name, std::string path, modAPI* mapi)
{
    void (*init_mod)(modAPI*) = NULL;


    mods[mod_name] = dlopen((path + mod_name + ".so").c_str(), RTLD_LAZY);

    if (dlerror() != 0)
    {
        std::cout << "Invalid mod path" << std::endl;
        return;
    }

    init_mod = (void (*)(modAPI*))dlsym(mods.at(mod_name), "initializeMod");

    if (dlerror() != 0)
    {
        std::cout << "Invalid mod file" << std::endl;
        return;
    }

    init_mod(mapi);
}

void modManager::closeAllMods()
{
    std::map<std::string, void*>::iterator it = mods.begin();
    while(it != mods.end())
    {
        dlclose(it->second);
    }
    
    mods.erase(mods.begin(), mods.end());
}