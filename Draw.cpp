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


	//マウス座標取得
	GetMousePoint(&posX_, &posY_);

	//マウス入力処理
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		//ドラッグ中は座標を追加
		//(前と座標が同じでも追加されるので、メモリ節約したい場合は移動した時だけ追加するようにした方がいい…)
		bline_[linesegCnt_].blackLineX = posX_;
		bline_[linesegCnt_].blackLineY = posY_;
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
	}
}
void Drawing::Draw() {
	//bline配列の情報を描画
	for (int i = 0; i < linesegCnt_; i++) {
		switch (bline_[i].pType)
		{
		case  Drawing::Pen:
			DrawLine(bline_[i - 1].blackLineX, bline_[i - 1].blackLineY, bline_[i].blackLineX, bline_[i].blackLineY, 0x0, 3);
			break;
		case  Drawing::Eraser:
			DrawBox(bline_[i].blackLineX - 20, bline_[i].blackLineY - 20, bline_[i].blackLineX + 20, bline_[i].blackLineY + 20, 0xffffff, TRUE);
			break;
		}
	}
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
}
