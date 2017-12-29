#ifndef MOD_MANAGER_H
#define MOD_MANAGER_H

#include <map>
#include <string>

#include "../include_win32/dlfcn.h"
#include "ModdingAPI.hpp"

class modManager
{
    public:

        std::map<std::string, void*> mods;

        void loadMod(std::string mod_name, std::string path, modAPI* mapi);

        void closeAllMods();

    protected:

        void (*init_mod)(void(*)());

    private:
};
#endif // MOD_MANAGER_H