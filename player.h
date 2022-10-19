#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_TEX_W	64.0f//�v���C���[�摜�̕�����
#define PLAYER_TEX_H	64.0f
#define PLAYER_PIVOT_X	32.0f//���S
#define PLAYER_PIVOT_Y	32.0f

#define PLAYER_WALK_SPEED 3.0f

#define PLAYER_WALK_DOWN 0//�A�j��No���������萔
#define PLAYER_WALK_RIGHT 1
#define PLAYER_WALK_LEFT 2
#define PLAYER_WALK_UP 3

enum PLAYER_ACT
{
	IDLE_INIT = 0,
	IDLE,
	WALK_INIT,
	WALK,
};

void player_init();
void player_deinit();
void player_update();
void player_render();

void player_act();
void player_move();

void player_animeInit(int);
bool player_anime(int, int, bool);

#endif // !PLAYER_H

