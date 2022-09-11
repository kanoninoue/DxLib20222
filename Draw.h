#pragma once
#include"DxLib.h"
class Drawing {


public :

    void Initialize(char* key);
    void Update();
    void Draw();
    int GetDrawMode() { return DrawFlag;}
    int GetPlantMode() { return JunpFlag; }
    int GetTopPosX() {return PosBoxUnderX2;}
    int GetTopUnderX() { return PosBoxTopX2; }
    int GetTopPosY() { return PosBoxUnderY2; }
    int GetLineLeftX() { return PosLineLeftX2; }
    int GetLineLeftY() { return PosLineLeftY2; }
    int GetLineRightX() { return PosLineRightX2; }
    int GetJumpPosX() { return JumpTopX; }
    int GetJumpPosY() { return JumpTopY; }
    int GetJumpbottomX() { return JumpBottomX; }
    //2å¬ñ⁄
    int AGetTopPosX() { return APosBoxUnderX2; }
    int AGetTopUnderX() { return APosBoxTopX2; }
    int AGetTopPosY() { return APosBoxUnderY2; }
    int AGetLineLeftX() { return APosLineLeftX2; }
    int AGetLineRightX() { return APosLineRightX2; }
    int AGetLineLeftY() { return APosLineLeftY2; }
    int AGetJumpPosX() { return AJumpTopX; }
    int AGetJumpbottomX() { return AJumpBottomX; }
    int AGetJumpPosY() { return AJumpTopY; }
    //3å¬ñ⁄
    int BGetTopPosX() { return BPosBoxUnderX2; }
    int BGetTopUnderX() { return BPosBoxTopX2; }
    int BGetTopPosY() { return BPosBoxUnderY2; }
    int BGetLineLeftX() { return BPosLineLeftX2; }
    int BGetLineRightX() { return BPosLineRightX2; }
    int BGetLineLeftY() { return BPosLineLeftY2; }
    int BGetJumpPosX() { return BJumpTopX; }
    int BGetJumpbottomX() { return BJumpBottomX; }
    int BGetJumpPosY() { return BJumpTopY; }
    enum PencilType
    {
        Non,
        Pen,
        Eraser,
    };

    struct lineseg
    {
        int blackLineX;
        int blackLineY;
        PencilType pType;
    };
    lineseg* bline_;
    int GetTimer = 0;
    int PlantTimer = 0;
    int linesegMaX_ = 1000;
    int linesegCnt_ = 0;
    
    int posX_, posY_,
        //î†
        PosBoxTopX, PosBoxTopY, PosBoxUnderX, PosBoxUnderY, PosBoxTopX2, PosBoxTopY2, PosBoxUnderX2, PosBoxUnderY2, APosBoxTopX2, APosBoxTopY2, APosBoxUnderX2, APosBoxUnderY2, BPosBoxTopX2, BPosBoxTopY2, BPosBoxUnderX2, BPosBoxUnderY2,
        //////ê¸
        PosLineLeftX, PosLineLeftY, PosLineRightX, PosLineLeftX2, PosLineLeftY2, PosLineRightX2, APosLineLeftX2, APosLineLeftY2, APosLineRightX2, BPosLineLeftX2, BPosLineLeftY2, BPosLineRightX2,
        //ÉWÉÉÉìÉvë‰
        JumpTopX, JumpTopY, JumpBottomX, JumpbottomY, AJumpTopX, AJumpTopY, AJumpBottomX, AJumpbottomY, BJumpTopX, BJumpTopY, BJumpBottomX, BJumpbottomY;
    bool isDrag_ = false, isPenF_ = true;
    int DrawFlag = false;
    int Drawingflag = false;
    int DrawLineFlag = false;
    int BoxNumber = 0;
    int LineNumber = 0;
    int JumpNumber = 0;
    int LineTimer = 0;
    int BoxTimer = 0;
    int JumpTimer = 0;
    int JunpFlag = false;
    int PlantFlag = false;
    int Button, LogType, Button2, LogType2;
    char* keyBuf_;
    
};