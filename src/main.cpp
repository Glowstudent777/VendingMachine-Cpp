/*****
 * Author: Glowstudent
 * Vending Machine
 *****/

#include <iostream>
#include <iomanip>
#include <string>
#include <set>

// Function library for future use
#include <consoleUtils.h>

using namespace std;

const string title = "Vending Machine";
const int width = 53;
const set acceptedInput = set<float>{0, 0.01, 0.05, 0.10, 0.25, 1, 2, 5, 10, 20};

int balance = 0;

// Functions
void exitProgram(string message, int code);

void handleSelection(int selection);
void handleVending(float price, int selection);

void getScreen(int screen);
void mainScreen();

void printMenu(int menu);

void exitProgram(string message = "", int code = 0)
{
	if (message != "")
	{
		cout << message << endl;
	}
	exit(code);
}

void printMenu(int menu)
{
	switch (menu)
	{
	case 0:
		fullLine(width);
		printSpacer(width);
		printText(title, width, Alignment::center);
		printSpacer(width);
		printText("1) Pepsi     | $1.50   2) Coke       | $1.50", width, Alignment::left, 3);
		printText("3) Sprite    | $1.50   4) Dr. Pepper | $1.50", width, Alignment::left, 3);
		printText("5) Root Beer | $1.50   6) Water      | $1.00", width, Alignment::left, 3);
		printSpacer(width);
		printText("7) Insert Money        8) Exit", width, Alignment::center);
		printSpacer(width);
		printText("Current Balance: $" + format_currency(balance), width, Alignment::left, 3);
		fullLine(width);
		break;
	case 1:
		fullLine(width);
		printSpacer(width);
		printText("How Much Would You", width, Alignment::center);
		printText("Like To Insert?", width, Alignment::center);
		printSpacer(width);
		printText("Current Balance: $" + format_currency(balance), width, Alignment::left, 3);
		fullLine(width);
		break;
	default:
		break;
	}
}

void handleSelection(int selection)
{
	switch (selection)
	{
	case 1:
		handleVending(150, 1);
		break;
	case 2:
		handleVending(150, 2);
		break;
	case 3:
		handleVending(150, 3);
		break;
	case 4:
		handleVending(150, 4);
		break;
	case 5:
		handleVending(150, 5);
		break;
	case 6:
		handleVending(100, 6);
		break;
	case 7:
		double money;
		do
		{
			money = 0;
			resetInput();
			clearScreen();
			printMenu(1);

			cout << "Amount (max $20, $0 to return): $";
			cin >> money;

			while (cin.fail() || !acceptedInput.count(money) || (balance + money > 10000))
			{
				resetInput();

				if (balance + money > 10000)
					cout << "Maximum balance is $100. Please insert a smaller amount." << endl;
				else
					cout << "Invalid amount. Please insert a valid bill or coin under $20." << endl;
				cout << "Amount (max $20, $0 to return): $";
				cin >> money;
			}

			balance += (money * 100);
		} while (money != 0);
		getScreen(0);
		break;
	case 8:
		clearScreen();

		fullLine(width);
		printSpacer(width);

		printText("Exiting...", width, Alignment::center);

		if (balance > 0)
		{
			printText("Your change is:", width, Alignment::left, 2);

			while (balance >= 0)
			{
				if (balance >= 2000)
				{
					int twenties = balance / 2000;
					balance -= twenties * 2000;
					printText(to_string(twenties) + " $20 bill(s)", width, Alignment::left, 4);
				}
				else if (balance >= 1000)
				{
					int tens = balance / 1000;
					balance -= tens * 1000;
					printText(to_string(tens) + " $10 bill(s)", width, Alignment::left, 4);
				}
				else if (balance >= 500)
				{
					int fives = balance / 500;
					balance -= fives * 500;
					printText(to_string(fives) + " $5 bill(s)", width, Alignment::left, 4);
				}
				else if (balance >= 200)
				{
					int twos = balance / 200;
					balance -= twos * 200;
					printText(to_string(twos) + " $2 bill(s)", width, Alignment::left, 4);
				}
				else if (balance >= 100)
				{
					int ones = balance / 100;
					balance -= ones * 100;
					printText(to_string(ones) + " $1 bill(s)", width, Alignment::left, 4);
				}
				else if (balance >= 25)
				{
					int quarters = balance / 25;
					balance -= quarters * 25;
					printText(to_string(quarters) + " quarter(s)", width, Alignment::left, 4);
				}
				else if (balance >= 10)
				{
					int dimes = balance / 10;
					balance -= dimes * 10;
					printText(to_string(dimes) + " dime(s)", width, Alignment::left, 4);
				}
				else if (balance >= 5)
				{
					int nickels = balance / 5;
					balance -= nickels * 5;
					printText(to_string(nickels) + " nickel(s)", width, Alignment::left, 4);
				}
				else if (balance >= 1)
				{
					int pennies = balance / 1;
					balance -= pennies * 1;
					printText(to_string(pennies) + " penny(ies)", width, Alignment::left, 4);
				}
				else
				{
					break;
				}
			}
		}

		printSpacer(width);
		fullLine(width);

		exitProgram();
		break;
	default:
		break;
	}
}

void handleVending(float price, int sel)
{
	int selection;
	string item;

	while (balance < price)
	{
		cout << "Insufficient funds. Please insert more money or make another selection." << endl;
		cout << "Selection: ";
		cin >> selection;

		while (cin.fail() || selection < 1 || selection > 8)
		{
			resetInput();
			cout << "Invalid selection. Please try again: ";
			cin >> selection;
		}

		handleSelection(selection);

		break;
	}

	switch (sel)
	{
	case 1:
		item = "Pepsi";
		break;
	case 2:
		item = "Coke";
		break;
	case 3:
		item = "Sprite";
		break;
	case 4:
		item = "Dr. Pepper";
		break;
	case 5:
		item = "Root Beer";
		break;
	case 6:
		item = "Water";
		break;
	default:
		item = "Item";
		break;
	}

	balance -= price;

	clearScreen();

	fullLine(width);
	printSpacer(width);
	printText("Vending " + item + "...", width, Alignment::center);
	printText("Press [Enter] to collect", width, Alignment::center);
	printSpacer(width);
	fullLine(width);

	cin.ignore();
	cin.get();

	getScreen(0);
}

void mainScreen()
{
	int userSelection;

	clearScreen();

	printMenu(0);

	cout << "Selection: ";
	cin >> userSelection;

	while (cin.fail() || userSelection < 1 || userSelection > 8)
	{
		resetInput();
		cout << "Invalid selection. Please try again: ";
		cin >> userSelection;
	}

	switch (userSelection)
	{
	case 1:
		handleSelection(1);
		break;
	case 2:
		handleSelection(2);
		break;
	case 3:
		handleSelection(3);
		break;
	case 4:
		handleSelection(4);
		break;
	case 5:
		handleSelection(5);
		break;
	case 6:
		handleSelection(6);
		break;
	case 7:
		handleSelection(7);
		break;
	case 8:
		handleSelection(8);
		break;
	default:
		break;
	}
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