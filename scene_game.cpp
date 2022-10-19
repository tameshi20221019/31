#include "all.h"

int game_state;
int game_timer;

extern int player_state;

void game_init()
{
	game_state = 0;
	game_timer = 0;
}

void game_deinit()
{
	player_deinit();
}

void game_update()
{
	switch (game_state)
	{
	case 0:
		player_init();

		game_state++;
		/*fallthrough*/
	case 1:
		game_state++;
		/*fallthrough*/
	case 2:
		if (TRG(0) & PAD_SELECT)//バックスペースでタイトルへ戻る
		{
			nextScene = SCENE_TITLE;
		}

		player_update();

		break;
	}
	debug::setString("game_state:%d", game_state);
	debug::setString("game_timer:%d", game_timer);

	game_timer++;
}

void game_render()
{
	GameLib::clear(0, 1.0f, 1.0f);

	player_render();

}