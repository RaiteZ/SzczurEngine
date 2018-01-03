#include "Menu.hpp"

namespace rat {
    void Menu::init() {
        auto& gui = _getModule<GUI>();
        gui.loadAsset<sf::Texture>("data/background.jpg");
        gui.loadAsset<sf::Font>("data/consolab.ttf");
    
        ImageWidget* bg = new ImageWidget(gui.getAsset<sf::Texture>("data/background.jpg"));
        bg->setPosition(100,100);
        gui.add(bg);

        TextWidget* resume = new TextWidget;
        resume->setFont(gui.getAsset<sf::Font>("data/consolab.ttf"));
        resume->setString("RESUME");
        resume->setCharacterSize(20u);
        resume->setColor(sf::Color(255,0,0));
        resume->setPosition(sf::Vector2f(10.f, 10.f));

        TextWidget* leave = new TextWidget;
        leave->setFont(gui.getAsset<sf::Font>("data/consolab.ttf"));
        leave->setString("LEAVE");
        leave->setCharacterSize(20u);
        leave->setColor(sf::Color(255,0,0));
        leave->setPosition(sf::Vector2f(10.f, 60.f));

        bg->add(resume);
        bg->add(leave);

        bg->deactivate();
        bg->invisible();

        resume->setCallback(Widget::CallbackType::onRelease, [bg](Widget*){
            bg->deactivate();
            bg->invisible();
            return true;
        });

        _bg = bg;
    }

    void Menu::input(const sf::Event& event) {
        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
            if(_bg->isActivated()) {
                _bg->invisible();
                _bg->deactivate();
            }
            else {
                _bg->visible();
                _bg->activate();
            }
        }
    }

}