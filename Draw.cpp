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

void Drawing::Update(int Gamescene) {
	//キー入力
	GetHitKeyStateAll(keyBuf_);
	if (keyBuf_[KEY_INPUT_R] == 1) {
		PosBoxTopX = 0; PosBoxTopY = 0; PosBoxUnderX = 0; PosBoxUnderY = 0; PosBoxTopX2 = 0; PosBoxTopY2 = 0; PosBoxUnderX2 = 0; PosBoxUnderY2 = 0; APosBoxTopX2 = 0; APosBoxTopY2 = 0; APosBoxUnderX2 = 0; APosBoxUnderY2 = 0; BPosBoxTopX2 = 0; BPosBoxTopY2 = 0; BPosBoxUnderX2 = 0; BPosBoxUnderY2 = 0;
			//////線
			PosLineLeftX = 0; PosLineLeftY = 0; PosLineRightX = 0; PosLineLeftX2 = 0; PosLineLeftY2 = 0; PosLineRightX2 = 0; APosLineLeftX2 = 0; APosLineLeftY2 = 0; APosLineRightX2 = 0; BPosLineLeftX2 = 0; BPosLineLeftY2 = 0; BPosLineRightX2 = 0; CPosLineLeftX2 = 0; CPosLineLeftY2 = 0; CPosLineRightX2 = 0; DPosLineLeftX2 = 0; DPosLineLeftY2 = 0; DPosLineRightX2 = 0; EPosLineLeftX2 = 0; EPosLineLeftY2 = 0; EPosLineRightX2 = 0; FPosLineLeftX2 = 0; FPosLineLeftY2 = 0; FPosLineRightX2 = 0;
			//ジャンプ台
			JumpTopX = 0; JumpTopY = 0; JumpBottomX = 0; JumpbottomY = 0; AJumpTopX = 0; AJumpTopY = 0; AJumpBottomX = 0; AJumpbottomY = 0; BJumpTopX = 0; BJumpTopY = 0; BJumpBottomX = 0; BJumpbottomY = 0; CJumpTopX = 0; CJumpTopY = 0; CJumpBottomX = 0; CJumpbottomY = 0; DJumpTopX = 0; DJumpTopY = 0; DJumpBottomX = 0; DJumpbottomY = 0; EJumpTopX = 0; EJumpTopY = 0; EJumpBottomX = 0; EJumpbottomY = 0; FJumpTopX = 0; FJumpTopY = 0; FJumpBottomX = 0; FJumpbottomY = 0;
		isDrag_ = false, isPenF_ = true;
		 DrawFlag = false;
		 Drawingflag = false;
		 DrawLineFlag = false;
		 BoxNumber = 0;
		 LineNumber = 0;
		 JumpNumber = 0;
		 LineTimer = 0;
		 BoxTimer = 0;
		 JumpTimer = 0;
		 JunpFlag = false;
		 PlantFlag = false;
		linesegCnt_ = 0; }

	if (Gamescene == 2) {
		
		if (keyBuf_[KEY_INPUT_N] == 1) {
			PosBoxTopX = 0; PosBoxTopY = 0; PosBoxUnderX = 0; PosBoxUnderY = 0; PosBoxTopX2 = 0; PosBoxTopY2 = 0; PosBoxUnderX2 = 0; PosBoxUnderY2 = 0; APosBoxTopX2 = 0; APosBoxTopY2 = 0; APosBoxUnderX2 = 0; APosBoxUnderY2 = 0; BPosBoxTopX2 = 0; BPosBoxTopY2 = 0; BPosBoxUnderX2 = 0; BPosBoxUnderY2 = 0;
			//////線
			PosLineLeftX = 0; PosLineLeftY = 0; PosLineRightX = 0; PosLineLeftX2 = 0; PosLineLeftY2 = 0; PosLineRightX2 = 0; APosLineLeftX2 = 0; APosLineLeftY2 = 0; APosLineRightX2 = 0; BPosLineLeftX2 = 0; BPosLineLeftY2 = 0; BPosLineRightX2 = 0; CPosLineLeftX2 = 0; CPosLineLeftY2 = 0; CPosLineRightX2 = 0; DPosLineLeftX2 = 0; DPosLineLeftY2 = 0; DPosLineRightX2 = 0; EPosLineLeftX2 = 0; EPosLineLeftY2 = 0; EPosLineRightX2 = 0; FPosLineLeftX2 = 0; FPosLineLeftY2 = 0; FPosLineRightX2 = 0;
			//ジャンプ台
			JumpTopX = 0; JumpTopY = 0; JumpBottomX = 0; JumpbottomY = 0; AJumpTopX = 0; AJumpTopY = 0; AJumpBottomX = 0; AJumpbottomY = 0; BJumpTopX = 0; BJumpTopY = 0; BJumpBottomX = 0; BJumpbottomY = 0; CJumpTopX = 0; CJumpTopY = 0; CJumpBottomX = 0; CJumpbottomY = 0; DJumpTopX = 0; DJumpTopY = 0; DJumpBottomX = 0; DJumpbottomY = 0; EJumpTopX = 0; EJumpTopY = 0; EJumpBottomX = 0; EJumpbottomY = 0; FJumpTopX = 0; FJumpTopY = 0; FJumpBottomX = 0; FJumpbottomY = 0;
			isDrag_ = false, isPenF_ = true;
			DrawFlag = false;
			Drawingflag = false;
			DrawLineFlag = false;
			BoxNumber = 0;
			LineNumber = 0;
			JumpNumber = 0;
			LineTimer = 0;
			BoxTimer = 0;
			JumpTimer = 0;
			JunpFlag = false;
			PlantFlag = false;
			linesegCnt_ = 0;
		}
	}
	if (DrawFlag == FALSE) {
		LineTimer = 0;
		if (GetMouseInputLog2(&Button2, &posX_, &posY_, &LogType2, TRUE) == 0) {}
	}
	if (keyBuf_[KEY_INPUT_0] == 1) { linesegCnt_ = 0; }

	if (DrawFlag == false) {
		GetTimer++;
		if (keyBuf_[KEY_INPUT_P] == 1 && GetTimer >= 30) {
			DrawFlag = true; GetTimer = 0;
		}
	}
	else if (DrawFlag == true) {
		GetTimer++;
		if (JunpFlag == false) {
			PlantTimer++;
			if (keyBuf_[KEY_INPUT_O] == 1 && PlantTimer >= 30) { JunpFlag = true; PlantTimer = 0; }
		}
		if (JunpFlag == true) {
			PlantTimer++;
			if (keyBuf_[KEY_INPUT_O] == 1 && PlantTimer >= 60) {
				JunpFlag = false; PlantTimer = 0;
			}
		}
		if (keyBuf_[KEY_INPUT_P] == 1 && GetTimer >= 60) {
			DrawFlag = false; GetTimer = 0;
		}

	}
	//マウス座標取得
	GetMousePoint(&posX_, &posY_);
	if (DrawFlag == true) {
		if (JunpFlag == false) {
			//マウス入力処理
			if (GetMouseInput() & MOUSE_INPUT_LEFT) {
				//ドラッグ中は座標を追加
				//(前と座標が同じでも追加されるので、メモリ節約したい場合は移動した時だけ追加するようにした方がいい…)
				bline_[linesegCnt_].blackLineX = posX_;
				bline_[linesegCnt_].blackLineY = posY_;
				PosLineLeftX = posX_;
				PosLineLeftY = posY_;
				LineTimer++;
				if (LineTimer == 1) {
					LineNumber += 1;
				}
				if (LineNumber == 1) {
					PosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 3) {
					APosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 5) {
					BPosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 7) {
					CPosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 9) {
					DPosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 11) {
					EPosLineRightX2 = PosLineRightX;
				}
				if (LineNumber == 13) {
					FPosLineRightX2 = PosLineRightX;
				}
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
				LineTimer = 0;
				if (LineNumber == 1) {
					LineNumber = 2;
				}
				if (LineNumber == 3) {
					LineNumber = 4;
				}
				if (LineNumber == 5) {
					LineNumber = 6;
				}
				if (LineNumber == 7) {
					LineNumber = 8;
				}
				if (LineNumber == 9) {
					LineNumber = 10;
				}
				if (LineNumber == 11) {
					LineNumber = 12;
				}
				
				if (LineNumber == 13) {
					LineNumber = 14;
				}
				if (LineNumber == 2) {
					PosLineLeftX2 = PosLineLeftX;
					PosLineLeftY2 = PosLineLeftY;
				}
				if (LineNumber == 4) {
					APosLineLeftX2 = PosLineLeftX;
					APosLineLeftY2 = PosLineLeftY;
				}
				if (LineNumber == 6) {
					BPosLineLeftX2 = PosLineLeftX;
					BPosLineLeftY2 = PosLineLeftY;
				}
				
				if (LineNumber == 8) {
					CPosLineLeftX2 = PosLineLeftX;
					CPosLineLeftY2 = PosLineLeftY;
				}
				if (LineNumber == 10) {
					DPosLineLeftX2 = PosLineLeftX;
					DPosLineLeftY2 = PosLineLeftY;
				}
				
				if (LineNumber == 12) {
					EPosLineLeftX2 = PosLineLeftX;
					EPosLineLeftY2 = PosLineLeftY;
				}
				if (LineNumber == 14) {
					FPosLineLeftX2 = PosLineLeftX;
					FPosLineLeftY2 = PosLineLeftY;
				}

				DrawLineFlag = FALSE;

			}

			if (GetMouseInput() & MOUSE_INPUT_RIGHT) {
				PosBoxTopX = posX_;
				PosBoxTopY = posY_;
				BoxTimer++;
				if (BoxTimer == 1) {
					BoxNumber += 1;
				}
				if (BoxNumber == 1) {
					PosBoxUnderX2 = PosBoxUnderX;
					PosBoxUnderY2 = PosBoxUnderY;
				}
				if (BoxNumber == 3) {
					APosBoxUnderX2 = PosBoxUnderX;
					APosBoxUnderY2 = PosBoxUnderY;
				}
				if (BoxNumber == 5) {
					BPosBoxUnderX2 = PosBoxUnderX;
					BPosBoxUnderY2 = PosBoxUnderY;
				}
				Drawingflag = TRUE;
			}
			else {
				BoxTimer = 0;
				if (BoxNumber == 1) {
					BoxNumber = 2;
				}
				if (BoxNumber == 3) {
					BoxNumber = 4;
				}
				if (BoxNumber == 5) {
					BoxNumber = 6;
				}

				if (BoxNumber == 2) {
					PosBoxTopX2 = PosBoxTopX;
					PosBoxTopY2 = PosBoxTopY;
				}
				if (BoxNumber == 4) {
					APosBoxTopX2 = PosBoxTopX;
					APosBoxTopY2 = PosBoxTopY;
				}
				if (BoxNumber == 6) {
					BPosBoxTopX2 = PosBoxTopX;
					BPosBoxTopY2 = PosBoxTopY;
				}
				PosBoxUnderX = posX_;
				PosBoxUnderY = posY_;
				Drawingflag = FALSE;
			}
		}
		
		if (JunpFlag == true) {
			if(GetMouseInput() & MOUSE_INPUT_LEFT) {
				JumpTimer++;
				if (JumpTimer == 1) {
					JumpNumber += 1;
				}
				if (JumpNumber == 1) {
					JumpTopX = posX_ - 16;
					JumpTopY = posY_ - 16;
					JumpBottomX = posX_ + 16;
					JumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 2) {
					AJumpTopX = posX_ - 16;
					AJumpTopY = posY_ - 16;
					AJumpBottomX = posX_ + 16;
					AJumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 3) {
					BJumpTopX = posX_ - 16;
					BJumpTopY = posY_ - 16;
					BJumpBottomX = posX_ + 16;
					BJumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 4) {
					CJumpTopX = posX_ - 16;
					CJumpTopY = posY_ - 16;
					CJumpBottomX = posX_ + 16;
					CJumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 5) {
					DJumpTopX = posX_ - 16;
					DJumpTopY = posY_ - 16;
					DJumpBottomX = posX_ + 16;
					DJumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 6) {
					EJumpTopX = posX_ - 16;
					EJumpTopY = posY_ - 16;
					EJumpBottomX = posX_ + 16;
					EJumpbottomY = posY_ + 16;
				}
				if (JumpNumber == 7) {
					FJumpTopX = posX_ - 16;
					FJumpTopY = posY_ - 16;
					FJumpBottomX = posX_ + 16;
					FJumpbottomY = posY_ + 16;
				}
				PlantFlag = true;
			}
			else { JumpTimer = 0; PlantFlag = false; }
		}
	}
}
void Drawing::Draw(int Gamescene) {
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
	if (Gamescene >= 2) {
		if (DrawLineFlag == TRUE) {
			DrawLine(PosLineLeftX, PosLineLeftY, PosLineRightX, PosLineLeftY, 0xff0000, true);
		}

		if (LineNumber >= 2) {
			DrawLine(PosLineLeftX2, PosLineLeftY2, PosLineRightX2, PosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 4) {
			DrawLine(APosLineLeftX2, APosLineLeftY2, APosLineRightX2, APosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 6) {
			DrawLine(BPosLineLeftX2, BPosLineLeftY2, BPosLineRightX2, BPosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 8) {
			DrawLine(CPosLineLeftX2, CPosLineLeftY2, CPosLineRightX2, CPosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 10) {
			DrawLine(DPosLineLeftX2, DPosLineLeftY2, DPosLineRightX2, DPosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 12) {
			DrawLine(EPosLineLeftX2, EPosLineLeftY2, EPosLineRightX2, EPosLineLeftY2, 0xff0000, true);
		}
		if (LineNumber >= 14) {
			DrawLine(FPosLineLeftX2, FPosLineLeftY2, FPosLineRightX2, FPosLineLeftY2, 0xff0000, true);
		}



		if (Drawingflag == TRUE) {
			DrawBox(PosBoxTopX, PosBoxTopY, PosBoxUnderX, PosBoxUnderY, 0xff00ff, true);
		}
		if (BoxNumber >= 2) {
			DrawBox(PosBoxTopX2, PosBoxTopY2, PosBoxUnderX2, PosBoxUnderY2, 0xff00ff, true);
		}
		if (BoxNumber >= 4) {
			DrawBox(APosBoxTopX2, APosBoxTopY2, APosBoxUnderX2, APosBoxUnderY2, 0xff00ff, true);
		}
		if (BoxNumber >= 6) {
			DrawBox(BPosBoxTopX2, BPosBoxTopY2, BPosBoxUnderX2, BPosBoxUnderY2, 0xff00ff, true);
		}



		if (JunpFlag == TRUE) {
			DrawBox(posX_ - 16, posY_ - 16, posX_ + 16, posY_ + 16, 0x0000ff, true);
		}
		if (JumpNumber >= 1) {
			DrawBox(JumpTopX, JumpTopY, JumpBottomX, JumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 2) {
			DrawBox(AJumpTopX, AJumpTopY, AJumpBottomX, AJumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 3) {
			DrawBox(BJumpTopX, BJumpTopY, BJumpBottomX, BJumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 4) {
			DrawBox(CJumpTopX, CJumpTopY, CJumpBottomX, CJumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 5) {
			DrawBox(DJumpTopX, DJumpTopY, DJumpBottomX, DJumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 6) {
			DrawBox(EJumpTopX, EJumpTopY, EJumpBottomX, EJumpbottomY, 0x0000ff, true);
		}
		if (JumpNumber >= 7) {
			DrawBox(FJumpTopX, FJumpTopY, FJumpBottomX, FJumpbottomY, 0x0000ff, true);
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

		DrawFormatString(25, 50, 0xff00ff, "mousex:%d", CJumpTopX, true);
		DrawFormatString(25, 75, 0xff00ff, "mousey:%d", CJumpTopY, true);
		DrawFormatString(25, 100, 0xff00ff, "mousex1:%d", CJumpBottomX, true);
		DrawFormatString(25, 125, 0xff00ff, "mousey1:%d", JumpbottomY, true);
		DrawFormatString(25, 150, 0xff00ff, "posX:%d", posX_, true);
		DrawFormatString(25, 175, 0xff00ff, "posy:%d", posY_, true);
		DrawFormatString(25, 200, 0xff00ff, "drawflag:%d", JumpNumber, true);
		DrawFormatString(25, 225, 0xff00ff, "posy1:%d", JumpBottomX, true);
	}
}
	
 