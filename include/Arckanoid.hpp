/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** Arckanoid
*/

#ifndef ARCKANOID_HPP_
    #define ARCKANOID_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <SFML/System.hpp>
    #include <SFML/Network.hpp>
    #include <SFML/Window.hpp>
    #include <stdbool.h>

namespace Arckanoid {
    class Ball {
        private:
            sf::CircleShape shape;
            sf::Vector2f velocity;
        public:
            Ball(float x, float y, float radius);
            ~Ball() = default;
            void move();
            void checkCollisionWithWalls(float windowWidth, float windowHeight);
            //void checkCollisionWithPaddle(Paddle& paddle);
            //void checkCollisionWithBricks(std::vector<Brick>& bricks);
            void update();
            sf::CircleShape getShape() { return shape; }
    };
    
    class Paddle {
        private:
            sf::RectangleShape shape;
            float speed;
        public:
            Paddle(float x, float y, float width, float height);
            ~Paddle() = default;
            void moveLeft();
            void moveRight();
            void checkCollisionWithWalls(float windowWidth);
            void update();
            sf::RectangleShape getShape() { return shape; }
    };
    class Brick {

        private:
            sf::RectangleShape shape;
            int points;
        public:
            Brick(float x, float y, float width, float height, sf::Color color, int points);
            ~Brick() = default;
            bool isCollidingWithBall(const Ball& ball);
            void update();
            sf::RectangleShape getShape() { return shape; }
    };
    class Level {
        private:
            std::vector<Brick> bricks;
            int remainingBricks;
        public:
            Level();
            ~Level() = default;
            void loadLevel(int levelNumber);
            bool isLevelComplete();
            void update();
    };
};

#endif /* !ARCKANOID_HPP_ */
