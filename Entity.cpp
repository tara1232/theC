
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

Entity::Entity(int width_, int health_, int attack_, int speed_) {
	width = width_;
	health = health_;
	attack = attack_;
	speed = speed_;
}

void Entity::displayState() {
	std::cout 
		<< "width: " << width << std::endl
		<< "health: " << health << std::endl
		<< "attack: " << attack << std::endl
		<< "speed: " << speed << std::endl;
}

