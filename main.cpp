#include "all.h"

int curScene = SCENE_NONE;
int nextScene = SCENE_TITLE;

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	GameLib::init(L"�����Ńv���W�F�N�g���쐬", SCREEN_W, SCREEN_H);
	
	while (GameLib::gameLoop())
	{
		// �V�[���؂�ւ�����
		if (curScene != nextScene)
		{
			// ���݂̃V�[���ɉ������I������
			switch (curScene)
			{
			case SCENE_TITLE:
				title_deinit();
				break;
			case SCENE_GAME:
				game_deinit();
				break;
			}
			// ���̃V�[���ɉ����������ݒ菈��
			switch (nextScene)
			{
			case SCENE_TITLE:
				title_init();
				break;
			case SCENE_GAME:
				game_init();
				break;
			}
			// nextScene �� curScene �ɂȂ�
			curScene = nextScene;
		}

		input::update();

		// ���݂̃V�[���ɉ������X�V�E�`�揈��
		switch (curScene)
		{
		case SCENE_TITLE:
			title_update();
			title_render();
			break;
		case SCENE_GAME:
			game_update();
			game_render();
			break;
		}

		debug::display(0,1,0,1,1);
		GameLib::present(1, 0);
	}

		// ���݂̃V�[���ɉ������I���������s��
	switch (curScene)
	{
	case SCENE_TITLE:
		title_deinit();
		break;
	case SCENE_GAME:
		game_deinit();
		break;
	}

	GameLib::uninit();
}
