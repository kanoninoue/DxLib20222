#pragma once
#include"DxLib.h"
#include"Tranceform.h"
#include"Map.h"


class Player :public Tranceform,public Map {



public:
   

	Player();
	~Player();
	void Update();
	void Draw();

private:



   

};