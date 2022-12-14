#pragma once
#include"DxLib.h"
class Drawing {


public :

    void Initialize(char* key);
    void Update(int Gamescene);
    void Draw(int Gamescene);
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
    //2??
    int AGetTopPosX() { return APosBoxUnderX2; }
    int AGetTopUnderX() { return APosBoxTopX2; }
    int AGetTopPosY() { return APosBoxUnderY2; }
    int AGetLineLeftX() { return APosLineLeftX2; }
    int AGetLineRightX() { return APosLineRightX2; }
    int AGetLineLeftY() { return APosLineLeftY2; }
    int AGetJumpPosX() { return AJumpTopX; }
    int AGetJumpbottomX() { return AJumpBottomX; }
    int AGetJumpPosY() { return AJumpTopY; }
    //3??
    int BGetTopPosX() { return BPosBoxUnderX2; }
    int BGetTopUnderX() { return BPosBoxTopX2; }
    int BGetTopPosY() { return BPosBoxUnderY2; }
    int BGetLineLeftX() { return BPosLineLeftX2; }
    int BGetLineRightX() { return BPosLineRightX2; }
    int BGetLineLeftY() { return BPosLineLeftY2; }
    int BGetJumpPosX() { return BJumpTopX; }
    int BGetJumpbottomX() { return BJumpBottomX; }
    int BGetJumpPosY() { return BJumpTopY; }
    //4??
    int CGetLineLeftX() { return CPosLineLeftX2; }
    int CGetLineLeftY() { return CPosLineLeftY2; }
    int CGetLineRightX() { return CPosLineRightX2; }
    int CGetJumpPosX() { return CJumpTopX; }
    int CGetJumpPosY() { return CJumpTopY; }
    int CGetJumpbottomX() { return CJumpBottomX; }
    //5??
    int DGetLineLeftX() { return DPosLineLeftX2; }
    int DGetLineLeftY() { return DPosLineLeftY2; }
    int DGetLineRightX() { return DPosLineRightX2; }
    int DGetJumpPosX() { return DJumpTopX; }
    int DGetJumpPosY() { return DJumpTopY; }
    int DGetJumpbottomX() { return DJumpBottomX; }
    //6??
    int EGetLineLeftX() { return EPosLineLeftX2; }
    int EGetLineLeftY() { return EPosLineLeftY2; }
    int EGetLineRightX() { return EPosLineRightX2; }
    int EGetJumpPosX() { return EJumpTopX; }
    int EGetJumpPosY() { return EJumpTopY; }
    int EGetJumpbottomX() { return EJumpBottomX; }
    //7??
    int FGetLineLeftX() { return FPosLineLeftX2; }
    int FGetLineLeftY() { return FPosLineLeftY2; }
    int FGetLineRightX() { return FPosLineRightX2;}
    int FGetJumpPosX() { return FJumpTopX; }
    int FGetJumpPosY() { return FJumpTopY; }
    int FGetJumpbottomX() { return FJumpBottomX; }

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
        //??
        PosBoxTopX, PosBoxTopY, PosBoxUnderX, PosBoxUnderY, PosBoxTopX2, PosBoxTopY2, PosBoxUnderX2, PosBoxUnderY2, APosBoxTopX2, APosBoxTopY2, APosBoxUnderX2, APosBoxUnderY2, BPosBoxTopX2, BPosBoxTopY2, BPosBoxUnderX2, BPosBoxUnderY2,
        //////??
        PosLineLeftX, PosLineLeftY, PosLineRightX, PosLineLeftX2, PosLineLeftY2, PosLineRightX2, APosLineLeftX2, APosLineLeftY2, APosLineRightX2, BPosLineLeftX2, BPosLineLeftY2, BPosLineRightX2, CPosLineLeftX2, CPosLineLeftY2, CPosLineRightX2, DPosLineLeftX2, DPosLineLeftY2, DPosLineRightX2, EPosLineLeftX2, EPosLineLeftY2, EPosLineRightX2, FPosLineLeftX2, FPosLineLeftY2, FPosLineRightX2,
        //?W?????v??
        JumpTopX, JumpTopY, JumpBottomX, JumpbottomY, AJumpTopX, AJumpTopY, AJumpBottomX, AJumpbottomY, BJumpTopX, BJumpTopY, BJumpBottomX, BJumpbottomY, CJumpTopX, CJumpTopY, CJumpBottomX, CJumpbottomY, DJumpTopX, DJumpTopY, DJumpBottomX, DJumpbottomY, EJumpTopX, EJumpTopY, EJumpBottomX, EJumpbottomY, FJumpTopX, FJumpTopY, FJumpBottomX, FJumpbottomY;
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