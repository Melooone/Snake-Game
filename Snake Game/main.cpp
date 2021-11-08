#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, tailX[10], tailY[10], nTail;
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
	Sleep(10);
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
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{	
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
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
	cout << "Score: " << score << endl;

}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': if (dir != DOWN) { dir = UP; } break;
		case 'a': if (dir != RIGHT) { dir = LEFT; } break;
		case 's': if (dir != UP) { dir = DOWN; } break;
		case 'd': if (dir != LEFT) { dir = RIGHT; } break;
		case 'x': dir = STOP; break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i <= nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

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

	//if (x > width || x < 0 || y > height || y < 0 )
	//{ gameOver = true; }

	if (x >= width)
	{ x = 0; }
	else if (x < 0)
	{ x = width - 1; }

	if (y >= height)
	{ y = 0; }
	else if (y < 0)
	{ y = height - 1; }

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}
	}

	if (x == fruitX && y == fruitY) {
		fruitX = rand() % width;
		fruitY = rand() % width;
		score++;
		nTail++;
	}
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