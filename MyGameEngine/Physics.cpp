#include "Physics.h"

void PhysicsManager::applyGravity(Entity& object, float deltaTime) {
	float speed_y = object.getSpeed().y;

	// Вычисление скорости с учетом гравитации
	speed_y += -gravity * deltaTime * deltaTime / 2;

	// Смещение координаты за кадр, проверка на коллизию
	object.getObject()->move(0, speed_y);


}

CollysionType PhysicsManager::checkCollision(Entity& a, Entity& b) const{
	if (!a.getObject()->getGlobalBounds().intersects(b.getObject()->getGlobalBounds()))
		return CollysionType::None;

}