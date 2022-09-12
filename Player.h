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
	void Update(int isPlayerMoveFlag,int boxpostopX,int boxposunderX,int boxpostopY,int lineposleftX,int lineposrightX,int lineposleftY,int jumpposX ,int jumpposY,int jumpbottomX, int AboxpostopX, int AboxposunderX, int AboxpostopY, int BboxpostopX, int BboxposunderX, int BboxpostopY, int AlineposleftX, int AlineposrightX, int AlineposleftY, int BlineposleftX, int BlineposrightX, int BlineposleftY, int AjumpposX, int AjumpbottomX, int AjumpposY, int BjumpposX, int BjumpbottomX ,int BjumpposY, int ClineposleftX, int ClineposrightX, int ClineposleftY, int DlineposleftX, int DlineposrightX, int DlineposleftY, int CjumpposX, int CjumpbottomX, int CjumpposY, int DjumpposX, int DjumpbottomX, int DjumpposY, int ElineposleftX, int ElineposrightX, int ElineposleftY, int FlineposleftX, int FlineposrightX, int FlineposleftY, int EjumpposX, int EjumpbottomX, int EjumpposY, int FjumpposX, int FjumpbottomX, int FjumpposY);
	void Draw();
	int GetSceneNumber() { return SwitchNumber; }
public:

	
	int isFlag;
	char* keyBuf_;
	int SwitchNumber = 1;
	int SwitchFlag = false;
	int GoalFlag = 0;
};