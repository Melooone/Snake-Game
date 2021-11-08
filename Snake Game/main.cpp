#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;

	x = width / 2;
	y = height / 2;

	fruitX = rand() % width;
	fruitY = rand() % width;

	score = 0;
}

void Draw()
{
	system("cls");
	
	//Print top of the screen
	for (int i = 0; i < width + 2; i++)
	{ cout << "#"; }
	cout << endl;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//draw edge and blankspace
			if (j == 0)
			{ cout << "#"; }

			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}
			else
			{
				cout << " ";
			}

			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	//Print bottom of the screen
	for (int i = 0; i < width + 2; i++)
	{ cout << "#"; }
	cout << endl;

}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': dir = UP; break;
		case 'a': dir = LEFT; break;
		case 's': dir = DOWN; break;
		case 'd': dir = RIGHT; break;
		case 'x': gameOver = true; break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	default: break;
	}

	if (x == width || x < 0 || y == height || y < 0 )
	{ gameOver = true; }
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	return 0;
}