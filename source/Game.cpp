/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** Game
*/

#include "../include/jam.hpp"

Jam::Game::Game()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");
    font.loadFromFile("text_style/arial.ttf");
    backgroundColor = sf::Color::White;         
}
