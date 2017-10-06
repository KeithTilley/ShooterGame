#pragma once

#include "animatedsprite.h"
#include "globals.h"
#include "player.h"
#include <string>

class Graphics;

class Enemy : public AnimatedSprite {
public:
	Enemy();
	Enemy(Graphics &graphics, std::string filePath, int sourceX, int sourceY, int width, int height, Vector2 spawnPoint, int timeToUpdate);
	virtual void update(int elapsedTime, Player &player);
	virtual void draw(Graphics &graphics);
	inline int getMaxHealth() const { return this->maxHealth; }
	inline int getHealth() const { return this->currentHealth; }
protected:
	float facing;
	int maxHealth;
	int currentHealth;
	void setFacing(float x, float y);
};

class TestEnemy : public Enemy {
public:
	TestEnemy();
	TestEnemy(Graphics &graphics, Vector2 spawnPoint);
	void update(int elapsedTime, Player &player);
	void draw(Graphics &graphics);
	void animationDone(std::string currentAnimation);
	void setupAnimation();
private:
};