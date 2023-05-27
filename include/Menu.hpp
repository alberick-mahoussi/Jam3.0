/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include <vector>
    #include <string>
    #include <SFML/System.hpp>
    #include <SFML/Network.hpp>
    #include <SFML/Window.hpp>
    #include <stdbool.h>

namespace Jam {
    class Menu {
            public:
                sf::Texture texture_background;
                sf::Texture texture_start;
                sf::Texture texture_gmplayer;
                sf::Texture texture_exit;
                sf::Texture texture_hoppy;
                sf::Sprite sprite_background;
                sf::Sprite sprite_start;
                sf::Sprite sprite_gmplay;
                sf::Sprite sprite_exit;
                sf::Sprite sprite_hoppy;
                sf::Music music_menu;
                bool isStartHovered = false;
                bool isGmplayHovered = false;
                bool isExitHovered = false;

            public:
                Menu();
                ~Menu() = default;
                void Scale_sprites();
                void SetPositionSprite();
                void PlayMusic_menu();
        };
}

#endif /* !MENU_HPP_ */
