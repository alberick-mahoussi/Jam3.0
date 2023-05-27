/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** InputHoppy
*/

#ifndef INPUTHOPPY_HPP_
    #define INPUTHOPPY_HPP_
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
    class InputHoppy {
       public:
        sf::Font font;
        sf::Texture texture_hoppy;
        sf::Sprite sprite_hoppy;
        sf::Text welcomeText;
        sf::Text inputText;
        sf::RectangleShape inputBox;
        sf::Text inputTextValue;
        sf::RectangleShape blackBox;
        sf::Text blackText;
        sf::RectangleShape whiteBox;
        sf::Text whiteText;
        bool isBlackSelected = false;
        bool isWhiteSelected = false;
        std::string surnom;
       public:
        InputHoppy();
        ~InputHoppy() = default;
        void SetPosition();
        void SetScale();
        void SetTextParms();
        void SetFillColor();
        void SetBoxVector();
    };
};
#endif /* !INPUTHOPPY_HPP_ */
