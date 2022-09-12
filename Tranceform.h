#pragma once
struct PlayerTranceform {
	int x;
	int y;
	int radius;
	int speed;
	int gravity;
	int oldx;
	int oldy;
    int blocksize;
    int rightTopX;
    int rightTopY;
    int leftTopY;
    int leftTopX;
    int rightBottomX;
    int rightBottomY;
    int leftBottomX;
    int leftBottomY;
    int rightTopoldX;
    int rightTopoldY;
    int leftTopoldY;
    int leftTopoldX;
    int rightBottomoldX;
    int rightBottomoldY;
    int leftBottomoldX;
    int leftBottomoldY;
    int GoalX;
    int GoalY;

};

class Tranceform {
protected:
	PlayerTranceform playertranceform;
public:
	PlayerTranceform Gettranceform() {
		return playertranceform;
	}
};