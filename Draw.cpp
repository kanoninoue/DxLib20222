#include"Draw.h"
#include "DxLib.h"
#include <stdlib.h>

void Drawing::Initialize(char* key) {
	//キー入力用変数
	keyBuf_ = key;
	//linesegMaX_ = 1000;
	linesegCnt_ = 0;

	bline_ = (lineseg*)malloc(linesegMaX_ * sizeof(lineseg));
	/* if (bline == NULL) {
		 return -1;
	 }*/
}

void Drawing::Update() {
	//キー入力
	GetHitKeyStateAll(keyBuf_);
	if (keyBuf_[KEY_INPUT_1] == 1) { isPenF_ = true; }
	if (keyBuf_[KEY_INPUT_2] == 1) { isPenF_ = false; isDrag_ = false; }
	if (keyBuf_[KEY_INPUT_0] == 1) { linesegCnt_ = 0; }

	if (DrawFlag == false) {
		GetTimer++;
		if (keyBuf_[KEY_INPUT_P] == 1 && GetTimer >= 30) {
			DrawFlag = true; GetTimer = 0;
		}
	}
	else if (DrawFlag == true) {
		GetTimer++;
		if (keyBuf_[KEY_INPUT_P] == 1 && GetTimer >= 60) {
			DrawFlag = false; GetTimer = 0;
		}

	}
	//マウス座標取得
	GetMousePoint(&posX_, &posY_);
	if (DrawFlag == true) {
		//マウス入力処理
		if (GetMouseInput() & MOUSE_INPUT_LEFT) {
			//ドラッグ中は座標を追加
			//(前と座標が同じでも追加されるので、メモリ節約したい場合は移動した時だけ追加するようにした方がいい…)
			bline_[linesegCnt_].blackLineX = posX_;
			bline_[linesegCnt_].blackLineY = posY_;
			PosLineLeftX = posX_;
			PosLineLeftY = posY_;
			PosLineRightX2 = PosLineRightX;
			
			////////////////////////////////
			DrawLineFlag = true;
			if (isPenF_) {
				if (isDrag_) {//ドラッグ中は線を引く
					bline_[linesegCnt_].pType = PencilType::Pen;
				}
				else {//ドラッグ開始
					isDrag_ = true;    //ドラッグフラグをオンにする
					bline_[linesegCnt_].pType = PencilType::Non;
				}
			}
			else {
				bline_[linesegCnt_].pType = PencilType::Eraser;
			}
			linesegCnt_++;
			//メモリが足りなくなったら拡大
			if (linesegCnt_ == linesegMaX_) {
				linesegMaX_ += 1000;
				lineseg* tmp = (lineseg*)realloc(bline_, linesegMaX_ * sizeof(lineseg));
				/* if (tmp == NULL) {
					 free(bline);
					 return -1;
				 }*/
				bline_ = tmp;
			}
		}
		else {//マウスのキーは押されていない
			if (isDrag_)isDrag_ = false;  //ドラッグフラグをオフにする
			PosLineRightX = posX_;
			DrawLineFlag = FALSE;
			
		}
		
		if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
			PosBoxTopX = posX_;
			PosBoxTopY = posY_;
			PosBoxUnderX2 = PosBoxUnderX;
			PosBoxUnderY2 = PosBoxUnderY;
			Drawingflag = TRUE;
		}
		else {
			PosBoxUnderX = posX_;
			PosBoxUnderY = posY_;
			Drawingflag = FALSE;
		}
		if (GetMouseInputLog2(&Button, &posX_, &posY_, &LogType, TRUE) == 0) {
			if ((Button & MOUSE_INPUT_RIGHT) != 0) {
				PosBoxTopX2 = PosBoxTopX;
				PosBoxTopY2 = PosBoxTopY;
			}
			if ((Button & MOUSE_INPUT_LEFT) != 0) {
				PosLineLeftX2 = PosLineLeftX;
				PosLineLeftY2 = PosLineLeftY;

			}
		}

	}
}
void Drawing::Draw() {
	//bline配列の情報を描画
	//if (DrawFlag == 1) {
		//for (int i = 0; i < linesegCnt_; i++) {
			//switch (bline_[i].pType)
			//{
			//case  Drawing::Pen:
				//DrawLine(bline_[i - 1].blackLineX, bline_[i - 1].blackLineY, bline_[i].blackLineX, bline_[i].blackLineY, 0x0, 3);
				//break;
			//case  Drawing::Eraser:
				//DrawBox(bline_[i].blackLineX - 20, bline_[i].blackLineY - 20, bline_[i].blackLineX + 20, bline_[i].blackLineY + 20, 0xffffff, TRUE);
				//break;
			//}
		//}
		if (DrawLineFlag == TRUE) {
			DrawLine(PosLineLeftX, PosLineLeftY, PosLineRightX, PosLineLeftY, 0xff0000, true);
		}
		if (DrawLineFlag == FALSE) {
			DrawLine(PosLineLeftX2, PosLineLeftY2, PosLineRightX2, PosLineLeftY2, 0xff0000, true);
		}

		if (Drawingflag == TRUE) {
			DrawBox(PosBoxTopX, PosBoxTopY, PosBoxUnderX, PosBoxUnderY, 0xff00ff, true);
		}
		if (Drawingflag == FALSE) {
			DrawBox(PosBoxTopX2, PosBoxTopY2, PosBoxUnderX2, PosBoxUnderY2, 0xff00ff, true);
		}
	//}
	//文字等描画
	DrawString(0, 0, "キー操作：0=全削除 1=ペン 2=消しゴム", 0x0);


	if (isPenF_) {
		DrawString(0, 16, "現在のモード：ペン", 0x0);
		DrawLine(posX_, posY_ - 10, posX_, posY_ + 10, 0x0);
		DrawLine(posX_ - 10, posY_, posX_ + 10, posY_, 0x0);
	}
	else {
		DrawString(0, 16, "現在のモード：消しゴム", 0x0);
		DrawBox(posX_ - 20, posY_ - 20, posX_ + 20, posY_ + 20, 0xffffff, TRUE);
		DrawBox(posX_ - 20, posY_ - 20, posX_ + 20, posY_ + 20, 0x0, FALSE);
	}

	DrawFormatString(25, 50, 0xff00ff, "mousex:%d", PosBoxTopX, true);
	DrawFormatString(25, 75, 0xff00ff, "mousey:%d", PosBoxTopY, true);
	DrawFormatString(25, 100, 0xff00ff, "mousex1:%d", PosBoxUnderX, true);
	DrawFormatString(25, 125, 0xff00ff, "mousey1:%d", PosBoxUnderY, true);
	DrawFormatString(25, 150, 0xff00ff, "posx:%d", PosLineLeftX2, true);
	DrawFormatString(25, 175, 0xff00ff, "posy:%d", PosLineLeftY2, true);
	DrawFormatString(25, 200, 0xff00ff, "posx1:%d", PosLineRightX2, true);
	DrawFormatString(25, 225, 0xff00ff, "posy1:%d", PosBoxUnderY2, true);
}
	
 