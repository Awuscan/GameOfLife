#include "Board.h"

Board::Board()
{
}


Board::~Board()
{
}

void Board::initialize()
{
	int Y, X;

	{
		std::cout << "Podaj rozmiar horyzontalny: ";
		std::cin >> X;

		std::cout << "Podaj rozmiar wertykalny: ";
		std::cin >> Y;
	} while (this->initialize(Y, X) == false);

}

void Board::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			grid[i][j].draw(window);
		}
	}
}

void Board::nextStep()
{
	copyGrid();

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			int alive = 0;
			for (int c = -1; c < 2; c++)
			{
				for (int d = -1; d < 2; d++)
				{
					int a = i + c, b = j + d;
					if (!(c == 0 && d == 0) && ((a >= 0 && a < sizeY) && (b >= 0 && b < sizeX)))
					{
						if (gridCopy[a][b].readState())
						{
							++alive;
						}
					}
				}
			}

			if (alive < 2)
			{
				grid[i][j].changeState(false);
			}
			else if (alive == 3)
			{
				grid[i][j].changeState(true);
			}
			else if (alive > 3)
			{
				grid[i][j].changeState(false);
			}
		}
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



		for (int i = 0; i < sizeY; i++) {
			std::vector<Field> tmp;
			for (int j = 0; j < sizeX; j++) {
				Field field(j, i);
				tmp.push_back(field);
			}
			grid.push_back(tmp);
		}

		return true;
	}
}

void Board::fillOut()
{
}

void Board::randomize()
{
	srand(time(NULL));
	int randSeedV, randSeedH;
	int i,n = 0;

	std::cout << "Podaj: ";
	std::cin >> i;

	while (n < i)
	{
		randSeedV = rand() % sizeY;
		randSeedH = rand() % sizeX;
		if (!grid[randSeedV][randSeedH].readState())
		{
			grid[randSeedV][randSeedH].changeState(true);
			n++;
		}
	}
}

void Board::copyGrid()
{
	gridCopy = grid;
}
