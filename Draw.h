#pragma once
#include"DxLib.h"
class Drawing {


public :

    void Initialize(char* key);
    void Update();
    void Draw();
    int GetDrawMode() { return DrawFlag;}

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
    int posX_, posY_;
    bool isDrag_ = false, isPenF_ = true;
    int DrawFlag = false;
    char* keyBuf_;
    
};