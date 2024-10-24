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

void centerText(string text, int width)
{
	int left = ((width + text.length()) / 2) - 1;
	int right = width - left - 2;
	cout << "*" << setw(left) << text << string(right, ' ') << "*" << endl;
}

int main()
{
	cout << "\033]0;" << title << "\007";

	clearScreen();

	cout << string(53, '*') << endl;
	cout << "*" << setw(52) << "*" << endl;
	centerText(title, 53);
	centerText("by Glowstudent", 53);
	centerText("This is a test program", 53);
	cout << "*" << setw(52) << "*" << endl;
	cout << string(53, '*') << endl;

	return 0;
}