#include <SFML/Graphics.hpp>

int main() {
    // ������� ���� �������� 800x600 � ���������� "My Game Engine"
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");

    // ������� ������� (������)
    sf::RectangleShape player(sf::Vector2f(50, 50)); // ������ 50x50
    player.setFillColor(sf::Color::Red); // ������� ����
    player.setPosition(400, 300); // ��������� ������� � ������

    // ������� ����: ��������, ���� ���� �������
    while (window.isOpen()) {
        // ��������� ������� (�������� ����, ������� ������ � �.�.)
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
                window.close();
        }

        // ���������� �������
        float moveSpeed = 1.0f;
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
            player.move(-moveSpeed, 0); // �����
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
            player.move(moveSpeed, 0); // ������
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
            player.move(0, -moveSpeed); // �����
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
            player.move(0, moveSpeed); // ����
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