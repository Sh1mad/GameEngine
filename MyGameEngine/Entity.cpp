#include "Entity.h"

void Entity::setSpeed(sf::Vector2f cur_speed) {
	speed = cur_speed;
}

sf::Vector2f Entity::getSpeed() {
	return speed;
}

void Entity::setPosition(sf::Vector2u pos) {
	object.setPosition(pos.x, pos.y);
	position = pos;
}

sf::Vector2u Entity::getPosition() {
	return position;
}

sf::RectangleShape* Entity::getObject() {
	return &object;
}