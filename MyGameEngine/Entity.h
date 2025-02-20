#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	// Конструктор
	Entity(sf::RectangleShape& obj, unsigned x, unsigned y, float speed_x = 0, float speed_y = 0) :object(obj), speed({ speed_x, speed_y }), position({ x,y }) {};
	
	// Сеттер скорости
	void setSpeed(sf::Vector2f speed);

	// Сеттер позиции
	void setPosition(sf::Vector2u pos);

	// Геттер объекта
	sf::RectangleShape* getObject();

	// Геттер скорости
	sf::Vector2f getSpeed();

	// Геттер позиции
	sf::Vector2u getPosition();
private:
	sf::RectangleShape object;
	sf::Vector2f speed;
	sf::Vector2u position;
};

#endif // !ENTITY_H
