#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Menu
{
	std::string menuName;
	std::vector<std::string> options;

public:
	Menu(const std::string& name);
	void addOption(const std::string& option_caption);
	int askOption();
	static constexpr unsigned char CONSOLE{ 0b0000'0001 };

	void print(unsigned char flag, const std::string& text)
	{
		if (flag & CONSOLE) { std::cout << text; }
	}

	int inputInt(const std::string& text, std::pair<int, int> limits)
	{
		int input{ 1 };
		std::cin.clear();
		bool failFlag{ false };
		do
		{
			if (failFlag)
			{
				print(CONSOLE, "Incorrect input. Try again.\n");
			}
			print(CONSOLE, text);
			std::cin.clear();
			std::string str_input{};
			std::cin >> str_input;
			failFlag = false;
			try
			{
				input = std::stoi(str_input);
			}
			catch (std::logic_error)
			{
				failFlag = true;
			}
			failFlag |= !((input >= limits.first) && (input <= limits.second));

		} while (failFlag);

		return input;
	}


	

private:
	static bool comparator(const std::string& option1, const std::string& option2)
	{
		return option1.length() < option2.length();
	}

	size_t getMenuWidth();
};