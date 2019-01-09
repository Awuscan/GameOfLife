#include "Board.h"

Board::Board(int size) : fieldSize(size), generation(0)
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
	int alive,i,j,n;
	int neighbours[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

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

bool Board::initialize(int Y, int X)
{
	if (X < 1 || Y < 1)
	{
		std::cout << std::endl;
		std::cout << "Niepoprawne dane!" << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		sizeX = X;
		sizeY = Y;

		std::cout << std::endl;
		std::cout << "Stworzono plansze." << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < sizeY+2; i++) {
			std::vector<Field> tmp;
			for (int j = 0; j < sizeX+2; j++) {
				Field field(j, i, fieldSize);
				tmp.push_back(field);
			}
			grid.push_back(tmp);
		}

		return true;
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
			if (!grid[randSeedV][randSeedH])
			{
				grid[randSeedV][randSeedH] = true;
				j++;
			}
			if (i > 250000) { return; }
		}
	}
}