#ifndef COMMON_H
#define COMMON_H

#include "../GameLib/game_lib.h"
using namespace GameLib;

// �V�[���̃��x�� 
#define SCENE_NONE -1 
#define SCENE_TITLE 0 
#define SCENE_GAME 1 

#define SCREEN_W 1280
#define SCREEN_H 720

extern float(* const ToRadian)(float);// �p�x�����W�A����
extern float(* const ToDegree)(float);// ���W�A�����p�x��

extern int curScene;
extern int nextScene;

#endif//COMMON_H
