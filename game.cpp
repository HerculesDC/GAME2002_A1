#include <iostream>
#include <string>
#include <sstream>

#include "game.hpp"

const float Game::mWindowWidth = 1280;
const float Game::mWindowHeight = 800;
const sf::Time Game::TimePerFrame = sf::seconds(1.0f / 60.0f);

Game::Game() : mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), "GAME2002: Assignment 1 - Dias Campos, Hercules (HErC). ID 101091070"),
			   mBall(),
			   mBat(),
			   mFont(),
			   mText(),
			   mMusic()
{
	//int settings
	mLives = 5;
	mScore = 0;

	//font and texts loading and assignment
	if (!mFont.loadFromFile("Media/Fonts/GIGI.ttf")) return;
	mText.setFont(mFont);
	mText.setCharacterSize(15);
	mText.setPosition(10.0f, 10.0f);
	
	//music loading and play:
	if (!mMusic.openFromFile("Media/Music/BoxCat_Games_-_11_-_Assignment.mp3")) return;
	mMusic.play();
}

Game::~Game() {}

void Game::processEvents() {

	sf::Event event;
	
	while (mWindow.pollEvent(event)) {
		//REDESIGN TO INCORPORATE TIME:
		switch (event.type) {
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::A && mBat.getPosition().x > 0) mBat.moveLeft();
				if (event.key.code == sf::Keyboard::D && mBat.getPosition().x < (Game::mWindowWidth-mBat.getShape().getSize().x)) mBat.moveRight();
			}
		}
	}
}

void Game::render() {
	
	mWindow.clear(sf::Color(25, 88, 109, 255));
	
	mWindow.draw(mBat.getShape()); 
	mWindow.draw(mBall.getShape());
	
	mWindow.display();
}

void Game::update() {
	if (mLives > 0) {

		if (mBall.getPosition().x > Game::mWindowWidth || mBall.getPosition().x < 0) mBall.reboundSides();
		if (mBall.getPosition().y < 0) mBall.reboundBatOrTop();
		if (mBall.getPosition().y > Game::mWindowHeight) {
			mLives -= 1;
			mBall.hitBottom();
		}

		mBall.update();
		mBat.update();
	}
}

void Game::run() {
	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	while (mWindow.isOpen()) {
		
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			
			processEvents();
			update();
		}

		render();
	}
}

