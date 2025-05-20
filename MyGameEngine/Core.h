#pragma once
#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "InputManager.h"
#include "Physics.h"
#include "Renderer.h"
#include "WindowManager.h"
#include "EntityManager.h"

class Core {
public:
	Core() = default;

	// Инициализация игры
	void init();

	// Запуск главного цикла
	void run();

	// Выход из игры
	void stop();

	// Добавление игрока

	// Добавление текстур

private:

	// Методы игрового цикла
	void processInput();
	void update(float deltaTime);
	void render();

	// Флаг работы игры
	bool isRunning = false;

	// Модули
	WindowManager windowManager;
	Renderer renderer;
	InputManager inputManager;
	PhysicsManager physicsManager;
	EntityManager entityManager;

	// Указатель на окно игры
	sf::RenderWindow* window;

	//Другие переменные
	sf::Clock clock; // Таймер для измерения времени между кадрами
};

#endif // !CORE_H
