#include "GUI.hpp"

#include <iostream>
#include <fstream>

namespace rat {
    /*template<typename T>
    void GUI::loadAsset(const std::string& file) {
        _assets.loadFromFile<T>(file);
    }

    template<typename T>
    T* GUI::getAsset(const std::string& file) const {
        return _assets.get<T>(file);
    }

    Widget* GUI::add(Widget* obj) {
        return _root.add(obj);
    }*/


    void GUI::init() {
        
        /*_assets.loadFromFile<sf::Texture>("data/button.png");
        _assets.loadFromFile<sf::Texture>("data/button-active.png");
        _assets.loadFromFile<sf::Texture>("data/button-clicked.png");
        _assets.loadFromFile<sf::Texture>("data/check.png");
        _assets.loadFromFile<sf::Texture>("data/check-on.png");
        _assets.loadFromFile<sf::Font>("data/consolab.ttf");
        _assets.loadFromFile<sf::Texture>("data/button.png");
        _assets.loadFromFile<Json>("data/json.json");
        _guiJson.init(_assets.get<Json>("data/json.json"), &_assets, &_root, _getModule<Canvas>().getWindow().getSize());
        */
        //_assets.loadFromFile<sf::Texture>("data/background.jpg");
    }

    

    void GUI::input(const sf::Event& event) {
        if(
            event.type == sf::Event::MouseButtonPressed || 
            event.type == sf::Event::MouseButtonReleased || 
            event.type == sf::Event::MouseMoved ||
            event.type == sf::Event::TextEntered
        ) {
            _root.input(event);
        }
    }

    void GUI::update(float deltaTime) {
        _root.update(deltaTime);
    }

    void GUI::render() {
        _getModule<Canvas>().draw(Canvas::LayerId::GUI, _root);
    }

    void GUI::reload() {
        _guiJson.reload(_getModule<Canvas>().getWindow().getSize(), &_root);
    }
}