#include "TextWidget.hpp"

namespace rat {
    sf::Text TextWidget::createText(const std::string& text, const sf::Color& color, size_t charSize) {
        sf::Text temp;
        temp.setString(text);
        temp.setFillColor(color);
        temp.setCharacterSize(charSize);
        return temp;
    }

    TextWidget::TextWidget(const sf::Text& text, const std::string& path) :
    _text(text) {
        _font.loadFromFile(path);
        _text.setFont(_font);
    }

    sf::Vector2u TextWidget::_getSize() const {
        auto rect = _text.getGlobalBounds();
        return {
            static_cast<unsigned int>(rect.left + rect.width),
            static_cast<unsigned int>(rect.top + rect.height)
        };
    }

    void TextWidget::_draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_text, states);
    }

    void TextWidget::setColor(const sf::Color& newColor) {
        _text.setFillColor(newColor);
    }

}