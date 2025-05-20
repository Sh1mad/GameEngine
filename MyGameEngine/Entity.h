#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	// Конструктор
	//Entity(sf::RectangleShape& obj, unsigned x = 0, unsigned y = 0, float speed_x = 0, float speed_y = 0) :object(obj), speed({ speed_x, speed_y }), position({ x,y }) {};
	
	// Инициализация объекта
	void setObject(sf::RectangleShape obj);

	// Сеттер скорости
	void setSpeed(sf::Vector2f speed);

	// Сеттер позиции
	void setPosition(sf::Vector2f pos);

	// Функции контроля движения объекта
	void makeMoveable();

	void makeStatic();

	bool checkMoveable();

	// Функции для остановки скорости движения по осям x и y
	void stopX();

	void stopY();

	// Обновление состояния объекта
	void update(float deltaTime);

	// Геттер объекта
	sf::RectangleShape* getObject();

	// Геттер скорости
	sf::Vector2f getSpeed();

	// Геттер позиции
	sf::Vector2f getPosition();
private:
	sf::RectangleShape object;
	sf::Vector2f speed;
	sf::Vector2f position;
	bool moveable = false;
};

#endif // !ENTITY_H
