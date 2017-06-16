#include "Game.h"

int main() {
	int width = 70;
	int height = 20;
	int numSteps = 1000;
	
	Game game(width, height);
	
	//game.inputGrid();
	game.randomGrid();
	
	game.output();
	
	for (int i = 0; i < numSteps; ++i) {
		while (getchar() != '\n') {
		}
		
		game.takeStep();
		
		game.output();
	}
	
	return 0;
}