#include "Menu.hpp"

namespace rat {
    void Menu::init() {
        auto& gui = _getModule<GUI>();
        gui.loadAsset<sf::Texture>("data/resume.png");
        gui.loadAsset<sf::Texture>("data/exit.png");
        gui.loadAsset<sf::Texture>("data/resume-press.png");
        gui.loadAsset<sf::Texture>("data/exit-press.png");
        gui.loadAsset<sf::Texture>("data/resume-hover.png");
        gui.loadAsset<sf::Texture>("data/exit-hover.png");
    
        Widget* bg = new Widget;
        bg->setPosition(500,300);
        gui.add(bg);

        ImageWidget* resume = new ImageWidget(gui.getAsset<sf::Texture>("data/resume.png"));

        ImageWidget* exit = new ImageWidget(gui.getAsset<sf::Texture>("data/exit.png"));
        exit->setPosition(sf::Vector2f(0.f, 128.f));

        bg->add(resume);
        bg->add(exit);

        bg->deactivate();
        bg->invisible();

        resume->setCallback(Widget::CallbackType::onRelease, [bg, &gui, resume](Widget*){
            resume->setTexture(gui.getAsset<sf::Texture>("data/resume-hover.png"));
            bg->deactivate();
            bg->invisible();
            return true;
        });

        resume->setCallback(Widget::CallbackType::onHoverIn, [resume, &gui](Widget*){
            resume->setTexture(gui.getAsset<sf::Texture>("data/resume-hover.png"));
            return true;
        });

        resume->setCallback(Widget::CallbackType::onHoverOut, [resume, &gui](Widget*){
            resume->setTexture(gui.getAsset<sf::Texture>("data/resume.png"));
            return true;
        });

        resume->setCallback(Widget::CallbackType::onPress, [resume, &gui](Widget*){
            resume->setTexture(gui.getAsset<sf::Texture>("data/resume-press.png"));
            return true;
        });


        exit->setCallback(Widget::CallbackType::onHoverIn, [exit, &gui](Widget*){
            exit->setTexture(gui.getAsset<sf::Texture>("data/exit-hover.png"));
            return true;
        });

        exit->setCallback(Widget::CallbackType::onHoverOut, [exit, &gui](Widget*){
            exit->setTexture(gui.getAsset<sf::Texture>("data/exit.png"));
            return true;
        });

        exit->setCallback(Widget::CallbackType::onPress, [exit, &gui](Widget*){
            exit->setTexture(gui.getAsset<sf::Texture>("data/exit-press.png"));
            return true;
        });

        exit->setCallback(Widget::CallbackType::onRelease, [exit, &gui](Widget*){
            exit->setTexture(gui.getAsset<sf::Texture>("data/exit-hover.png"));
            return true;
        });

        _bg = bg;
    }

    void Menu::input(const sf::Event& event) {
        if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
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