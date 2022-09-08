#pragma once

class Drawing {
public :

    void Initialize(char* key);
    void Update();
    void Draw();

private:
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
    int linesegMaX_ = 1000;
    int linesegCnt_ = 0;
    int posX_, posY_;
    bool isDrag_ = false, isPenF_ = true;
    char* keyBuf_;
};