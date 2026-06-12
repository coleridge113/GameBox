#include "Player.h"

Player::Player(int startX, int startY, char s)
    : x(startX), y(startY), symbol(s) {}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}
