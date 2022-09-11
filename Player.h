#pragma once
#include"DxLib.h"
#include"Tranceform.h"
#include"Map.h"
#include"Draw.h"

class Player :public Tranceform,public Map{



public:
   

	Player();
	~Player();
	void Update(int isPlayerMoveFlag,int boxpostopX,int boxposunderX,int boxpostopY,int lineposleftX,int lineposrightX,int lineposleftY);
	void Draw();

public:

	
	int wall;
   

};