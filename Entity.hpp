#ifndef ENTITY
#define ENTITY
class Entity {
	public:
		sf::Texture texture;
		sf::Sprite sprite;
		int health, attack, width, speed;	

		Entity(int, int, int, int);
		void displayState();
};
#endif
