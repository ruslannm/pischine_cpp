#include "Harl.hpp"

Harl::Harl(void)
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	return;
}

size_t Harl::_getLevelNumber(std::string level)
{
	size_t levelNumber = 0;
	for (size_t i = 0; i != 4; ++i)
	{
		if (level == _levels[i])
			levelNumber = i + 1;
	}
	return levelNumber;
};

void Harl::filter(std::string level)
{

	switch (Harl::_getLevelNumber(level))
	{
		case 1:
			Harl::complain("DEBUG");
		case 2:
			Harl::complain("INFO");
		case 3:
			Harl::complain("WARNING");
		case 4:
			Harl::complain("ERROR");
			break;
		default:
			std::cout << "[ "
					  << "Probably complaining about insignificant problems"
					  << " ]" << std::endl;
	}
	return;
}

void Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug,
								   &Harl::info,
								   &Harl::warning,
								   &Harl::error};

	size_t i = Harl::_getLevelNumber(level);
	if (i)
	{
		std::cout << "[ " << level << " ]" << std::endl;
		(this->*func[i - 1])();
		std::cout << std::endl;
	}
	return;
};

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my" <<
			  " 7XL-double-cheese-triple-pickle-special-ketchup burger." <<
			  " I really do!" << std::endl;
	return;
};

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." <<
			  " You didn’t put enough bacon in my burger!" <<
			  "If you did, I wouldn’t be asking for more!" << std::endl;
	return;
};

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." <<
			  " I’ve been coming for years whereas you started working" <<
			  "here since last month." << std::endl;
	return;
};

void Harl::error(void)
{
	std::cout << "This is unacceptable!" <<
			  " I want to speak to the manager now." << std::endl;
	return;
};
