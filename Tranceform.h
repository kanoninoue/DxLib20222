#pragma once
struct PlayerTranceform {
	int x;
	int y;
	int radius;
	int speed;
};

class Tranceform {
protected:
	PlayerTranceform playertranceform;
public:
	PlayerTranceform Gettranceform() {
		return playertranceform;
	}
};