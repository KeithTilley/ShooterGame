#include "hud.h"
#include "graphics.h"

HUD::HUD() {}

HUD::HUD(Graphics &graphics, Player player) {
	this->player = player;
	this->healthBarSprite = Sprite(graphics, "sprites/hud.png", 0, 0, 128, 8, 8, 8);
	this->currentHealthSprite = Sprite(graphics, "sprites/hud.png", 0, 8, 126, 6, 10, 10);
	for (int i = 0; i < 3; i++) {
		this->livesSprites.push_back(Sprite(graphics, "sprites/hud.png", 0, 16, 10, 10, 270 + (i * 20), 6));
	}

}

void HUD::update(int elapsedTime) {
	// Width of health bar; 100% == 126px, max health == 100.
	float healthPercent = (float)this->player.getHealth() / 100;
	this->currentHealthSprite.setSourceRectW(std::floor(healthPercent * 126));
	for (int i = 0; i < 3; i++) {
		if (this->player.getLives() <= i) {
			this->livesSprites.at(i).setSourceRectX(10);
		}
	}
}

void HUD::draw(Graphics &graphics) {
	this->healthBarSprite.draw(graphics, this->healthBarSprite.getX(), this->healthBarSprite.getY());
	this->currentHealthSprite.draw(graphics, this->currentHealthSprite.getX(), this->currentHealthSprite.getY());
	for (int i = 0; i < 3; i++) {
		livesSprites.at(i).draw(graphics);
	}
}