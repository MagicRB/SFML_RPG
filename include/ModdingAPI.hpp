#ifndef MODDING_API_H
#define MODDING_API_H

#include <functional>
#include <string>
#include <vector>

#include "TextureManager.hpp"
#include "goManager.hpp"

class modAPI
{
    public:
        TextureManager*                 grtTexm();
        void                            sroTexm(TextureManager* rtexm);
        goManager*                      grtGom();
        void                            sroGom(goManager* rtexm);
        sf::RenderWindow*               grtWindow();
        void                            sroWindow(sf::RenderWindow* window);
        sf::View*                       grtView();
        void                            sroView(sf::View* view);

        sf::Event*                      grtEvent();
        void                            sroEvent(sf::Event* event);

        void                            sorControl(std::function<void(modAPI*, sf::Event)> mcorapix);
        std::function<void(modAPI*, sf::Event)>    gorControl();

        void steWorldFileEntry(std::function<void(modAPI*, std::string)> func);
        void steInput(std::function<void(modAPI*)> func);
        
        std::vector<std::function<void(modAPI*, std::string)>> getWorldFileEntryEV();
        std::vector<std::function<void(modAPI*)>> getInputEV();

        int windowScale = 2;

        std::map<unsigned short int, std::function<void(modAPI*)>> keyBindMap;

        modAPI();
        ~modAPI();
    protected:
        
    private:
        
        TextureManager*         ptexm;
        goManager*              pgom;
        sf::RenderWindow*       pwindow;
        sf::View*               pview;
        sf::Event*              pevent;

        std::function<void(modAPI*, sf::Event)> overrideControl;

        std::vector<std::function<void(modAPI*, std::string)>> WorldFileEntryEV;
        std::vector<std::function<void(modAPI*)>> InputEV;

};



#endif // MODDING_API_H