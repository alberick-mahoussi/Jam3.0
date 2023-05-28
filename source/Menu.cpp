/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** Menu
*/

#include "../include/Menu.hpp"

Jam::Menu::Menu()
{
    texture_background.loadFromFile("img/background.jpg");
    texture_start.loadFromFile("img/start.png");
    texture_gmplayer.loadFromFile("img/gameplay.png");
    texture_exit.loadFromFile("img/exit.png");
    texture_hoppy.loadFromFile("img/hoppy.jpg");
    sprite_background.setTexture(texture_background);
    sprite_start.setTexture(texture_start);
    sprite_gmplay.setTexture(texture_gmplayer);
    sprite_exit.setTexture(texture_exit);
    music_menu.openFromFile("music/musicMenu.wav");
    music_button.openFromFile("music/button.wav");
}

void Jam::Menu::Scale_sprites()
{
    sprite_start.scale(sf::Vector2f {0.15, 0.15});
    sprite_gmplay.scale(sf::Vector2f {0.7, 0.7});
    sprite_exit.scale(sf::Vector2f {0.8, 0.8});
    sprite_hoppy.scale(sf::Vector2f {0.5, 0.5});
}

void Jam::Menu::SetPositionSprite()
{
    sprite_background.setPosition(0, 0);
    sprite_start.setPosition(790, 290);
    sprite_gmplay.setPosition(775, 500);
    sprite_exit.setPosition(790, 695);
}

void Jam::Menu::PlayMusic_menu()
{
    music_menu.setLoop(true);
    music_menu.play();
}

void Jam::Menu::PlayMusic_button()
{
    music_button.setLoop(false);
    music_button.play();
}