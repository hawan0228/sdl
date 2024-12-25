#include <SDL.h>
#ifndef PLAYER_H
#define PLAYER_H

// Player ���O�w�q
class Player {
private:
    int x, y;           // �D������m
    int width, height;  // �D�����ؤo
    int speed;          // �D�������ʳt��
    SDL_Color color;    // �D�����C��

public:
    // �غc�禡
    Player(int startX, int startY, int w, int h, int moveSpeed, SDL_Color c);

    // �B�z�����޿�
    void move(const Uint8* keyState, int screenWidth, int screenHeight);

    // ��V�D��
    void render(SDL_Renderer* renderer) const;
};

#endif // PLAYER_H