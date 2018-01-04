#pragma once

#include <SFML/Graphics.hpp>

#include "Szczur/Modules/GUI/GUI.hpp"
#include "Szczur/Modules/Canvas/Canvas.hpp"
#include "Szczur/Utility/Modules.hpp"

#include "Szczur/Modules/GUI/ImageWidget.hpp"
#include "Szczur/Modules/GUI/TextWidget.hpp"
#include "Szczur/Modules/GUI/Widget.hpp"


namespace rat {
    class Menu : public Module<GUI, Canvas>, Module<>::Inputable {
        using Module::Module;
    public:
        void init();
        void input(const sf::Event& event);
    private:
        Widget* _bg;
    };
}