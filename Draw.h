#pragma once
#include"DxLib.h"
class Drawing {


public :

    void Initialize(char* key);
    void Update();
    void Draw();
    int GetDrawMode() { return DrawFlag;}
    int GetTopPosX() {return PosBoxUnderX2;}
    int GetTopUnderX() { return PosBoxTopX2; }
    int GetTopPosY() { return PosBoxUnderY2; }
    int GetLineLeftX() { return PosLineLeftX2; }
    int GetLineLeftY() { return PosLineLeftY2; }
    int GetLineRightX() { return PosLineRightX2; }
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
    int linesegMaX_ = 1000;
    int linesegCnt_ = 0;
    
    int posX_, posY_, PosBoxTopX, PosBoxTopY, PosBoxUnderX, PosBoxUnderY, PosBoxTopX2, PosBoxTopY2, PosBoxUnderX2, PosBoxUnderY2, PosLineLeftX, PosLineLeftY, PosLineLeftY2, PosLineLeftX2, PosLineRightX, PosLineRightX2;
    bool isDrag_ = false, isPenF_ = true;
    int DrawFlag = false;
    int Drawingflag = false;
    int DrawLineFlag = false;
    int Button, LogType, Button2, LogType2;
    char* keyBuf_;
    
};