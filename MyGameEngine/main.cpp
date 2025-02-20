#include "WindowManager.h"
#include "Renderer.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);

    WindowManager windowManager;
    // Создание окна
    windowManager.createWindow("My 2D Game", 800, 600);

    // Создание рендера
    Renderer renderer;
    renderer.setWindow(windowManager.getWindowPtr());

    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Red);
    player.setPosition(400, 300);

    // Главный цикл игры
    while (windowManager.isWindowOpen()) {
        sf::Event event;
        while (windowManager.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                windowManager.closeWindow();
            }
        }

        // Очистка экрана
        renderer.clear(sf::Color::Blue);

        // Отрисовка спрайта и текста
        renderer.drawRectangle(player);

        // Отображение кадра
        renderer.display();
    }

    return 0;
}