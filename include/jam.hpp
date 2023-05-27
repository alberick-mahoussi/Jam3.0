/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** jam
*/

#ifndef JAM_HPP_
    #define JAM_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <SFML/System.hpp>
    #include <SFML/Network.hpp>
    #include <SFML/Window.hpp>
    #include <stdbool.h>
    #include "Menu.hpp"
    #include "InputHoppy.hpp"


    namespace Jam {
        class Game {
            public:
                sf::RenderWindow window;
                sf::Font font;
                sf::Color backgroundColor;
                Jam::Menu menu;
                Jam::InputHoppy inputHoppy;
            public:
                Game();
                ~Game() = default;
        };
    };

#endif /* !JAM_HPP_ */
