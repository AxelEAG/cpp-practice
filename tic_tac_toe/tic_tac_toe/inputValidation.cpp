#include <iostream>
#include <string_view>
#include <format>
#include <limits>
#include <cstdlib>

static void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
static bool clearFailedExtraction()
{
	// Only proceed if extraction failed
	if (std::cin)
		return false;

	if (std::cin.eof())
		std::exit(0);

	std::cin.clear();
	ignoreLine();

	return true;
}

// returns true if had unextracted input and cleans it
static bool clearUnextractedInput()
{
	if (std::cin.peek() == '\n')
		return false;

	ignoreLine();
	return true;
}

int getValidInput(std::string_view type, int max, int min = 1)
{
	while (true)
	{
		std::cout << std::format("Input valid {} (1-{}): ", type, max);
		int value{};
		std::cin >> value;
		if (clearFailedExtraction() || clearUnextractedInput())
			continue;

		if (value >= min && value <= max)
			return value;
	}

}

int getValidAnswer()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char answer{};
		std::cin >> answer;
		if (!clearFailedExtraction() && !clearUnextractedInput() && (answer == 'y' || answer == 'n'))
			return answer;

		std::cout << "Please enter a vaild answer (y/n). \n";
	}

}

