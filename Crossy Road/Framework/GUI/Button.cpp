#include "Button.h"

Button::Button(ButtonSize s)
{
    _button.setOutlineThickness(1);
    _button.setOutlineColor(sf::Color::Blue);
    _button.setFillColor(sf::Color::Yellow);
    switch (s) {
    case ButtonSize::Wide:
        _button.setSize({ 256, 64 });
        break;

    case ButtonSize::Small:
        _button.setSize({ 128, 64 });
        break;
    }
}

void Button::setFunction(std::function<void(void)>func)
{
    _function = func;
}

void Button::setText(const std::string& str)
{
    _text.setString(str);
    updateText();
}

void Button::setTexture(const sf::Texture& tex)
{
    _button.setTexture(&tex);
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    auto pos = sf::Mouse::getPosition(window);

    switch (e.type) {
    case sf::Event::MouseButtonPressed:
        switch (e.mouseButton.button) {
        case sf::Mouse::Left:
            if (_button.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {
                _function();
            }
        default:
            break;
        }
    default:
        break;
    }
}

void Button::render(sf::RenderTarget& renderer)
{
    renderer.draw(_button);
    renderer.draw(_text);
}

void Button::setPosition(const sf::Vector2f& pos)
{
    _pos = pos;
    _button.setPosition(_pos);
    _text.setPosition(_pos);
    updateText();
}

void Button::updateText()
{
    _text.setOrigin(_text.getGlobalBounds().width +70 ,
        _text.getGlobalBounds().height+30 );
    _text.move(_button.getGlobalBounds().width+10 ,
        _button.getGlobalBounds().height);
}


sf::Vector2f Button::getSize() const
{
    return _button.getSize();
}

