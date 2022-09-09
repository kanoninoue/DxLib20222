#pragma once
#include"DxLib.h"
#include"Tranceform.h"
#include"Map.h"
#include"Draw.h"

class Player :public Tranceform,public Map{



public:
   

	Player();
	~Player();
	void Update(int isPlayerMoveFlag);
	void Draw();

public:

	
	
   

};