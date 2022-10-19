#include "all.h"

int player_state;

OBJ2D player;

Sprite* sprPlayer;

void player_init()
{
	player_state = 0;
}

void player_deinit()
{
	safe_delete(sprPlayer);
}

void player_update()
{
	switch (player_state)
	{
	case 0:
		sprPlayer = sprite_load(L"./Data/Images/player_001.PNG");

		++player_state;
		/*falltheough*/

	case 1:

		player = {};
		player.timer = 0;
		player.pos = { SCREEN_W / 2,SCREEN_H / 2 };
		player.scale = { 1.0f,1.0f };
		player.texPos = { 0,0 };
		player.texSize = { PLAYER_TEX_W,PLAYER_TEX_H };
		player.pivot = { PLAYER_PIVOT_X,PLAYER_PIVOT_Y };
		player.angle = ToRadian(0);
		player.color = { 1.0f,1.0f,1.0f,1.0f };
		player.act = PLAYER_ACT::IDLE_INIT;

		++player_state;
		/*fallthrough*/

	case 2:

		player_act();
		player_move();

		player.pos += player.speed;

		debug::setString("player pos.x:%f pos.y:%f", player.pos.x, player.pos.y);
		debug::setString("player act:%d",player.act);

		break;
	}
}

void player_render()
{
	sprite_render(
		sprPlayer,
		player.pos.x, player.pos.y,
		player.scale.x, player.scale.y,
		player.texPos.x, player.texPos.y,
		player.texSize.x, player.texSize.y,
		player.pivot.x, player.pivot.y,
		player.angle,
		player.color.x, player.color.y, player.color.z, player.color.w
	);
}

void player_act()
{
	switch (player.act)
	{
	case PLAYER_ACT::IDLE_INIT:

		player.anime = player.animeTimer = 0;
		player.texPos.x = 0;//�����Ă��������������đҋ@���邽�߂ɂ�����animeInit�֐����g���Ă��Ȃ�

		++player.act;
		/*fallthrough*/

	case PLAYER_ACT::IDLE:

		player_move();

		//�s���̑J��
		if (fabsf(player.speed.x) || fabsf(player.speed.y))//�v���C���[�X�s�[�h�̐�Βl
		{
			player.act = PLAYER_ACT::WALK_INIT;
		}

		break;

	case PLAYER_ACT::WALK_INIT:

		if (0 > player.speed.x)
		{
			animeInit(&player,PLAYER_WALK_RIGHT);
		}
		else if (0 < player.speed.x)
		{
			animeInit(&player, PLAYER_WALK_LEFT);
		}
		if (0 > player.speed.y)
		{
			animeInit(&player, PLAYER_WALK_UP);
		}
		else if (0 < player.speed.y)
		{
			animeInit(&player, PLAYER_WALK_DOWN);
		}

		++player.act;
		/*fallthrough*/

	case PLAYER_ACT::WALK:

		player_move();

		anime(&player,7,5,true);

		//�㉺���E�̃A�j���؂�ւ�
		if (0 > player.speed.x)
		{
			player.texPos.y = player.texSize.y * PLAYER_WALK_RIGHT;
		}
		else if (0 < player.speed.x)
		{
			player.texPos.y = player.texSize.y * PLAYER_WALK_LEFT;
		}
		if (0 > player.speed.y)
		{
			player.texPos.y = player.texSize.y * PLAYER_WALK_UP;
		}
		else if (0 < player.speed.y)
		{
			player.texPos.y = player.texSize.y * PLAYER_WALK_DOWN;
		}

		//�s���̑J��
		if (fabsf(player.speed.x) == 0 && fabsf(player.speed.y) == 0)//�v���C���[�X�s�[�h�̐�Βl
		{
			player.act = PLAYER_ACT::IDLE_INIT;
		}

		break;
	}
}

void player_move()
{
	if (STATE(0) & PAD_RIGHT && !(STATE(0) & PAD_LEFT))
	{
		player.speed.x = PLAYER_WALK_SPEED;
	}
	else if (STATE(0) & PAD_LEFT && !(STATE(0) & PAD_RIGHT))
	{
		player.speed.x = -PLAYER_WALK_SPEED;
	}
	else
	{
		player.speed.x = 0.0f;
	}

	if (STATE(0) & PAD_UP && !(STATE(0) & PAD_DOWN))
	{
		player.speed.y = -PLAYER_WALK_SPEED;
	}
	else if (STATE(0) & PAD_DOWN && !(STATE(0) & PAD_UP))
	{
		player.speed.y = PLAYER_WALK_SPEED;
	}
	else
	{
		player.speed.y = 0.0f;
	}
}