#pragma once
#include"DxLib.h"
#include"Tranceform.h"
#include"Map.h"
#include"Draw.h"

class Player :public Tranceform,public Map{



public:
   

	Player();
	~Player();
	void Initialize(char* key);
	void Update(int isPlayerMoveFlag,int boxpostopX,int boxposunderX,int boxpostopY,int lineposleftX,int lineposrightX,int lineposleftY,int jumpposX ,int jumpposY,int jumpbottomX, int AboxpostopX, int AboxposunderX, int AboxpostopY, int BboxpostopX, int BboxposunderX, int BboxpostopY, int AlineposleftX, int AlineposrightX, int AlineposleftY, int BlineposleftX, int BlineposrightX, int BlineposleftY, int AjumpposX, int AjumpbottomX, int AjumpposY, int BjumpposX, int BjumpbottomX ,int BjumpposY);
	void Draw();

public:

	
	int isFlag;
	char* keyBuf_;

};