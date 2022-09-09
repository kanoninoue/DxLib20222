#pragma once
#include "DxLib.h"
#include "Tranceform.h"
#include "Player.h"
#include "Map.h"
class Collision : public Player ,public Map{
public:
	Collision();

	~Collision();

	void Update();

	void Draw();

private:

	

};