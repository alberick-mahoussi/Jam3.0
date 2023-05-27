/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** main
*/

#include "../include/jam.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu");
    
    sf::Font font;
    font.loadFromFile("text_style/arial.ttf");

    sf::Texture texture_background;
    sf::Texture texture_start;
    sf::Texture texture_gmplayer;
    sf::Texture texture_exit;
    sf::Texture texture_hoppy;
    texture_background.loadFromFile("img/background.jpg");
    texture_start.loadFromFile("img/start.png");
    texture_gmplayer.loadFromFile("img/gameplay.png");
    texture_exit.loadFromFile("img/exit.png");
    texture_hoppy.loadFromFile("img/hoppy.jpg");

    sf::Sprite sprite_background(texture_background);
    sf::Sprite sprite_start(texture_start);
    sf::Sprite sprite_gmplay(texture_gmplayer);
    sf::Sprite sprite_exit(texture_exit);
    sf::Sprite sprite_hoppy(texture_hoppy);

    sprite_start.scale(sf::Vector2f {0.15, 0.15});
    sprite_gmplay.scale(sf::Vector2f {0.7, 0.7});
    sprite_exit.scale(sf::Vector2f {0.8, 0.8});
    sprite_hoppy.scale(sf::Vector2f {0.5, 0.5});

    sf::Music music_menu;
    music_menu.openFromFile("music/musicMenu.wav");
    music_menu.setLoop(true);
    music_menu.play();

    sprite_background.setPosition(0, 0);
    sprite_start.setPosition(790, 290);
    sprite_gmplay.setPosition(775, 500);
    sprite_exit.setPosition(790, 695);
    sprite_hoppy.setPosition(0, 0);

    bool isStartHovered = false;
    bool isGmplayHovered = false;
    bool isExitHovered = false;

    sf::Text welcomeText("Bienvenue", font, 50);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setPosition(window.getSize().x / 2 - welcomeText.getGlobalBounds().width / 2, window.getSize().y / 2 - 230);

    sf::Text inputText("Veuillez entrer votre surnom:", font, 30);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(window.getSize().x / 2 - inputText.getGlobalBounds().width / 2, window.getSize().y / 2 - 100);

    sf::RectangleShape inputBox(sf::Vector2f(300, 50));
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setPosition(window.getSize().x / 2 - inputBox.getSize().x / 2, window.getSize().y / 2 - 25);

    sf::Text inputTextValue("", font, 30);
    inputTextValue.setFillColor(sf::Color::Black);
    inputTextValue.setPosition(inputBox.getPosition().x + 10, inputBox.getPosition().y + 10);

    std::string surnom;
    bool start_pressed = false;

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
            } else if (event.type == sf::Event::MouseMoved) {
                // Récupère les coordonnées de la souris
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                // Vérifie si la souris est sur le bouton Start
                if (sprite_start.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    isStartHovered = true;
                    sprite_start.setScale(sf::Vector2f(0.2, 0.2)); // Agrandit l'image
                } else {
                    isStartHovered = false;
                    sprite_start.setScale(sf::Vector2f(0.15, 0.15)); // Rétablit la taille d'origine
                }

                // Vérifie si la souris est sur le bouton Gmplay
                if (sprite_gmplay.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    isGmplayHovered = true;
                    sprite_gmplay.setScale(sf::Vector2f(0.8, 0.8)); // Agrandit l'image
                } else {
                    isGmplayHovered = false;
                    sprite_gmplay.setScale(sf::Vector2f(0.7, 0.7)); // Rétablit la taille d'origine
                }

                // Vérifie si la souris est sur le bouton Exit
                if (sprite_exit.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    isExitHovered = true;
                    sprite_exit.setScale(sf::Vector2f(0.9, 0.9)); // Agrandit l'image
                } else {
                    isExitHovered = false;
                    sprite_exit.setScale(sf::Vector2f(0.8, 0.8)); // Rétablit la taille d'origine
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Récupère les coordonnées du clic de souris
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Vérifie si le bouton Start est survolé et cliqué
                    if (isStartHovered && sprite_start.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        start_pressed = true;
                        std::cout << "Chargement du jeu Bububle Yang..." << std::endl;
                         music_menu.stop();
                        //window.close(); // Quitte le menu après avoir chargé le jeu
                    } else if (isGmplayHovered && sprite_gmplay.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        std::cout << "Affichage des informations sur le gameplay..." << std::endl;
                        // Ici, vous pouvez afficher des informations sur le gameplay
                    } else if (isExitHovered && sprite_exit.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        window.close();
                    }
            }
        }
    }
        window.clear();
        window.draw(sprite_background);
        window.draw(sprite_start);
        window.draw(sprite_gmplay);
        window.draw(sprite_exit);
        if (start_pressed) {
            window.clear();
            window.draw(sprite_hoppy);
            window.draw(welcomeText);
            window.draw(inputText);
            window.draw(inputBox);
            window.draw(inputTextValue);
        }
        window.display();
    }
    return 0;
}
