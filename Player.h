#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	Vector2f position;

	Sprite sprite;

	Texture texture;
	Vector2f resolution;
	IntRect arena;
	Time lastHit;

	int tileSize;
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;

	float speed;

};

