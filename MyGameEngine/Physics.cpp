#include "Physics.h"

void PhysicsManager::applyGravity(Entity& object, float deltaTime) {
	float speed_y = object.getSpeed().y;

	// Вычисление скорости с учетом гравитации
	speed_y += gravity * deltaTime;

	object.setSpeed({ object.getSpeed().x, speed_y });
}

void PhysicsManager::moveObject(Entity& a) {
	a.getObject()->move(a.getSpeed());
}

//CollysionType PhysicsManager::checkCollision(Entity& a, Entity& b) const{
//	sf::RectangleShape* firstTexture = a.getObject(), *secondTexture = b.getObject();
//	if (!firstTexture->getGlobalBounds().intersects(secondTexture->getGlobalBounds()))
//		return CollysionType::None;
//	if (((a.getPosition().y + firstTexture->getSize().y) <= b.getPosition().y) &&
//		((firstTexture->getPosition().y + firstTexture->getSize().y) > secondTexture->getPosition().y))
//		return CollysionType::Top;
//	if (((a.getPosition().x + firstTexture->getSize().x) <= b.getPosition().x) &&
//		((firstTexture->getPosition().x + firstTexture->getSize().x) > secondTexture->getPosition().x))
//		return CollysionType::Left;
//	if ((a.getPosition().x >= (b.getPosition().x + secondTexture->getSize().x)) &&
//		(firstTexture->getPosition().x < (secondTexture->getPosition().x + secondTexture->getSize().x)))
//		return CollysionType::Right;
//	if ((a.getPosition().y >= (b.getPosition().y + secondTexture->getSize().y)) &&
//		(firstTexture->getPosition().y < (secondTexture->getPosition().y + secondTexture->getSize().y)))
//		return CollysionType::Bottom;
//}

CollisionType PhysicsManager::checkCollision(Entity& a, Entity& b) const {
    sf::FloatRect aBounds = a.getObject()->getGlobalBounds();
    sf::FloatRect bBounds = b.getObject()->getGlobalBounds();

    if (!aBounds.intersects(bBounds)) {
        return CollisionType::None;
    }

    float dx = (aBounds.left + aBounds.width / 2) - (bBounds.left + bBounds.width / 2);
    float dy = (aBounds.top + aBounds.height / 2) - (bBounds.top + bBounds.height / 2);

    float width = (aBounds.width + bBounds.width) / 2;
    float height = (aBounds.height + bBounds.height) / 2;

    float crossWidth = width * dy;
    float crossHeight = height * dx;

    if (std::abs(dx) > std::abs(dy)) {
        if (dx > 0) {
            return CollisionType::Right;
        }
        else {
            return CollisionType::Left;
        }
    }
    else {
        if (dy > 0) {
            return CollisionType::Bottom;
        }
        else {
            return CollisionType::Top;
        }
    }
}

void PhysicsManager::handleCollision(Entity& a, Entity& b) {
	CollisionType type = checkCollision(a, b);
	if (type == CollisionType::None) {
		a.setPosition(a.getObject()->getPosition());
		return;
	}

	if (type == CollisionType::Top) {
		a.getObject()->setPosition(a.getObject()->getPosition().x, b.getPosition().y - b.getObject()->getSize().y);
		a.setPosition({ a.getObject()->getPosition().x, b.getPosition().y - b.getObject()->getSize().y });
		a.stopY();
		return;
	}

	if (type == CollisionType::Left) {
		a.getObject()->setPosition(b.getPosition().x - a.getObject()->getSize().x, a.getObject()->getPosition().y);
		a.setPosition({ b.getPosition().x - a.getObject()->getSize().x, a.getObject()->getPosition().y });
		a.stopX();
		return;
	}

	if (type == CollisionType::Right) {
		a.getObject()->setPosition(b.getPosition().x + b.getObject()->getSize().x, a.getObject()->getPosition().y);
		a.setPosition({ b.getPosition().x + b.getObject()->getSize().x, a.getObject()->getPosition().y });
		a.stopX();
		return;
	}

	if (type == CollisionType::Bottom) {
		a.getObject()->setPosition(a.getObject()->getPosition().x, b.getPosition().y + b.getObject()->getSize().y);
		a.setPosition({ a.getObject()->getPosition().x, b.getPosition().y + b.getObject()->getSize().y });
		a.stopY();
		return;
	}
}