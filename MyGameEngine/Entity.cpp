#include "Entity.h"

void Entity::setSpeed(sf::Vector2f cur_speed) {
	speed = cur_speed;
}

sf::Vector2f Entity::getSpeed() {
	return speed;
}

void Entity::makeMoveable() {
	moveable = true;
}

void Entity::makeStatic() {
	moveable = false;
}

bool Entity::checkMoveable() {
	return moveable;
}

void Entity::setPosition(sf::Vector2f pos) {
	object.setPosition(pos.x, pos.y);
	position = pos;
}

void Entity::setObject(sf::RectangleShape obj) {
	object = obj;
}

void Entity::stopX() {
	setSpeed({ 0, speed.y });
}

void Entity::stopY() {
	setSpeed({ speed.x, 0 });
}

sf::Vector2f Entity::getPosition() {
	return position;
}

sf::RectangleShape* Entity::getObject() {
	return &object;
}

void Entity::update(float deltaTime) {

}