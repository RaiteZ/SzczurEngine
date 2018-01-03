#pragma once

#include <SFML/Graphics.hpp>

#include "Szczur/Modules/GUI/GUI.hpp"
#include "Szczur/Utility/Modules.hpp"

#include "Szczur/Modules/GUI/ImageWidget.hpp"
#include "Szczur/Modules/GUI/TextWidget.hpp"
#include "Szczur/Modules/GUI/Widget.hpp"


namespace rat {
    class Menu : public Module<GUI>, Module<>::Inputable {
        using Module::Module;
    public:
        void init();
        void input(const sf::Event& event);
    private:
        Widget* _bg;
    };
}