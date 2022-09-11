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

}

Player::~Player() {

}

void Player::Initialize(char* key) {
	keyBuf_ = key;
}
void Player::Update(int isPlayerMoveFlag, int boxpostopx, int boxposunderX, int boxpostopY, int lineposleftX, int lineposrightX, int lineposleftY, int jumpposX, int jumpposY, int jumpbottomX, int AboxpostopX, int AboxposunderX, int AboxpostopY, int BboxpostopX, int BboxposunderX, int BboxpostopY,int AlineposleftX, int AlineposrightX, int AlineposleftY, int BlineposleftX, int BlineposrightX, int BlineposleftY, int AjumpposX, int AjumpbottomX, int AjumpposY, int BjumpposX, int BjumpbottomX, int BjumpposY) {
	GetDrawMode();
	GetHitKeyStateAll(keyBuf_);
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
	
	playertranceform.oldx = playertranceform.x;
	playertranceform.oldy = playertranceform.y;
	if (isPlayerMoveFlag == false) {
		playertranceform.y += playertranceform.gravity;
		playertranceform.gravity += 1;
		playertranceform.x += playertranceform.speed;
		if (playertranceform.x + playertranceform.radius >= boxpostopx &&
			playertranceform.x - playertranceform.radius <= boxposunderX && playertranceform.y <= boxpostopY)
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
			playertranceform.x - playertranceform.radius <= AboxposunderX && playertranceform.y <= AboxpostopY)
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
			playertranceform.x - playertranceform.radius <= BboxposunderX && playertranceform.y <= BboxpostopY)
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

		if (playertranceform.x + playertranceform.radius > /*rightx2*/ lineposrightX &&
			playertranceform.x - playertranceform.radius < /*leftx2*/lineposleftX && playertranceform.y < /*lefty2*/lineposleftY&&playertranceform.y + playertranceform.radius > lineposleftY )
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



		//////////////////////////////////////////////////////////////////////////////////////
		if (playertranceform.x + playertranceform.radius >= /*rightx2*/ jumpposX &&
			playertranceform.x - playertranceform.radius <= /*leftx2*/jumpbottomX && playertranceform.y >= jumpposY)
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
		if (playertranceform.x + playertranceform.radius >= /*rightx2*/ AjumpposX &&
			playertranceform.x - playertranceform.radius <= /*leftx2*/AjumpbottomX && playertranceform.y >= AjumpposY)
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
		if (playertranceform.x + playertranceform.radius >= /*rightx2*/ BjumpposX &&
			playertranceform.x - playertranceform.radius <= /*leftx2*/BjumpbottomX && playertranceform.y >= BjumpposY)
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

void Player::Draw() {

	DrawBox(playertranceform.x - playertranceform.radius, playertranceform.y - playertranceform.radius, playertranceform.x + playertranceform.radius, playertranceform
		.y + playertranceform.radius, 0xffff0, true);

	//DrawFormatString(25, 250, 0xff00ff, "posx1:%d", , true);
	DrawFormatString(25, 275, 0xff00ff, "posy1:%d", isFlag, true);
}

