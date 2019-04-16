
/*
 * AUTHOR: Alek Westover
 * PROGRAM: main.cpp
 *
 * */

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	sf::RenderWindow window;
	window.create(sf::VideoMode(800,600), "theC");
	window.setFramerateLimit(60);
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}			
		}
		window.clear();
		window.display();
	}
	return 0;
}
