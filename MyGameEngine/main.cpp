#include <SFML/Graphics.hpp>

int main() {
    // ������� ���� �������� 800x600 � ���������� "My Game Engine"
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My Game Engine");

    // ������� ������� (������)
    sf::RectangleShape player(sf::Vector2f{ 50, 50 }); // ������ 50x50
    player.setFillColor(sf::Color::Red); // ������� ����
    player.setPosition({ 400, 300 }); // ��������� ������� � ������

    // ������� ����: ��������, ���� ���� �������
    while (window.isOpen()) {
        // ��������� �������
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        // ���������� �������
        float moveSpeed = 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Left)) {
            player.move({ -moveSpeed, 0 }); // �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
            player.move({ moveSpeed, 0 }); // ������
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
            player.move({ 0, -moveSpeed }); // �����
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
            player.move({ 0, moveSpeed }); // ����
        }

        // ������� ���� ������ ������
        window.clear(sf::Color::Black);

        // ������ ������
        window.draw(player);

        // ���������� �� ������
        window.display();
    }

    return 0;
}