#include <iostream>
#include <string>
#include <ctime>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "ball.hpp"
#include "bat.hpp"

class Game : sf::NonCopyable {
	public:
		Game();
		~Game();
		void processEvents();
		void update();
		void render();
		void run();


	private:
		//some are named a bit differently than the outline specifies, for consistency
		Ball mBall;
		Bat mBat;
		int mLives;
		int mScore; 
		sf::Font mFont;
		sf::Sprite mIcon;
		sf::Music mMusic;
		sf::Text mText;
		sf::RenderWindow mWindow;
		static const float mWindowHeight;
		static const float mWindowWidth;
};