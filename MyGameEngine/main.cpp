#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно размером 800x600 с заголовком "My Game Engine"
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Game Engine");

    // Создаем квадрат (игрока)
    sf::RectangleShape player(sf::Vector2f{ 50, 50 }); // Размер 50x50
    player.setFillColor(sf::Color::Red); // Красный цвет
    player.setPosition({ 400, 300 }); // Стартовая позиция в центре

    // Главный цикл: работает, пока окно открыто
    while (window.isOpen()) {
        // Обработка событий
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        // Управление игроком
        float moveSpeed = 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
            player.move({ -moveSpeed, 0 }); // Влево
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
            player.move({ moveSpeed, 0 }); // Вправо
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
            player.move({ 0, -moveSpeed }); // Вверх
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
            player.move({ 0, moveSpeed }); // Вниз
        }

        // Очищаем окно черным цветом
        window.clear(sf::Color::Black);

        // Рисуем игрока
        window.draw(player);

        // Отображаем на экране
        window.display();
    }

    return 0;
}