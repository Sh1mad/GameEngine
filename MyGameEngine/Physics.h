#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

enum class CollysionType {
	None,       // Нет столкновения
	Top,        // Столкновение сверху
	Bottom,     // Столкновение снизу
	Left,       // Столкновение слева
	Right       // Столкновение справа
};

class PhysicsManager {
public:
	// Конструктор
	PhysicsManager() = default;

	// Применение гравитации к объекту
	void applyGravity(Entity& object, float deltaTime);

	// Перемещение объекта
	void moveObject(sf::RectangleShape& object, float dx, float dy);

	// Обновление состояния объектов
	void update(float deltaTime);

private:
	float gravity = 9.8f;

protected:
	// Проверка столкновения между двумя объектами
	CollysionType checkCollision(Entity& a, Entity& b) const;
};

#endif // !PHYSICS_H
