#include "Board.h"

const int tab[418] = {  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
						0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,
						0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

const int tab2[396] = {	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
						0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
						0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,
						0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
						0,1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,
						0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
						0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
						0,1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
						0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

const int tab3[169] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,1,1,1,0,0,1,1,0,0,0,0,
						0,0,1,1,0,1,0,1,0,1,1,1,0,
						0,0,1,1,1,0,0,1,1,1,1,1,0,
						0,1,0,1,0,1,0,1,0,1,0,1,0,
						0,1,1,1,1,0,1,0,1,0,1,0,0,
						0,0,0,0,0,1,1,1,0,0,0,0,0,
						0,0,1,0,1,0,1,0,1,1,1,1,0,
						0,1,0,1,0,1,0,1,0,1,0,1,0,
						0,1,1,1,1,1,0,0,1,1,1,0,0,
						0,1,1,1,0,1,0,1,0,1,1,0,0,
						0,0,0,0,1,1,0,0,1,1,1,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0 };

const int tab4[126] = { 0,0,0,0,0,0,0,0,0,
						0,0,0,0,1,0,0,0,0,
						0,0,0,1,0,1,0,0,0,
						0,0,1,0,1,0,1,0,0,
						0,1,0,1,0,1,0,1,0,
						0,1,0,1,0,1,0,1,0,
						0,0,1,0,1,0,1,0,0,
						0,1,0,1,0,1,0,1,0,
						0,1,0,1,0,1,0,1,0,
						0,0,1,0,1,0,1,0,0,
						0,1,0,1,0,1,0,1,0,
						0,1,0,1,0,1,0,1,0,
						0,0,1,0,1,0,1,0,0,
						0,0,0,0,0,0,0,0,0 };

const int tab5[56] = {	0,0,0,0,0,0,0,
						0,0,1,1,1,0,0,
						0,1,0,0,0,1,0,
						0,1,0,1,0,1,0,
						0,1,0,0,0,1,0,
						0,0,1,0,1,0,0,
						0,0,0,1,0,0,0,
						0,0,0,0,0,0,0 };

Board::Board(int size) : fieldSize(size)
{
}


Board::~Board()
{
}


void Board::draw(sf::RenderWindow & window)
{
	for (int i = 1; i < sizeY+1; i++)
	{
		for (int j = 1; j < sizeX+1; j++)
		{
			grid[i][j].draw(window);
		}
	}
}

void Board::nextStep()
{
	generation++;
	copyGrid();
	int alive, i, j, n;
	int neighbours[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

	if (wrap) {
		for (i = 1; i < sizeY + 1; i++) {
			gridCopy[i][0] = gridCopy[i][sizeX];
			gridCopy[i][sizeX+1] = gridCopy[i][1];
		}

		for (i = 1; i < sizeX + 1; i++) {
			gridCopy[0][i] = gridCopy[sizeY][i];
			gridCopy[sizeY+1][i] = gridCopy[1][i];
		}
		gridCopy[0][0] = gridCopy[sizeY][sizeX];
		gridCopy[sizeY+1][sizeX+1] = gridCopy[1][1];
		gridCopy[0][sizeX + 1] = gridCopy[sizeY][1];
		gridCopy[sizeY + 1][0] = gridCopy[1][sizeX];
	}

	for (i = 1; i < sizeY+1; i++)	{
		for (j = 1; j < sizeX+1; j++)	{
			alive = 0;
			for (n = 0; n < 8; n++) {
				if (gridCopy[i + neighbours[n][0]][j + neighbours[n][1]]) {
					++alive;
				}
			}

			if (alive < 2) {
				grid[i][j] = false;
			}
			else if (alive == 3) {
				grid[i][j] = true;
			}
			else if (alive > 3)	{
				grid[i][j] = false;
			}
		}
	}
}

void Board::changeFieldState(int x, int y)
{
	if (grid[y][x]) {
		grid[y][x] = false;
	}
	else {
		grid[y][x] = true;
	}
}

void Board::initialize(int Y, int X)
{
		sizeX = X;
		sizeY = Y;
		for (int i = 0; i < sizeY+2; i++) {
			std::vector<Field> tmp;
			for (int j = 0; j < sizeX+2; j++) {
				Field field(j, i, fieldSize);
				tmp.push_back(field);
			}
			grid.push_back(tmp);
		}
}

void Board::randomize(int n)
{
	srand(time(NULL));
	int randSeedV, randSeedH;
	int i = 0, j = 0;

	if (n < sizeX * sizeY) {
		while (j < n)
		{
			i++;
			randSeedV = rand() % sizeY + 1;
			randSeedH = rand() % sizeX + 1;
			if (!grid[randSeedV][randSeedH]){
				grid[randSeedV][randSeedH] = true;
				j++;
			}
			if (i > 250000) { return; }
		}
	}
}

void Board::patterns(int pattern, int x, int y)
{
	int n = 0;

	if (x<1 || y<1 || x>sizeX || y>sizeY) return;

	switch (pattern) {
	case 1:
		if (sizeX < x + 38 || sizeY < y + 11) break;
		for (int j = 0; j < 11; j++) {
			for (int i = 0; i < 38; i++) {
				grid[y + j][x + i] = tab[n];
				n++;
			}
		}
		break;
	case 2:
		if (sizeX < x+35 || sizeY < y+11) break;
		for (int j = 0; j < 11; j++) {
			for (int i = 0; i < 35; i++) {
				grid[y + j][x + i] = tab2[n];
				n++;
			}
		}
		break;
	case 3:
		if (sizeX < x + 13 || sizeY < y + 13) break;
		for (int j = 0; j < 13; j++) {
			for (int i = 0; i < 13; i++) {
				grid[y + j][x + i] = tab3[n];
				n++;
			}
		}
		break;
	case 4:
		if (sizeX < x + 9 || sizeY < y + 14) break;
		for (int j = 0; j < 14; j++) {
			for (int i = 0; i < 9; i++) {
				grid[y + j][x + i] = tab4[n];
				n++;
			}
		}
		break;
	case 5:
		if (sizeX < x + 7 || sizeY < y + 8) break;
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 7; i++) {
				grid[y + j][x + i] = tab5[n];
				n++;
			}
		}
		break;
	case 6:  //diamond
		if (sizeX < x + 3 || sizeY < y + 4) break;
		grid[y][x + 1] =
			grid[y + 1][x] = grid[y + 1][x + 2] =
			grid[y + 2][x] = grid[y + 2][x + 2] =
			grid[y + 3][x + 1] = true;
		break;
	}
}

void Board::reset()
{
	generation = 0;
	for (int i = 1; i < sizeY + 1; i++) {
		for (int j = 1; j < sizeX + 1; j++) {
			grid[i][j].reset();
		}
	}
}
