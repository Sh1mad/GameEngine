#include "Core.h"

void Core::init() {
	// Защита от двойной инициализации ядра
	if (isRunning) return;
	isRunning = true;

	// Создаем игровое окно
	windowManager.createWindow("My 2D Game", 800, 600, false);

	// Передаем адрес окна модулям управления
	renderer.setWindow(windowManager.getWindowPtr());
	inputManager.setWindow(windowManager.getWindowPtr());
}

void Core::stop() {
	isRunning = false;
	window->close();
}

void Core::run() {
	while (isRunning) {
		//float deltaTime = clock.restart().asSeconds(); // Время между кадрами

		processInput();
		//update(deltaTime);
		//render();
	}
}

void Core::processInput() {
	inputManager.pollEvents();
	if (inputManager.isKeyPressed(sf::Keyboard::Key::Escape)) {
		stop();
	}
}

void Core::update(float deltaTime) {
	entityManager.updateAll(deltaTime);
}

void Core::render() {
	for (auto& entity : entityManager.getEntities()) {
		window->draw(*(entity->getObject()));
	}
}