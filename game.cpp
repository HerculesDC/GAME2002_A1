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
	mText.setPosition(10.0f, 10.0f);
	//for some reason, setFillColor doesn't work...
	//mText.setFillColor(sf::Color(0.0f, 0.0f, 0.0f, 1.0f));
	mText.setOutlineColor(sf::Color(1.0f, 1.0f, 1.0f, 1.0f));
	mText.setCharacterSize(25);
	
	//music loading and play:
	if (!mMusic.openFromFile("Media/Music/Deeper.ogg")) return;
	mMusic.play();
}

Game::~Game() {}

void Game::processEvents(sf::Time elapsedTime) {

	sf::Event event;
	
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed: {
				//put time here just because... (lazy design choice, I know, but it was quicker...)
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left 
					&& mBat.getPosition().x > 0)
						mBat.moveLeft(elapsedTime.asSeconds());
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right 
					&& mBat.getPosition().x < Game::mWindowWidth-mBat.getShape().getSize().x)
						mBat.moveRight(elapsedTime.asSeconds());
			}
		}
	}
}

void Game::render() {
	
	mWindow.clear(sf::Color(25, 88, 109, 255));
	
	mWindow.draw(mBat.getShape()); 
	mWindow.draw(mBall.getShape());
	mWindow.draw(mText);
	
	mWindow.display();
}

void Game::updateText() {
	std::stringstream data;
	data << "Lives: " << mLives << "\n" << "Score: " << mScore;
	mText.setString(data.str());
}

void Game::update(sf::Time elapsedTime) {
	if (mLives > 0) {

		if (mBall.getPosition().x > (Game::mWindowWidth-(2*mBall.getShape().getRadius())) || mBall.getPosition().x < 0) mBall.reboundSides();
		if (mBall.getPosition().y < 0) mBall.reboundBatOrTop();
		if (mBall.getPosition().y >= (mBat.getPosition().y - (2*mBall.getShape().getRadius())) &&
			mBall.getPosition().x > mBat.getPosition().x &&
			mBall.getPosition().x < (mBat.getPosition().x + mBat.getShape().getSize().x)) {
				++mScore;
				mBall.reboundBatOrTop();
		}
		if (mBall.getPosition().y > Game::mWindowHeight) {
			mLives -= 1;
			mBall.hitBottom();
		}

		mBall.update(elapsedTime.asSeconds());
		mBat.update();
		updateText();
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
			
			processEvents(TimePerFrame);
			update(TimePerFrame);
		}

		render();
	}
}