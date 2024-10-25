/*****
 * Author: Glowstudent
 * Vending Machine
 *****/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Function library for future use
#include <consoleUtils.h>

using namespace std;

const string title = "Vending Machine";
const int width = 53;

// Functions
void clearScreen();
void resetInput();

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

void mainScreen()
{
	int userSelection;

	clearScreen();

	fullLine(width);
	printSpacer(width);
	printText(title, width, Alignment::center);
	printSpacer(width);

	printText("1) Pepsi     | $1.50   2) Coke       | $1.50", width, Alignment::left, 3);
	printText("3) Sprite    | $1.50   4) Dr. Pepper | $1.50", width, Alignment::left, 3);
	printText("5) Root Beer | $1.50   6) Water      | $1.00", width, Alignment::left, 3);
	printSpacer(width);
	printText("7) Insert Money        8) Exit", width, Alignment::left, 3);

	printSpacer(width);
	fullLine(width);

	cout << "Selection: ";
	cin >> userSelection;
}

void getScreen(int screen)
{
	switch (screen)
	{
	case 0:
		mainScreen();
		break;
	default:
		break;
	}
}

int main()
{
	cout << "\033]0;" << title << "\007";

	getScreen(0);

	return 0;
}