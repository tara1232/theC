
#include <iostream>

Entity::Entity(int health_, int attack_, int speed_) {
	health = health_;
	attack = attack_;
	speed = speed_;
}

void Entity::displayState() {
	std::cout 
		<< "health: " << health << std::endl
		<< "attack: " << attack << std::endl
		<< "speed: " << speed << std::endl;
}

