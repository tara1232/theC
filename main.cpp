
/*
 * AUTHOR: Alek Westover
 * PROGRAM: main.cpp
 *
 * */

/*
 * Some thoughts: 
 * I think that the Entity class should be for holding general info about the entity
 * and then there should be more specific things
 * like I don't want something like
 * Entity unicorns[10];
 * I want something more like
 * Animal unicorns[10];
 * and then animal can use whatever Entity stuff it wants
 *
 * */


#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
#include "Entity.hpp"

int main() {

	srand(time(NULL));

	// constants
	sf::Vector2f screenDimensions(1024, 512);
	sf::Vector2f worldDimensions(2048, 2048);
	const int mapSize = 32;
	const int tileWidth = 64;
	const int MAX_FRAME_RATE = 60;
	const float moveSpeed = 200;
	const float switchFrame = 100, frameSpeed = 500;
	// probably they all have to be 64 by 64 ...
	const int chickenWidth = 64;
	const int unicornWidth = 128;

	// initialize window variables 
	sf::RenderWindow window;
	window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "theC");
	window.setFramerateLimit(MAX_FRAME_RATE);

	// views
	sf::View view(sf::Vector2f(0, 0), screenDimensions);
	view.setViewport(sf::FloatRect(0.0f,0.0f,1.0f,1.0f));
	sf::View minimap(sf::Vector2f(worldDimensions.x/2,worldDimensions.y/2), worldDimensions);
	minimap.setViewport(sf::FloatRect(0.75f, 0.0f, 0.25f, 0.25f));


	sf::Clock clock;
	float dt, frameCounter;

	bool paused = false;
	bool showMap = true;

	// read config data
	const std::map<char, int> mapData = {{'s', 0}, {'f', 1}, {'g', 2}, {'w', 3}};
	sf::Texture tileTextures;
	sf::Sprite tileSprite;
	tileTextures.loadFromFile("pictures/tiles.png");
	tileSprite.setTexture(tileTextures);
	std::ifstream mapFile("data/map.txt");
	int map[mapSize][mapSize];
	for (int i = 0; i < mapSize; i++){
		for (int j = 0; j < mapSize; j++){
			char curChar;
			mapFile >> curChar;
			map[i][j] = mapData.at(curChar);
		}
	}

	// initialize the game 
	
	// chicken
	Entity chicken(10, 10, 10);
	chicken.initImage("pictures/chicken.png", chickenWidth, sf::Vector2i(2,2));
	sf::Vector2f pos(screenDimensions.x/2, screenDimensions.y/2);
	sf::Vector2f cameraPos(screenDimensions.x/2, screenDimensions.y/2);

	sf::RectangleShape boundingBox(sf::Vector2f(chickenWidth, chickenWidth));
	boundingBox.setFillColor(sf::Color(0,255,0,75));

	sf::RectangleShape blipBox(sf::Vector2f(chickenWidth, chickenWidth));
	blipBox.setFillColor(sf::Color(255,0,0,255));


	// unicorn
	Entity unicorn(10, 10, 10);
	unicorn.initImage("pictures/unicorn.png", unicornWidth, sf::Vector2i(4,2));
	sf::Vector2f unicornPoses[4];
	unicornPoses[0] = sf::Vector2f(tileWidth*16,tileWidth*16);
	unicornPoses[1] = sf::Vector2f(tileWidth*5,tileWidth*7);
	unicornPoses[2] = sf::Vector2f(tileWidth*8,tileWidth*9);
	unicornPoses[3] = sf::Vector2f(tileWidth*23,tileWidth*19);
	sf::RectangleShape boundingBoxUni(sf::Vector2f(unicornWidth, unicornWidth));
	boundingBoxUni.setFillColor(sf::Color(0,255,0,75));



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
					else if(event.key.code == sf::Keyboard::I){
						if(screenDimensions.x *2 <= worldDimensions.x){
							screenDimensions.x *= 2;
							screenDimensions.y *= 2;
							view.setSize(screenDimensions);
						}
					}
					else if(event.key.code == sf::Keyboard::O){
						if(screenDimensions.x / 2 >= tileWidth){
							screenDimensions.x /= 2;
							screenDimensions.y /= 2;
							view.setSize(screenDimensions);
						}
					} 
					break;
				case sf::Event::KeyReleased:
					if(event.key.code == sf::Keyboard::M){
						showMap = !showMap;
					}
					break;
				case sf::Event::Resized:
					screenDimensions.x = event.size.width;
					screenDimensions.y = event.size.height;
					std::cout << screenDimensions.x << std::endl;
					view.setSize(screenDimensions);
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
			chicken.nextFrame();
			unicorn.nextFrame();
			frameCounter = 0;


			unicornPoses[rand()%4].x += ((rand()%3)-1)*tileWidth;
			unicornPoses[rand()%4].y += ((rand()%3)-1)*tileWidth;
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

		chicken.setAniState();
		unicorn.setAniState();
	
		cameraPos.x = pos.x + chickenWidth/2;
		if (cameraPos.x < screenDimensions.x/2)
			cameraPos.x = screenDimensions.x/2;
		if (cameraPos.x > worldDimensions.x -screenDimensions.x/2)
			cameraPos.x = worldDimensions.x -screenDimensions.x/2;
		cameraPos.y = pos.y + chickenWidth/2;
		if (cameraPos.y < screenDimensions.y/2)
			cameraPos.y = screenDimensions.y/2;
		if (cameraPos.y > worldDimensions.y - screenDimensions.y/2)
			cameraPos.y = worldDimensions.y - screenDimensions.y/2;
		view.setCenter(cameraPos);

		// clear, draw, display (in that order!)
		window.clear(sf::Color(49, 100, 183, 200)); // lightish blue

		window.setView(view);
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				tileSprite.setTextureRect(sf::IntRect(map[i][j]*tileWidth, 0, tileWidth, tileWidth));
				tileSprite.setPosition(j*tileWidth, i*tileWidth);
				window.draw(tileSprite);
			}
		}

		for(int i = 0; i < 4; i++){
			unicorn.sprite.setPosition(unicornPoses[i]);
			window.draw(unicorn.sprite);
			boundingBoxUni.setPosition(unicornPoses[i]);
			window.draw(boundingBoxUni); 
		}

		chicken.sprite.setPosition(pos);
		window.draw(chicken.sprite);
		boundingBox.setPosition(pos);
		window.draw(boundingBox);
		chicken.sprite.setPosition(0, 0);
		window.draw(chicken.sprite);

		if (showMap) {
			window.setView(minimap);
			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					tileSprite.setTextureRect(sf::IntRect(map[i][j]*tileWidth, 0, tileWidth, tileWidth));
					tileSprite.setPosition(j*tileWidth, i*tileWidth);
					window.draw(tileSprite);
				}
			}
			blipBox.setPosition(pos);
			window.draw(blipBox);
		}

		window.display();
	}
	return 0;
}

