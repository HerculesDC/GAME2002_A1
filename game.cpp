#include <iostream>
#include <string>
#include <sstream>

#include "game.hpp"

const float Game::mWindowWidth = 1280;
const float Game::mWindowHeight = 800;

Game::Game() : mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), "GAME2002: Assignment 1 - Dias Campos, Hercules. ID 101091070"),
			   mBall(),
			   mBat()
{
	mLives = 5;
	mScore = 0;
}

Game::~Game() {}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
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
	while (mWindow.isOpen()) {
		processEvents();
		update();
		render();
	}
}

