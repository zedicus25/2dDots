#include <iostream>
#include <iomanip>
#include "c_Point2D.h"
using namespace std;
void createArray(c_Point2D*& arr, int size);
void deleteArray(c_Point2D*& arr);
void sortY(c_Point2D*& arr, int size);
void printCoord(c_Point2D* arr, int size);
void randPoints(c_Point2D*& arr, int size);
void printPoints(c_Point2D* arr, int size);
int generateY(c_Point2D* arr, int size);
int generateX(c_Point2D* arr, int size);
int main()
{
	srand(time(NULL));
	c_Point2D* points;
	const int size = 10;
	createArray(points, size);
	randPoints(points, size);
	sortY(points, size);
	printCoord(points, size);
	printPoints(points, size);
}

void createArray(c_Point2D*& arr, int size)
{
	arr = new c_Point2D[size];
}

void deleteArray(c_Point2D*& arr)
{
	delete[] arr;
}

void sortY(c_Point2D*& arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = size-1; j > 0; j--)
		{
			if (arr[j].getY() < arr[j - 1].getY()) {
				int tmpX = arr[j].getX();
				int tmpY = arr[j].getY();
				arr[j].setX(arr[j - 1].getX());
				arr[j].setY(arr[j - 1].getY());
				arr[j - 1].setX(tmpX);
				arr[j - 1].setY(tmpY);
			}
		}
	}
}

void printCoord(c_Point2D* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "X: " << arr[i].getX() << " Y: " << arr[i].getY()<<endl;
	}
}

void randPoints(c_Point2D*& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int x = generateX(arr, size);
		int y = generateY(arr,size);
		arr[i].setX(x);
		arr[i].setY(y);
	}
}

void printPoints(c_Point2D* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0) {
			for (int j = 1; j < arr[i].getY(); j++)
			{
				cout << endl;
			}
			cout << setw(arr[i].getX());
			cout << "@\n";
		}
		else {
			for (int j = 1; j <arr[i].getY() - arr[i-1].getY(); j++)
			{
				cout << endl;
			}
			cout << setw(arr[i].getX());
			cout << "@\n";
		}
		
	}
}

int generateY(c_Point2D* arr, int size)
{
	int y;
	for(;;)
	{
		bool dontRepeat = true;
		y = 1 + rand() % 25;
		for (int i = 0; i < size; i++)
		{
			if (y == arr[i].getY()) {
				dontRepeat = false;
				break;
			}
		}
		if (dontRepeat) {
			return y;
		}
	}
}

int generateX(c_Point2D* arr, int size)
{
	int x;
	for (;;)
	{
		bool dontRepeat = true;
		x = 1 + rand() % 35;
		for (int i = 0; i < size; i++)
		{
			if (x == arr[i].getX()) {
				dontRepeat = false;
				break;
			}
		}
		if (dontRepeat) {
			return x;
		}
	}
}
