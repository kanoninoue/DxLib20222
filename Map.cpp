#include "Map.h"

Map::Map() {
	BlockSize = 32;
	block = LoadGraph("block.png");
}

Map::~Map() {

}

void Map::Update() {
   

}

void Map::Draw(int gamescene) {
	if (gamescene == 2) {
		for (int y = 0; y < 23; y++) {
			for (int x = 0; x < 47; x++) {
				if (tutorialMap[y][x] == 1) {
					DrawGraph(x * BlockSize, y * BlockSize, block, true);
				}
			}
		}
	}
	if (gamescene == 3) {
		for (int y = 0; y < 23; y++) {
			for (int x = 0; x < 47; x++) {
				if (PlayMap[y][x] == 1) {
					DrawGraph(x * BlockSize, y * BlockSize, block, true);
				}
			}
		}
	}
}