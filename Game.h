#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Game {
public:
	Game(int width, int height);
	
	void makeGrid();
	
	void inputGrid();
	
	void randomGrid();
	
	void takeStep();
	
	void output();
	
private:
	struct Point {
		bool occupied;
	};
	
	void makeGrid(vector<vector<Point>> &grid);
	
	int width;
	int height;
	int step;
	
	vector<vector<Point>> grid;
};

#endif