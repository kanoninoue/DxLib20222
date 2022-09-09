#pragma once
#include"DxLib.h"
#include"Tranceform.h"
#include"Map.h"
#include"Draw.h"

class Player :public Tranceform,public Map,public Drawing {



public:
   

	Player();
	~Player();
	void Update();
	void Draw();

private:



   

};