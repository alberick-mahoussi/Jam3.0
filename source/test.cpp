/*
** EPITECH PROJECT, 2023
** Jam3.0
** File description:
** Arckanoid
*/

#include "../include/Arckanoid.hpp"

/*Arckanoid::Ball::Ball(float x, float y, float radius) {
    shape.setPosition(x, y);
    shape.setRadius(radius);
    // Initialisation de la vitesse et de la direction de la balle
    velocity = sf::Vector2f(0.f, 0.f);
}

void Arckanoid::Ball::move() {
    shape.move(velocity);
}

void Arckanoid::Ball::checkCollisionWithWalls(float windowWidth, float windowHeight) {
    sf::FloatRect bounds = shape.getGlobalBounds();

    // Vérification des collisions avec les bords de la fenêtre
    if (bounds.left <= 0.f || bounds.left + bounds.width >= windowWidth) {
        velocity.x = -velocity.x; // Inversion de la direction horizontale
    }

    if (bounds.top <= 0.f) {
        velocity.y = -velocity.y; // Inversion de la direction verticale
    }
}

void Arckanoid::Ball::checkCollisionWithPaddle(Arckanoid::Paddle& paddle) {
    if (shape.getGlobalBounds().intersects(paddle.getShape().getGlobalBounds())) {
        // Inversion de la direction verticale
        velocity.y = -velocity.y;
    }
}

void Arckanoid::Ball::checkCollisionWithBricks(std::vector<Brick>& bricks) {
    for (auto& brick : bricks) {
        if (brick.isCollidingWithBall(*this)) {
            // Gérer la collision avec la brique
            // Par exemple, détruire la brique, incrémenter le score, etc.
        }
    }
}

void Arckanoid::Ball::update() {
    move();
}

// Classe Paddle

Arckanoid::Paddle::Paddle(float x, float y, float width, float height) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    // Autres initialisations...
}

void Arckanoid::Paddle::moveLeft() {
    shape.move(-speed, 0.f);
}

void Arckanoid::Paddle::moveRight() {
    shape.move(speed, 0.f);
}

void Arckanoid::Paddle::checkCollisionWithWalls(float windowWidth) {
    sf::FloatRect bounds = shape.getGlobalBounds();

    // Vérification des collisions avec les bords de la fenêtre
    if (bounds.left <= 0.f) {
        shape.setPosition(0.f, bounds.top);
    }

    if (bounds.left + bounds.width >= windowWidth) {
        shape.setPosition(windowWidth - bounds.width, bounds.top);
    }
}

void Arckanoid::Paddle::update() {
    // Autres mises à jour...
}

// Classe Brick

Arckanoid::Brick::Brick(float x, float y, float width, float height, sf::Color color, int points) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(color);
    this->points = points;
}

bool Arckanoid::Brick::isCollidingWithBall(const Arckanoid::Ball &ball) 
{
    return shape.getGlobalBounds().intersects(ball.getShape().getGlobalBounds());    //return shape.getGlobalBounds().intersects(ball.getShape().getGlobalBounds());
}

void Arckanoid::Brick::update() {
    // Autres mises à jour...
}

// Classe Level

Arckanoid::Level::Level() {
    // Initialisation d'autres attributs...
}

void Arckanoid::Level::loadLevel(int levelNumber) {
    // Chargement du niveau spécifié par le numéro
    // Initialisation des briques selon le niveau
}

bool Arckanoid::Level::isLevelComplete() {
    return remainingBricks == 0;
}

void Arckanoid::Level::update() {
    // Autres mises à jour du niveau...
}*/
