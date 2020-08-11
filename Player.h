#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	Vector2f m_Position;

	Sprite m_Sprite;

	Texture m_Texture;
	Vector2f m_Resolution;
	IntRect m_Arena;
	Time m_LastHit;

	int m_TileSize;

	int m_MaxHealth;
	int m_Health;
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	float m_Speed;

public:
	Player();

	// Player position 
	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	void resetPlayerStats();
	bool hit(Time timeHit);
	Time getLastHit();
	FloatRect getPosition();
	Vector2f getCenter();
	float getRotation();
	Sprite getSprite();

	// Player movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	void update(float elapsedTime, Vector2i mousePosition);

	// Player attribute upgrades
	void upgradeSpeed();
	void upgradeHealth();
	void increaseHealth(int amount);
	int getHealth();
};

