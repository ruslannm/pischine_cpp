#include "FtSed.hpp"

FtSed::FtSed(std::string filename) :
		_ifs(filename)
{
	_available = true;
	if (_ifs.is_open())
	{
		_ofs.open(filename + ".replace");
		if (!_ofs.is_open())
		{
			std::cout << "Файл " << filename << ".replace не открыт"
					  << std::endl;
			_available = false;
		}

	}
	else
	{
		std::cout << "Файл " << filename << " не открыт" << std::endl;
		_available = false;
	}
};

FtSed::~FtSed()
{
	_ifs.close();
	_ofs.close();
};

bool FtSed::replace(std::string strFrom, std::string strTo)
{
	std::string content;
	std::size_t pos;
	std::size_t i = 0;

	if (!_available)
	{
		return false;
	}
	if (strFrom.empty() || strTo.empty())
	{
		std::cout << "String can not be empty" << std::endl;
		return false;
	}
	std::getline(_ifs, content, '\0');
	pos = content.find(strFrom);
	while (pos != std::string::npos)
	{
		while (i != pos)
		{
			_ofs << content[i++];
		}
		_ofs << strTo;
		i += strFrom.size();
		pos = content.find(strFrom, i);
	}
	while (i != content.size())
	{
		_ofs << content[i++];
	}
	return true;
};
