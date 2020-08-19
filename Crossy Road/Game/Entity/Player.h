#pragma once

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>



    /**
        Represents the player
    */
    class Player 
    {
    public:
        constexpr static int WIDTH = 44;
        constexpr static int HEIGHT = 32;

        Player();

        void inputKeyPress();
        void update(float dt);
        void draw(sf::RenderTarget& target);           

        const sf::Vector2f& getPosition() const;
       // void onCollide(Collidable& other) override;
     
        bool isAlive() const;

    private:
        void restart();

        sf::RectangleShape people;     
        sf::Vector2f v_speed;   
        sf::Vector2f origin_pos = { 640, 720 - 10 };

        bool is_Alive = true;        

       
    };
