#include "all.h"

int title_state;
int title_timer;

Sprite* sprCar;

void title_init()
{
	title_state = 0;
	title_timer = 0;
}
void title_deinit()
{
	
}
void title_update()
{
	switch (title_state)
	{
	case 0:
		/////初期設定/////

		title_state++;
		/*fallthrough*/
	case 1:
		/////パラメータの設定/////

		GameLib::setBlendMode(Blender::BS_ALPHA);
		title_state++;
		/*fallthrough*/
	case 2:
		/////通常時/////
		
		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_GAME;
			break;
		}
		break;
	}
	debug::setString("title_state:%d", title_state);
	debug::setString("title_timer:%d", title_timer);


	title_timer++;
}
void title_render()
{
	GameLib::clear(0, 0, 0);
	
	font::textOut(5, "Push Enter Key", 100, 500, 1.5f, 1.5f, 1, 1, 1);
}