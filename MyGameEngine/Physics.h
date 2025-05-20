#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

enum class CollisionType {
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
	void moveObject(Entity& a);

	// Обновление состояния объектов
	//void update(float deltaTime);

	void handleCollision(Entity& a, Entity& b);

private:
	float gravity = 1.0f;

	// Проверка столкновения между двумя объектами
	CollisionType checkCollision(Entity& a, Entity& b) const;
};

#endif // !PHYSICS_H
