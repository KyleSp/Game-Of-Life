#include "Game.h"

Game::Game(int width, int height) : width(width), height(height), step(0) {
	
}

void Game::makeGrid() {
	makeGrid(this->grid);
}

void Game::makeGrid(vector<vector<Point>> &grid) {
	vector<Point> row;
	Point point;
	point.occupied = false;
	
	for (int i = 0; i < height; ++i) {
		row.clear();
		for (int j = 0; j < width; ++j) {
			row.push_back(point);
		}
		grid.push_back(row);
	}
}

void Game::inputGrid() {
	makeGrid();
	
	string line;
	vector<vector<Point>> miniGrid;
	vector<Point> row;
	
	Point pOcc, pEmpt;
	pOcc.occupied = true;
	pEmpt.occupied = false;
	
	while (cin >> line) {
		row.clear();
		
		for (int i = 0; i < (int) line.length(); ++i) {
			if (line[i] == '*') {
				row.push_back(pOcc);
			} else {
				row.push_back(pEmpt);
			}
		}
		
		miniGrid.push_back(row);
	}
	
	//add minigrid to full grid
	int mX = width / 2;
	int mY = height / 2;
	int sizeX = (int) line.length();
	int sizeY = (int) miniGrid.size();
	
	for (int i = 0; i < sizeY; ++i) {
		for (int j = 0; j < sizeX; ++j) {
			//cout << mX + j - sizeX / 2 << "," << mY + i - sizeY / 2 << ": " << miniGrid[i][j].occupied << "\n";
			
			grid[mY + i - sizeY / 2][mX + j - sizeX / 2].occupied = miniGrid[i][j].occupied;
		}
	}
}

void Game::randomGrid() {
	makeGrid();
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			bool r = rand() % 2;
			grid[i][j].occupied = r;
		}
	}
}

void Game::takeStep() {
	++step;
	
	int numNeighbors = 0;
	
	vector<vector<Point>> newGrid;
	makeGrid(newGrid);
	
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			numNeighbors = 0;
			
			//get number of neighbors
			for (int i = -1; i < 2; ++i) {
				for (int j = -1; j < 2; ++j) {
					if (!(i == 0 && j == 0) && i + y >= 0 && i + y < height && j + x >= 0 && j + x < width) {
						if (grid[i + y][j + x].occupied) {
							++numNeighbors;
						}
					}
				}
			}
			
			//underpopulation - dies
			if (numNeighbors < 2) {
				newGrid[y][x].occupied = false;
			}
			
			//overpopulation - dies
			if (numNeighbors > 3) {
				newGrid[y][x].occupied = false;
			}
			
			//continue living
			if ((grid[y][x].occupied) && (numNeighbors == 2 || numNeighbors == 3)) {
				newGrid[y][x].occupied = true;
			}
			
			//reproduction - alive
			if (numNeighbors == 3) {
				newGrid[y][x].occupied = true;
			}
		}
	}
	
	//copy over new grid
	grid = newGrid;
}

void Game::output() {
	cout << "step: " << step << "\n";
	cout << "=========================\n";
	
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (grid[i][j].occupied) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}
	
	cout << "=========================\n";
}