
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Entity.hpp"

// want: load width, health, attach, speed from a config file, or something 
Entity::Entity(int health_, int attack_, int speed_) {
	health = health_;
	attack = attack_;
	speed = speed_;
}

void Entity::initImage(std::string imgPath, int width_, sf::Vector2i aniFrameMax_) {
	aniFrameMax = aniFrameMax_;
	aniFrame = sf::Vector2i(0,0);
	width = width_;
	texture.loadFromFile(imgPath);
	sprite.setTexture(texture);
}

void Entity::displayState() {
	std::cout 
		<< "width: " << width << std::endl
		<< "health: " << health << std::endl
		<< "attack: " << attack << std::endl
		<< "speed: " << speed << std::endl;
}

void Entity::setAniState() {
	sprite.setTextureRect(sf::IntRect(width*aniFrame.x, width*aniFrame.y, width, width));
}

void Entity::nextFrame() {
	aniFrame.x = (aniFrame.x + 1) % aniFrameMax.x;
}

