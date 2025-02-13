#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно размером 800x600 с заголовком "My Game Engine"
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");

    // Создаем квадрат (игрока)
    sf::RectangleShape player(sf::Vector2f(50, 50)); // Размер 50x50
    player.setFillColor(sf::Color::Red); // Красный цвет
    player.setPosition(400, 300); // Стартовая позиция в центре

    // Главный цикл: работает, пока окно открыто
    while (window.isOpen()) {
        // Обработка событий (закрытие окна, нажатие клавиш и т.д.)
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
                window.close();
        }

        // Управление игроком
        float moveSpeed = 1.0f;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
            player.move(-moveSpeed, 0); // Влево
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
            player.move(moveSpeed, 0); // Вправо
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
            player.move(0, -moveSpeed); // Вверх
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
            player.move(0, moveSpeed); // Вниз
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