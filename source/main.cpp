/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** main
*/

#include "../include/jam.hpp"

int archanoid(std::string name);

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
    sf::Color backgroundColor = sf::Color::White; // Couleur de fond initiale (blanc)

    sprite_start.scale(sf::Vector2f {0.15, 0.15});
    sprite_gmplay.scale(sf::Vector2f {0.7, 0.7});
    sprite_exit.scale(sf::Vector2f {0.8, 0.8});
    sprite_hoppy.scale(sf::Vector2f {0.5, 0.5});

    sf::Music music_menu;
    music_menu.openFromFile("music/musicMenu.wav");
    music_menu.setLoop(true);
    music_menu.play();


    sf::Music music_button;
    music_button.openFromFile("music/over_bu.wav");

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

    bool start_pressed = false;
    bool gib_name = false;
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
                    gib_name = true;
                    archanoid(surnom);
                    window.close();
                }
            } else if (event.type == sf::Event::MouseMoved) {
                // Récupère les coordonnées de la souris
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                // Vérifie si la souris est sur le bouton Start
                if (sprite_start.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    if(isStartHovered == false) {
                        music_button.setLoop(false);
                        music_button.play();
                    }
                    isStartHovered = true;
                    sprite_start.setScale(sf::Vector2f(0.2, 0.2)); // Agrandit l'image
                } else {
                    isStartHovered = false;
                    sprite_start.setScale(sf::Vector2f(0.15, 0.15)); // Rétablit la taille d'origine
                }

                // Vérifie si la souris est sur le bouton Gmplay
                if (sprite_gmplay.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    if(isGmplayHovered == false) {
                        music_button.setLoop(false);
                        music_button.play();
                    }
                    isGmplayHovered = true;
                    sprite_gmplay.setScale(sf::Vector2f(0.8, 0.8)); // Agrandit l'image

                } else {
                    isGmplayHovered = false;
                    sprite_gmplay.setScale(sf::Vector2f(0.7, 0.7)); // Rétablit la taille d'origine
                }

                // Vérifie si la souris est sur le bouton Exit
                if (sprite_exit.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    if(isExitHovered == false) {
                        music_button.setLoop(false);
                        music_button.play();
                    }
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
        } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::N) { // Touche N pour noir
                    backgroundColor = sf::Color::Black;
                } else if (event.key.code == sf::Keyboard::L) { // Touche L pour blanc
                    backgroundColor = sf::Color::White;
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
            window.draw(blackBox);
            window.draw(blackText);
            window.draw(whiteBox);
            window.draw(whiteText);
        }
        /*if (isBlackSelected && gib_name != NULL) {
            window.clear(sf::Color::Black);
        } else if (isWhiteSelected && gib_name != NULL) {
            window.clear(sf::Color::White);
        }*/
        window.display();
    }
    return 0;
}
