#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Szczur/Modules/Canvas/Canvas.hpp"
#include "Szczur/Utility/Modules.hpp"
#include "Szczur/Json.hpp"

#include "Widget.hpp"
#include "GuiJson.hpp"
#include "GuiAssetsManager.hpp"

 
namespace rat {
    class GUI : public Module<Canvas>, Module<>::Inputable, Module<>::Renderable, Module<>::Updatable { 
        using Module::Module;
    public:
        void init();
        void input(const sf::Event& event);
        void update(float deltaTime);
        void render();
        void reload();

        template<typename T>
        void loadAsset(const std::string& file){
            _assets.loadFromFile<T>(file);
        }

        template<typename T>
        T* getAsset(const std::string& file) const {
            return _assets.get<T>(file);
        }

        Widget* add(Widget* obj) {
            return _root.add(obj);
        }
    private:
        Widget _root;
        GuiJson _guiJson;
        BasicGuiAssetsManager _assets;
    };
}