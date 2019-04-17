#ifndef ENTITY
#define ENTITY
class Entity {
	public:
		sf::Texture texture;
		sf::Sprite sprite;
		int health, attack, width, speed;	
		sf::Vector2i aniFrame;
		sf::Vector2i aniFrameMax;

		Entity(int health_, int attack_, int speed_);
		void initImage(std::string imgPath, int width_, sf::Vector2i aniFrameMax_);
		void displayState();
		void setAniState();
		void nextFrame();
};
#endif
