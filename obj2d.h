#ifndef OBJ2D_H
#define OBJ2D_H

struct OBJ2D
{
	int					state;
	int					timer;

	GameLib::Sprite*	spr;

	VECTOR2				pos;
	VECTOR2				scale;
	VECTOR2				texPos;
	VECTOR2				texSize;
	VECTOR2				pivot;
	VECTOR4				color;

	VECTOR2				speed;
	int					act;
	int					anime;
	int					animeTimer;

	float				angle ;
};

#endif // !OBJ2D_H

