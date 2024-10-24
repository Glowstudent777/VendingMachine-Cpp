/*****
 * Author: Glowstudent
 * Vending Machine
 *****/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const string title = "Vending Machine";
const int width = 53;

const string red("\033[0;31m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");

const string reset("\033[0m");

const string red_BG("\033[0;41m");
const string green_BG("\033[1;42m");
const string yellow_BG("\033[1;43m");
const string cyan_BG("\033[0;46m");
const string magenta_BG("\033[0;45m");

enum class Direction
{
	left,
	center,
	right
};

// Functions
void clearScreen();
void resetInput();
void printText(string text, int width, Direction dir, int offset);
void printSpacer(int width);
void fullLine(int width);

void clearScreen()
{
	// Clear the screen
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#elif defined(__linux__)
	system("clear");
#elif defined(__APPLE__)
	system("clear");
#endif
}

void resetInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printText(string text, int width, Direction dir, int offset = 0)
{
	int left = 0;
	int right = 0;

	switch (dir)
	{
	case Direction::left:
		left = offset;
		right = width - text.length() - left - 2;
		break;
	case Direction::center:
		left = ((width - text.length()) / 2) - 1;
		right = width - text.length() - left - 2;
		break;
	case Direction::right:
		right = offset;
		left = width - text.length() - right - 2;
		break;
	}

	cout << "*" << string(left, ' ') << text << string(right, ' ') << "*" << endl;
}

void printSpacer(int width)
{
	cout << "*" << setw(width - 1) << "*" << endl;
}

void fullLine(int width)
{
	cout << string(width, '*') << endl;
}

int main()
{
	cout << "\033]0;" << title << "\007";

	clearScreen();

	fullLine(width);
	printSpacer(width);

	printText(title, width, Direction::center);

	printSpacer(width);
	fullLine(width);

	return 0;
}