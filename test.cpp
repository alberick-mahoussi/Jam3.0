/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** test
*/

#include "../include/jam.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bienvenue");
    sf::Font font;
    if (!font.loadFromFile("text_style/arial.ttf")) {
        std::cout << "Erreur lors du chargement de la police" << std::endl;
        return -1;
    }

    sf::Text welcomeText("Bienvenue", font, 50);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setPosition(window.getSize().x / 2 - welcomeText.getGlobalBounds().width / 2, window.getSize().y / 2 - 100);

    sf::Text inputText("Veuillez entrer votre surnom:", font, 30);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(window.getSize().x / 2 - inputText.getGlobalBounds().width / 2, window.getSize().y / 2 + 50);

    sf::RectangleShape inputBox(sf::Vector2f(300, 40));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setPosition(window.getSize().x / 2 - inputBox.getSize().x / 2, window.getSize().y / 2 + 100);

    sf::Text inputTextValue("", font, 30);
    inputTextValue.setFillColor(sf::Color::Black);
    inputTextValue.setPosition(inputBox.getPosition().x + 10, inputBox.getPosition().y + 10);

    sf::RectangleShape blackBox(sf::Vector2f(100, 50));
    blackBox.setFillColor(sf::Color::Black);
    blackBox.setPosition(window.getSize().x / 2 - blackBox.getSize().x - 50, window.getSize().y - blackBox.getSize().y - 50);

    sf::Text blackText("Noir", font, 20);
    blackText.setFillColor(sf::Color::White);
    blackText.setPosition(blackBox.getPosition().x + blackBox.getSize().x / 2 - blackText.getGlobalBounds().width / 2,
                          blackBox.getPosition().y + blackBox.getSize().y / 2 - blackText.getGlobalBounds().height / 2);

    sf::RectangleShape whiteBox(sf::Vector2f(100, 50));
    whiteBox.setFillColor(sf::Color::White);
    whiteBox.setPosition(window.getSize().x / 2 + 50, window.getSize().y - whiteBox.getSize().y - 50);

    sf::Text whiteText("Blanc", font, 20);
    whiteText.setFillColor(sf::Color::Black);
    whiteText.setPosition(whiteBox.getPosition().x + whiteBox.getSize().x / 2 - whiteText.getGlobalBounds().width / 2,
                          whiteBox.getPosition().y + whiteBox.getSize().y / 2 - whiteText.getGlobalBounds().height / 2);

    std::string surnom;
    bool isBlackSelected = false;
    bool isWhiteSelected = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode != 13) { // 13 correspond à la touche Entrée
                    surnom += static_cast<char>(event.text.unicode);
                    inputTextValue.setString(surnom);
                }
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    std::cout << "Surnom : " << surnom << std::endl;
                    // Ici, vous pouvez faire ce que vous voulez avec le surnom
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (blackBox.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        isBlackSelected = true;
                        isWhiteSelected = false;
                    } else if (whiteBox.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        isBlackSelected = false;
                        isWhiteSelected = true;
                    }
                }
            }
        }

        window.clear();

        if (isBlackSelected) {
            window.clear(sf::Color::Black);
        } else if (isWhiteSelected) {
            window.clear(sf::Color::White);
        }

        window.draw(welcomeText);
        window.draw(inputText);
        window.draw(inputBox);
        window.draw(inputTextValue);
        window.draw(blackBox);
        window.draw(blackText);
        window.draw(whiteBox);
        window.draw(whiteText);
        window.display();
    }

    return 0;
}
