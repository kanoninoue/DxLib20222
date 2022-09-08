#include"Draw.h"
#include "DxLib.h"
#include <stdlib.h>

void Drawing::Initialize(char* key) {
	//�L�[���͗p�ϐ�
	keyBuf_ = key;
	//linesegMaX_ = 1000;
	linesegCnt_ = 0;

	bline_ = (lineseg*)malloc(linesegMaX_ * sizeof(lineseg));
	/* if (bline == NULL) {
		 return -1;
	 }*/
}
void Drawing::Update() {
	//�L�[����
	GetHitKeyStateAll(keyBuf_);
	if (keyBuf_[KEY_INPUT_1] == 1) { isPenF_ = true; }
	if (keyBuf_[KEY_INPUT_2] == 1) { isPenF_ = false; isDrag_ = false; }
	if (keyBuf_[KEY_INPUT_0] == 1) { linesegCnt_ = 0; }


	//�}�E�X���W�擾
	GetMousePoint(&posX_, &posY_);

	//�}�E�X���͏���
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		//�h���b�O���͍��W��ǉ�
		//(�O�ƍ��W�������ł��ǉ������̂ŁA�������ߖ񂵂����ꍇ�͈ړ������������ǉ�����悤�ɂ������������c)
		bline_[linesegCnt_].blackLineX = posX_;
		bline_[linesegCnt_].blackLineY = posY_;
		if (isPenF_) {
			if (isDrag_) {//�h���b�O���͐�������
				bline_[linesegCnt_].pType = PencilType::Pen;
			}
			else {//�h���b�O�J�n
				isDrag_ = true;    //�h���b�O�t���O���I���ɂ���
				bline_[linesegCnt_].pType = PencilType::Non;
			}
		}
		else {
			bline_[linesegCnt_].pType = PencilType::Eraser;
		}
		linesegCnt_++;
		//������������Ȃ��Ȃ�����g��
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
	else {//�}�E�X�̃L�[�͉�����Ă��Ȃ�
		if (isDrag_)isDrag_ = false;  //�h���b�O�t���O���I�t�ɂ���
	}
}
void Drawing::Draw() {
	//bline�z��̏���`��
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
	//�������`��
	DrawString(0, 0, "�L�[����F0=�S�폜 1=�y�� 2=�����S��", 0x0);
	if (isPenF_) {
		DrawString(0, 16, "���݂̃��[�h�F�y��", 0x0);
		DrawLine(posX_, posY_ - 10, posX_, posY_ + 10, 0x0);
		DrawLine(posX_ - 10, posY_, posX_ + 10, posY_, 0x0);
	}
	else {
		DrawString(0, 16, "���݂̃��[�h�F�����S��", 0x0);
		DrawBox(posX_ - 20, posY_ - 20, posX_ + 20, posY_ + 20, 0xffffff, TRUE);
		DrawBox(posX_ - 20, posY_ - 20, posX_ + 20, posY_ + 20, 0x0, FALSE);
	}
}
