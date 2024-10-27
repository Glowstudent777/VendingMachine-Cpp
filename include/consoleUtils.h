#ifndef CONSOLEUTILS_H
#define CONSOLEUTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>

enum class Alignment
{
    left,
    center,
    right
};

void printText(std::string text, int width, Alignment dir, int offset = 0)
{
    int displayLength = text.length();
    int left = 0;
    int right = 0;

    // -2 to account for the asterisks
    switch (dir)
    {
    case Alignment::left:
        left = offset;
        right = width - displayLength - left - 2;
        break;
    case Alignment::center:
        left = ((width - displayLength) / 2) - 1;
        right = width - displayLength - left - 2;
        break;
    case Alignment::right:
        right = offset;
        left = width - displayLength - right - 2;
        break;
    }

    std::cout << "*" << std::string(left, ' ') << text << std::string(right, ' ') << "*" << std::endl;
}

void printSpacer(int width)
{
    std::cout << "*" << std::setw(width - 1) << "*" << std::endl;
}

void fullLine(int width)
{
    std::cout << std::string(width, '*') << std::endl;
}

std::string format_currency(float amount)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << amount;
    std::string formatted = stream.str();
    return formatted;
}

#endif