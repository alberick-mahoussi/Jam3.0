/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** InputHoppy
*/

#include "../include/InputHoppy.hpp"

Jam::InputHoppy::InputHoppy()
{
    font.loadFromFile("text_style/arial.ttf");
    texture_hoppy.loadFromFile("img/hoppy.jpg");
    sprite_hoppy.setTexture(texture_hoppy);


}

void Jam::InputHoppy::SetScale()
{
    sprite_hoppy.scale(sf::Vector2f {0.5, 0.5});
}

void Jam::InputHoppy::SetPosition()
{
    welcomeText.setPosition(1920 / 2 - welcomeText.getGlobalBounds().width / 2, 1080 / 2 - 230);
    inputText.setPosition(1920 / 2 - inputText.getGlobalBounds().width / 2, 1080 / 2 - 100);
    inputTextValue.setPosition(1920 + 10, 1080 + 10);
    inputBox.setPosition(1920 / 2 - inputBox.getSize().x / 2, 1080 / 2 - 25);
    blackBox.setPosition(1920 / 2 - blackBox.getSize().x - 50, 1080 - blackBox.getSize().y - 50);
    blackText.setPosition(blackBox.getPosition().x + blackBox.getSize().x / 2 - blackText.getGlobalBounds().width / 2,
                          blackBox.getPosition().y + blackBox.getSize().y / 2 - blackText.getGlobalBounds().height / 2);
    whiteBox.setPosition(1920 / 2 + 50, 1080 - whiteBox.getSize().y - 50);
    whiteText.setPosition(whiteBox.getPosition().x + whiteBox.getSize().x / 2 - whiteText.getGlobalBounds().width / 2,
                          whiteBox.getPosition().y + whiteBox.getSize().y / 2 - whiteText.getGlobalBounds().height / 2);
    
}

void Jam::InputHoppy::SetTextParms()
{
    welcomeText.setString("Bienvenue");
    welcomeText.setFont(font);
    welcomeText.setCharacterSize(50);
    inputText.setString("Veuillez entrer votre surnom:");
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputTextValue.setString("");
    inputTextValue.setFont(font);
    inputTextValue.setCharacterSize(30);
    blackText.setString("Noir");
    blackText.setFont(font);
    blackText.setCharacterSize(30);
    whiteText.setString("Blanc");
    whiteText.setFont(font);
    whiteText.setCharacterSize(30);
}

void Jam::InputHoppy::SetFillColor()
{
    welcomeText.setFillColor(sf::Color::White);
    inputText.setFillColor(sf::Color::White);
    inputTextValue.setFillColor(sf::Color::Black);
    inputBox.setFillColor(sf::Color::White);
    blackBox.setFillColor(sf::Color::Black);
    blackText.setFillColor(sf::Color::White);
    whiteBox.setFillColor(sf::Color::Black);
    whiteText.setFillColor(sf::Color::Black);
}

void Jam::InputHoppy::SetBoxVector()
{
    inputBox.setSize(sf::Vector2f(300, 50));
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::Black);
    blackBox.setSize(sf::Vector2f(100, 50));
    whiteBox.setSize(sf::Vector2f(100, 50));

}