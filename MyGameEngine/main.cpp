#include <iostream>
#include "WindowManager.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Physics.h"
#include "Entity.h"
#include "EntityManager.h"

int main() {
    // Инициализация модулей движка
    WindowManager windowManager;
    Renderer renderer;
    InputManager inputManager;
    PhysicsManager physics;
    EntityManager entityManager;

    try {
        // Создание окна
        windowManager.createWindow("Simple Game", 800, 600);
        renderer.setWindow(windowManager.getWindowPtr());
        inputManager.setWindow(windowManager.getWindowPtr());

        // Создание игрока
        sf::RectangleShape playerRect(sf::Vector2f(50.0f, 50.0f));
        playerRect.setFillColor(sf::Color::Green);

        auto player = std::make_shared<Entity>();
        player->setObject(playerRect);
        player->setPosition({ 100, 100 });
        player->setSpeed({ 0, 0 });
        player->makeMoveable();
        player->getObject()->setPosition(player->getPosition().x, player->getPosition().y);
        entityManager.addEntity(player);

        // Создание платформы
        sf::RectangleShape platformRect(sf::Vector2f(800.0f, 20.0f));
        platformRect.setFillColor(sf::Color::Blue);

        auto platform = std::make_shared<Entity>();
        platform->setObject(platformRect);
        platform->setPosition({ 0, 500 });
        platform->getObject()->setPosition(platform->getPosition().x, platform->getPosition().y);
        entityManager.addEntity(platform);

        sf::Clock clock;

        // Главный игровой цикл
        while (windowManager.isWindowOpen()) {
            sf::Event event;
            while (windowManager.getWindow().pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    windowManager.closeWindow();

                inputManager.pollEvents(event); // Обработка событий
            }

            // Логика управления
            float deltaTime = clock.restart().asSeconds();

            auto entities = entityManager.getEntities();

            // Управление игроком
            for (auto& entity : entities) {
                if (entity->checkMoveable()) {
                    sf::Vector2f speed = entity->getSpeed();

                    if (inputManager.isKeyPressed(sf::Keyboard::A))
                        speed.x = -100*deltaTime;
                    else if (inputManager.isKeyPressed(sf::Keyboard::D))
                        speed.x = 100 * deltaTime;
                    else
                        speed.x = 0;

                    if (inputManager.isKeyPressed(sf::Keyboard::Space))
                        speed.y = 1; // Прыжок

                    entity->setSpeed(speed);
                }
            }

            // Применение физики
            physics.applyGravity(*player, deltaTime);

            // Обработка столкновений с другими объектами
            for (auto& other : entities) {
                if (other != player) {
                    physics.handleCollision(*player, *other);
                }
            }

            physics.moveObject(*player);

            // Отрисовка
            renderer.clear();
            for (auto& entity : entities) {
                renderer.drawRectangle(*entity->getObject());
            }
            renderer.display();
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}