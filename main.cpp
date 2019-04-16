
/*
 * AUTHOR: Alek Westover
 * PROGRAM: main.cpp
 *
 * */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

int main() {

	// constants
	sf::Vector2f screenDimensions(800, 600);
	const int MAX_FRAME_RATE = 60;
	const float moveSpeed = 200;
	const float switchFrame = 100, frameSpeed = 500;

	// initialize window variables 
	sf::RenderWindow window;
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "theC");
	window.setFramerateLimit(MAX_FRAME_RATE);

	sf::View view(sf::Vector2f(0, 0), screenDimensions);
	sf::Clock clock;
	float dt, frameCounter;


	// initialize the game
	
	// chicken
	sf::Texture chickenTexture;
	sf::Sprite chicken;
	chickenTexture.loadFromFile("pictures/chicken.png");
	chicken.setTexture(chickenTexture);
	const int chickenWidth = 64;
	sf::Vector2f offset(chickenWidth/2, chickenWidth/2);
	// put all this in the Entity class!!!
	sf::Vector2f pos(screenDimensions.x/2, screenDimensions.y/2);

	sf::RectangleShape boundingBox(sf::Vector2f(chickenWidth, chickenWidth));
	boundingBox.setFillColor(sf::Color(0,255,0,75));

	while(window.isOpen()) { // game loop
		sf::Event event;
		while(window.pollEvent(event)) { // event loop
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Q)
						window.close();
					break;
				case sf::Event::Resized:
					screenDimensions.x = event.size.width;
					screenDimensions.y = event.size.height;
					break;
				case sf::Event::LostFocus:
					std::cout << "goodbye!!!" << std::endl;
					break;
				case sf::Event::GainedFocus:
					std::cout  << "welcome back!!" << std::endl;
					break;
				default:
					break;
			}			
		}

		dt = clock.restart().asSeconds();

		frameCounter += frameSpeed*dt;
		if(frameCounter >= switchFrame){
			frameCounter = 0;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			pos.x -= moveSpeed*dt;
		}	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			pos.x += moveSpeed*dt;
		}	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			pos.y -= moveSpeed*dt;
		}	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			pos.y += moveSpeed*dt;
		}	

		chicken.setTextureRect(sf::IntRect(chickenWidth, chickenWidth, chickenWidth, chickenWidth));

		view.setCenter(pos);

		// clear, draw, display (in that order!)
		window.clear(sf::Color(49, 100, 183,200));

		window.setView(view);
		chicken.setPosition(pos-offset);
		window.draw(chicken);
		boundingBox.setPosition(pos-offset);
		window.draw(boundingBox);
		chicken.setPosition(0, 0);
		window.draw(chicken);

		window.display();
	}
	return 0;
}

