#include "Player.h"
#include <SDL.h>
// �غc�禡
Player::Player(int startX, int startY, int w, int h, int moveSpeed, SDL_Color c)
    : x(startX), y(startY), width(w), height(h), speed(moveSpeed), color(c) {
}

// ���ʥD��
void Player::move(const Uint8* keyState, int screenWidth, int screenHeight) {
    if (keyState[SDL_SCANCODE_UP]) y -= speed;
    if (keyState[SDL_SCANCODE_DOWN]) y += speed;
    if (keyState[SDL_SCANCODE_LEFT]) x -= speed;
    if (keyState[SDL_SCANCODE_RIGHT]) x += speed;

    // ����ˬd
    if (x < 0) x = 0;
    if (x + width > screenWidth) x = screenWidth - width;
    if (y < 0) y = 0;
    if (y + height > screenHeight) y = screenHeight - height;
}

// ��V�D��
void Player::render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255); // �]�w�C��
    SDL_Rect rect = { x, y, width, height }; // �D������m�M�ؤo
    SDL_RenderFillRect(renderer, &rect); // ø�s�x��
}