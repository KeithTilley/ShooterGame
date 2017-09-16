#pragma once

#include "player.h"
#include "level.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(int elapsedTime);

	Player player;
	Level level;
};
