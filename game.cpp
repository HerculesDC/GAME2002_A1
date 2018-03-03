#include "game.hpp"

const float Game::mWindowWidth = 1280;
const float Game::mWindowHeight = 800;

Game::Game() : mWindow(sf::VideoMode(mWindowWidth, mWindowHeight), "GAME2002: Assignment 1 - Dias Campos, Hercules. ID 101091070"),
			   mBall(),
			   mBat()
{}

Game::~Game() {}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		}
	}
}

void Game::render() {
	mWindow.clear(sf::Color(25, 88, 109, 255));
	mWindow.draw(mBall.getShape());
	mWindow.draw(mBat.getShape());
	mWindow.display();
}

void Game::update() {
	if (mBall.getPosition().x > Game::mWindowWidth || mBall.getPosition().x < 0) mBall.reboundSides();
	if (mBall.getPosition().y > Game::mWindowHeight || mBall.getPosition().y < 0) mBall.reboundBatOrTop();

	mBall.update();
	mBat.update();
}

void Game::run() {
	while (mWindow.isOpen()) {
		processEvents();
		update();
		render();
	}
}

