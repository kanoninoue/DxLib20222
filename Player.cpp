#include "Player.h"
#include "Tranceform.h"
#include "DxLib.h"
#include "Draw.h"
Player::Player() {
	
	playertranceform.x = 48;
	playertranceform.y = 500;
	playertranceform.radius = 16;
	playertranceform.speed = 1;
	playertranceform.gravity = 0;
	playertranceform.oldx = 0;
	playertranceform.oldy = 0;
	playertranceform.rightTopX = 0;
	playertranceform.rightTopY = 0;
	playertranceform.leftTopY = 0;
	playertranceform.leftTopX = 0;
	playertranceform.rightBottomX = 0;
	playertranceform.rightBottomY = 0;
	playertranceform.leftBottomX = 0;
	playertranceform.leftBottomY = 0;
	playertranceform.rightTopoldX = 0;
	playertranceform.rightTopoldY = 0;
	playertranceform.leftTopoldY = 0;
	playertranceform.leftTopoldX = 0;
	playertranceform.rightBottomoldX = 0;
	playertranceform.rightBottomoldY = 0;
	playertranceform.leftBottomoldX = 0;
	playertranceform.leftBottomoldY = 0;
	isFlag = 0;
	playertranceform.GoalX = 0;
	playertranceform.GoalY = 0;
	GoalFlag = 0;

}

Player::~Player() {

}

void Player::Initialize(char* key) {
	keyBuf_ = key;
	SwitchNumber = 1;
	SwitchFlag = false;
}
void Player::Update(int isPlayerMoveFlag, int boxpostopx, int boxposunderX, int boxpostopY, int lineposleftX, int lineposrightX, int lineposleftY, int jumpposX, int jumpposY, int jumpbottomX, int AboxpostopX, int AboxposunderX, int AboxpostopY, int BboxpostopX, int BboxposunderX, int BboxpostopY,int AlineposleftX, int AlineposrightX, int AlineposleftY, int BlineposleftX, int BlineposrightX, int BlineposleftY, int AjumpposX, int AjumpbottomX, int AjumpposY, int BjumpposX, int BjumpbottomX, int BjumpposY, int ClineposleftX, int ClineposrightX, int ClineposleftY, int DlineposleftX, int DlineposrightX, int DlineposleftY, int CjumpposX, int CjumpbottomX, int CjumpposY, int DjumpposX, int DjumpbottomX, int DjumpposY, int ElineposleftX, int ElineposrightX, int ElineposleftY, int FlineposleftX, int FlineposrightX, int FlineposleftY, int EjumpposX, int EjumpbottomX, int EjumpposY, int FjumpposX, int FjumpbottomX, int FjumpposY) {
	GetDrawMode();
	GetHitKeyStateAll(keyBuf_);
	if (SwitchNumber == 2) { playertranceform.GoalX = 496; playertranceform.GoalY = 688; }
	if (SwitchNumber == 3) {
		playertranceform.GoalX = 48;
		playertranceform.GoalY = 272;
	}
	if (SwitchNumber >= 2) {
		if (keyBuf_[KEY_INPUT_R] == 1) {
			playertranceform.x = 48;
			playertranceform.y = 500;
			playertranceform.radius = 16;
			playertranceform.speed = 1;
			playertranceform.gravity = 0;
			playertranceform.oldx = 0;
			playertranceform.oldy = 0;
			playertranceform.rightTopX = 0;
			playertranceform.rightTopY = 0;
			playertranceform.leftTopY = 0;
			playertranceform.leftTopX = 0;
			playertranceform.rightBottomX = 0;
			playertranceform.rightBottomY = 0;
			playertranceform.leftBottomX = 0;
			playertranceform.leftBottomY = 0;
			playertranceform.rightTopoldX = 0;
			playertranceform.rightTopoldY = 0;
			playertranceform.leftTopoldY = 0;
			playertranceform.leftTopoldX = 0;
			playertranceform.rightBottomoldX = 0;
			playertranceform.rightBottomoldY = 0;
			playertranceform.leftBottomoldX = 0;
			playertranceform.leftBottomoldY = 0;
			isFlag = 0;

		}
		if (playertranceform.y>704) {
			isPlayerMoveFlag = true;
		}
		playertranceform.oldx = playertranceform.x;
		playertranceform.oldy = playertranceform.y;
		if (isPlayerMoveFlag == false) {
			playertranceform.y += playertranceform.gravity;
			playertranceform.gravity += 1;
			playertranceform.x += playertranceform.speed;
			if (playertranceform.x + playertranceform.radius >= boxpostopx &&
				playertranceform.x - playertranceform.radius <= boxposunderX && playertranceform.y <= boxpostopY && playertranceform.y + playertranceform.radius > boxpostopY)
			{
				playertranceform.gravity = 0;

				playertranceform.y = boxpostopY - playertranceform.radius;
			}
			if (playertranceform.x + playertranceform.radius == boxpostopx && playertranceform.y > boxpostopY) {
				playertranceform.speed *= -1;
			}
			if (playertranceform.x - playertranceform.radius == boxposunderX && playertranceform.y > boxpostopY) {
				playertranceform.speed *= -1;
			}
			if (playertranceform.x + playertranceform.radius >= AboxpostopX &&
				playertranceform.x - playertranceform.radius <= AboxposunderX && playertranceform.y <= AboxpostopY && playertranceform.y + playertranceform.radius > boxpostopY)
			{
				playertranceform.gravity = 0;

				playertranceform.y = AboxpostopY - playertranceform.radius;
			}
			if (playertranceform.x + playertranceform.radius == AboxpostopX && playertranceform.y > AboxpostopY) {
				playertranceform.speed *= -1;
			}
			if (playertranceform.x - playertranceform.radius == AboxposunderX && playertranceform.y > AboxpostopY) {
				playertranceform.speed *= -1;
			}
			if (playertranceform.x + playertranceform.radius >= BboxpostopX &&
				playertranceform.x - playertranceform.radius <= BboxposunderX && playertranceform.y <= BboxpostopY && playertranceform.y + playertranceform.radius > boxpostopY)
			{
				playertranceform.gravity = 0;

				playertranceform.y = BboxpostopY - playertranceform.radius;
			}
			if (playertranceform.x + playertranceform.radius == BboxpostopX && playertranceform.y > BboxpostopY) {
				playertranceform.speed *= -1;
			}
			if (playertranceform.x - playertranceform.radius == BboxposunderX && playertranceform.y > BboxpostopY) {
				playertranceform.speed *= -1;
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			isFlag = 0;
			//1
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ lineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/lineposleftX && playertranceform.y < /*lefty2*/lineposleftY && playertranceform.y + playertranceform.radius > lineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 1;
				playertranceform.y = lineposleftY - playertranceform.radius;
			}
			
			if (playertranceform.x - playertranceform.radius > /*rightx2*/ lineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/lineposleftX && playertranceform.y < /*lefty2*/lineposleftY && playertranceform.y + playertranceform.radius > lineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 1;
				playertranceform.y = lineposleftY - playertranceform.radius;
			}


			//2
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ AlineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/AlineposleftX && playertranceform.y < /*lefty2*/AlineposleftY && playertranceform.y + playertranceform.radius > AlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = AlineposleftY - playertranceform.radius;
			}
			
			if (playertranceform.x - playertranceform.radius > /*rightx2*/ AlineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/AlineposleftX && playertranceform.y < /*lefty2*/AlineposleftY && playertranceform.y + playertranceform.radius > AlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = AlineposleftY - playertranceform.radius;
			}


			//3
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ BlineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/BlineposleftX && playertranceform.y < /*lefty2*/BlineposleftY && playertranceform.y + playertranceform.radius > BlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = BlineposleftY - playertranceform.radius;
			}

			if (playertranceform.x - playertranceform.radius > /*rightx2*/ BlineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/BlineposleftX && playertranceform.y < /*lefty2*/BlineposleftY && playertranceform.y + playertranceform.radius > BlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = BlineposleftY - playertranceform.radius;
			}

			//4
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ ClineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/ClineposleftX && playertranceform.y < /*lefty2*/ClineposleftY && playertranceform.y + playertranceform.radius > ClineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = ClineposleftY - playertranceform.radius;
			}

			if (playertranceform.x - playertranceform.radius > /*rightx2*/ ClineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/ClineposleftX && playertranceform.y < /*lefty2*/ClineposleftY && playertranceform.y + playertranceform.radius > ClineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = ClineposleftY - playertranceform.radius;
			}


			//5
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ DlineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/DlineposleftX && playertranceform.y < /*lefty2*/DlineposleftY && playertranceform.y + playertranceform.radius > DlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = DlineposleftY - playertranceform.radius;
			}

			if (playertranceform.x - playertranceform.radius > /*rightx2*/ DlineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/DlineposleftX && playertranceform.y < /*lefty2*/DlineposleftY && playertranceform.y + playertranceform.radius > DlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = DlineposleftY - playertranceform.radius;
			}

			//6
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ ElineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/ElineposleftX && playertranceform.y < /*lefty2*/ElineposleftY && playertranceform.y + playertranceform.radius > ElineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = ElineposleftY - playertranceform.radius;
			}

			if (playertranceform.x - playertranceform.radius > /*rightx2*/ ElineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/ElineposleftX && playertranceform.y < /*lefty2*/ElineposleftY && playertranceform.y + playertranceform.radius > ElineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 2;
				playertranceform.y = ElineposleftY - playertranceform.radius;
			}


			//7
			if (playertranceform.x + playertranceform.radius > /*rightx2*/ FlineposrightX &&
				playertranceform.x - playertranceform.radius < /*leftx2*/FlineposleftX && playertranceform.y < /*lefty2*/FlineposleftY && playertranceform.y + playertranceform.radius > FlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = FlineposleftY - playertranceform.radius;
			}

			if (playertranceform.x - playertranceform.radius > /*rightx2*/ FlineposrightX &&
				playertranceform.x + playertranceform.radius < /*leftx2*/FlineposleftX && playertranceform.y < /*lefty2*/FlineposleftY && playertranceform.y + playertranceform.radius > FlineposleftY)
			{
				playertranceform.gravity = 0;
				isFlag = 3;
				playertranceform.y = FlineposleftY - playertranceform.radius;
			}



			//////////////////////////////////////////////////////////////////////////////////////
			//1
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ jumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/jumpbottomX && playertranceform.y >= jumpposY && playertranceform.y - playertranceform.radius-16 < jumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}
			}
			//2
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ AjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/AjumpbottomX && playertranceform.y >= AjumpposY && playertranceform.y - playertranceform.radius-16 < AjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}

			}

		//3
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ BjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/BjumpbottomX && playertranceform.y >= BjumpposY && playertranceform.y - playertranceform.radius-16 < BjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}
			}
			//4
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ CjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/CjumpbottomX && playertranceform.y >= CjumpposY && playertranceform.y - playertranceform.radius-16 < CjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}

			}
			//5
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ DjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/DjumpbottomX && playertranceform.y >= DjumpposY && playertranceform.y - playertranceform.radius-16 < DjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}
			}
			//6
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ EjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/EjumpbottomX && playertranceform.y >= EjumpposY && playertranceform.y - playertranceform.radius-16 < EjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}

			}
			//7
			if (playertranceform.x + playertranceform.radius >= /*rightx2*/ FjumpposX &&
				playertranceform.x - playertranceform.radius <= /*leftx2*/FjumpbottomX && playertranceform.y >= FjumpposY && playertranceform.y - playertranceform.radius-16 < FjumpposY)
			{
				if (playertranceform.speed >= 1) {
					playertranceform.gravity = -21;
					playertranceform.speed = 1;
				}
				else {
					playertranceform.gravity = -21;
					playertranceform.speed = -1;
				}
			}
			if (playertranceform.x + playertranceform.radius == playertranceform.GoalX &&
				playertranceform.y == playertranceform.GoalY)
			{
				GoalFlag = 1;
			}

			if (playertranceform.x - playertranceform.radius == playertranceform.GoalX &&
				playertranceform.y == playertranceform.GoalY)
			{
				GoalFlag = 1;
			}

		}


		//左上のマップチップ上での座標を取得
		playertranceform.leftTopX = (playertranceform.x - playertranceform.radius) / BlockSize;
		playertranceform.leftTopY = (playertranceform.y - playertranceform.radius) / BlockSize;

		//左下でのマップチップ上での座標を取得
		playertranceform.leftBottomX = (playertranceform.x - playertranceform.radius) / BlockSize;
		playertranceform.leftBottomY = (playertranceform.y + playertranceform.radius - 1) / BlockSize;

		//右上のマップチップ上での座標を取得
		playertranceform.rightTopX = (playertranceform.x + playertranceform.radius - 1) / BlockSize;
		playertranceform.rightTopY = (playertranceform.y - playertranceform.radius) / BlockSize;

		//右下のマップチップ上での座標を取得
		playertranceform.rightBottomX = (playertranceform.x + playertranceform.radius - 1) / BlockSize;
		playertranceform.rightBottomY = (playertranceform.y + playertranceform.radius - 1) / BlockSize;

		/////////過去/////////
		//左上のマップチップ上での座標を取得
		playertranceform.leftTopoldX = (playertranceform.oldx - playertranceform.radius) / BlockSize;
		playertranceform.leftTopoldY = (playertranceform.oldy - playertranceform.radius) / BlockSize;

		//左下でのマップチップ上での座標を取得
		playertranceform.leftBottomoldX = (playertranceform.oldx - playertranceform.radius) / BlockSize;
		playertranceform.leftBottomoldY = (playertranceform.oldy + playertranceform.radius - 1) / BlockSize;

		//右上のマップチップ上での座標を取得
		playertranceform.rightTopoldX = (playertranceform.oldx + playertranceform.radius - 1) / BlockSize;
		playertranceform.rightTopoldY = (playertranceform.oldy - playertranceform.radius) / BlockSize;

		//右下のマップチップ上での座標を取得
		playertranceform.rightBottomoldX = (playertranceform.oldx + playertranceform.radius - 1) / BlockSize;
		playertranceform.rightBottomoldY = (playertranceform.oldy + playertranceform.radius - 1) / BlockSize;

		//マップチップ
		if (SwitchNumber == 3) {
			//床の判定
			if (PlayMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 0 && PlayMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (PlayMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 1 && PlayMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (PlayMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 1 && PlayMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (PlayMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 0 && PlayMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (PlayMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 1 && PlayMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (PlayMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 1 && PlayMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (PlayMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 0 && PlayMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (PlayMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 1 && PlayMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (PlayMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 1 && PlayMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (PlayMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 0 && PlayMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (PlayMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 1 && PlayMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (PlayMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 1 && PlayMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (PlayMap[playertranceform.rightBottomY][playertranceform.rightBottomX] == 1) {
				playertranceform.gravity = 0;
			}
		}
		///////////////////////////////////////
		

		//マップチップ
		//床の判定
		if (SwitchNumber == 2) {
			if (tutorialMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 0 && tutorialMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (tutorialMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 1 && tutorialMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (tutorialMap[playertranceform.leftTopoldY][playertranceform.leftTopX] == 1 && tutorialMap[playertranceform.leftTopY][playertranceform.leftTopoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (tutorialMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 0 && tutorialMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (tutorialMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 1 && tutorialMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (tutorialMap[playertranceform.rightTopoldY][playertranceform.rightTopX] == 1 && tutorialMap[playertranceform.rightTopY][playertranceform.rightTopoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (tutorialMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 0 && tutorialMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (tutorialMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 1 && tutorialMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (tutorialMap[playertranceform.leftBottomoldY][playertranceform.leftBottomX] == 1 && tutorialMap[playertranceform.leftBottomY][playertranceform.leftBottomoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (tutorialMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 0 && tutorialMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 1) {
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;

			}
			else if (tutorialMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 1 && tutorialMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 0) {
				playertranceform.x = playertranceform.oldx;
			}
			else if (tutorialMap[playertranceform.rightBottomoldY][playertranceform.rightBottomX] == 1 && tutorialMap[playertranceform.rightBottomY][playertranceform.rightBottomoldX] == 1) {
				playertranceform.x = playertranceform.oldx;
				playertranceform.y = playertranceform.oldy;
				playertranceform.gravity = 0;
			}

			if (tutorialMap[playertranceform.rightBottomY][playertranceform.rightBottomX] == 1) {
				playertranceform.gravity = 0;
			}
		}
	}
		//タイトル
		if (SwitchNumber == 1) {
			SwitchFlag = 0;
			if (keyBuf_[KEY_INPUT_M] == 1) {
				SwitchFlag = 1;
			}
			if (SwitchFlag == 1) {
				SwitchNumber = 2;
			}
		}
		//チュートリアル
		if (SwitchNumber == 2) {
			SwitchFlag = 0;
			if (keyBuf_[KEY_INPUT_N] == 1) {
				SwitchFlag = 1;
			}
			if (SwitchFlag == 1) {
				playertranceform.x = 48;
				playertranceform.y = 500;
				playertranceform.radius = 16;
				playertranceform.speed = 1;
				playertranceform.gravity = 0;
				playertranceform.oldx = 0;
				playertranceform.oldy = 0;
				playertranceform.rightTopX = 0;
				playertranceform.rightTopY = 0;
				playertranceform.leftTopY = 0;
				playertranceform.leftTopX = 0;
				playertranceform.rightBottomX = 0;
				playertranceform.rightBottomY = 0;
				playertranceform.leftBottomX = 0;
				playertranceform.leftBottomY = 0;
				playertranceform.rightTopoldX = 0;
				playertranceform.rightTopoldY = 0;
				playertranceform.leftTopoldY = 0;
				playertranceform.leftTopoldX = 0;
				playertranceform.rightBottomoldX = 0;
				playertranceform.rightBottomoldY = 0;
				playertranceform.leftBottomoldX = 0;
				playertranceform.leftBottomoldY = 0;
				isFlag = 0;
				SwitchNumber = 3;
			}
		}
		//ステージ1
		if (SwitchNumber == 3) {
			SwitchFlag = 0;
			if (keyBuf_[KEY_INPUT_B] == 1) {
				if (GoalFlag == 1) {
					SwitchFlag = 1;
				}
			}
			if (SwitchFlag == 1) {
				SwitchNumber = 1;
			}
		}


	
}

void Player::Draw() {
	if (SwitchNumber == 1) {
		DrawFormatString(25, 50, 0xffff, "タイトル", true);
		DrawFormatString(25, 75, 0xffff, "Mでちゅーとりある", true);
	}
	if (SwitchNumber == 2) {
		DrawFormatString(25, 50, 0xffff, "チュートリアル", true);
		DrawFormatString(25, 75, 0xffff, "Nでステージ", true);

		DrawBox(playertranceform.x - playertranceform.radius, playertranceform.y - playertranceform.radius, playertranceform.x + playertranceform.radius, playertranceform
			.y + playertranceform.radius, 0xffff0, true);
		DrawBox(playertranceform.GoalX - playertranceform.radius, playertranceform.GoalY - playertranceform.radius, playertranceform.GoalX + playertranceform.radius, playertranceform
			.GoalY + playertranceform.radius, 0xffff00, true);
	}

	if (SwitchNumber == 3) {
		DrawBox(playertranceform.x - playertranceform.radius, playertranceform.y - playertranceform.radius, playertranceform.x + playertranceform.radius, playertranceform
			.y + playertranceform.radius, 0xffff0, true);
		DrawBox(playertranceform.GoalX - playertranceform.radius, playertranceform.GoalY - playertranceform.radius, playertranceform.GoalX + playertranceform.radius, playertranceform
			.GoalY + playertranceform.radius, 0xffff00, true);

		//DrawFormatString(25, 250, 0xff00ff, "posx1:%d", , true);
		DrawFormatString(25, 275, 0xff00ff, "posy1:%d", GoalFlag, true);
	}
}

