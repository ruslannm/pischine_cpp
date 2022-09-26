#include "Conversion.hpp"

Conversion::Conversion() : _str(""), _type(ERROR),
						   _pseudoLiteralType(
								   NON_DEFINED),
						   _char(0),
						   _int(0), _float(0), _double(0) {};

Conversion::Conversion(const std::string &str) : _str(str)
{
	_detectType();
	switch (_type)
	{
		case ERROR:
			this->_char = 0;
			this->_int = 0;
			this->_float = 0;
			this->_double = 0;
			break;
		case CHAR:
			_convertToChar();
			break;
		case INT:
			_convertToInt();
			break;
		case FLOAT:
			if (_pseudoLiteralType == NON_DEFINED)
			{
				_convertToFloat();
			}
			break;
		case DOUBLE:
			if (_pseudoLiteralType == NON_DEFINED)
			{
				_convertToDouble();
			}
			break;
	}
	return;
};

Conversion::Conversion(Conversion const &src) : _str(src._str),
												_type(src._type),
												_pseudoLiteralType(
														src._pseudoLiteralType),
												_char(src._char),
												_int(src._int),
												_float(src._float),
												_double(src._double) {};

Conversion &Conversion::operator=(Conversion const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_type = rhs._type;
		this->_pseudoLiteralType = rhs._pseudoLiteralType;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return *this;
};

Conversion::~Conversion() {};

std::string Conversion::getStr(void) const
{
	return _str;
};

std::string Conversion::getType() const
{
	switch (_type)
	{
		case CHAR:
			return "char";
		case INT:
			return "int";
		case FLOAT:
			return "float";
		case DOUBLE:
			return "double";
		default:
			return "undefined";
	}
};

void Conversion::_detectType(void)
{
	if (_str.length() == 0)
	{
		_type = ERROR;
		_pseudoLiteralType = NON_DEFINED;
		return;
	}
	if (_str == "-inff")
	{
		_type = FLOAT;
		_pseudoLiteralType = MINUS_INF;
		return;
	}
	if (_str == "-inf")
	{
		_type = DOUBLE;
		_pseudoLiteralType = MINUS_INF;
		return;
	}
	if (_str == "+inff")
	{
		_type = FLOAT;
		_pseudoLiteralType = PLUS_INF;
		return;
	}
	if (_str == "+inf")
	{
		_type = DOUBLE;
		_pseudoLiteralType = PLUS_INF;
		return;
	}
	if (_str == "nanf")
	{
		_type = FLOAT;
		_pseudoLiteralType = NAN;
		return;
	}
	if (_str == "nan")
	{
		_type = DOUBLE;
		_pseudoLiteralType = NAN;
		return;
	}
	if (_str.length() == 1 && std::isprint(_str[0]))
	{
		_type = CHAR;
		_pseudoLiteralType = NON_DEFINED;
		return;
	}
	if (Conversion::_isInt(_str))
	{
		_type = INT;
		_pseudoLiteralType = NON_DEFINED;
		return;
	}
	if (Conversion::_isFloat(_str))
	{
		_type = FLOAT;
		_pseudoLiteralType = NON_DEFINED;
		return;
	}
	if (Conversion::_isDouble(_str))
	{
		_type = DOUBLE;
		_pseudoLiteralType = NON_DEFINED;
		return;
	}
	_type = ERROR;
	_pseudoLiteralType = NON_DEFINED;
	return;
};

bool Conversion::_isChar()
{
	return _str.length() == 1 && std::isprint(_str[0]);
}

bool Conversion::_isDigit(char c)
{
	return '0' <= c && c <= '9';
}

bool Conversion::_isNumber(const std::string &str, bool sign, bool zero)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i)
		{
			if (!_isDigit(str[i]))
			{
				return false;
			}
		}
		else
		{
			if (str[i] == '-' && !sign)
			{
				return false;
			}
			if (str[i] == '0' && !zero)
			{
				return false;
			}
		}
	}
	return true;
}

bool Conversion::_isInt(const std::string &str)
{
	return Conversion::_isNumber(str, true, false);
}

bool Conversion::_isDouble(const std::string &str)
{
	bool result = true;
	size_t pointInd = str.find_first_of('.');
	if (pointInd > 0)
	{
		result *= Conversion::_isInt(str.substr(0, pointInd));
		result *= Conversion::_isNumber(
				str.substr(pointInd + 1, std::string::npos), false, true);
		return result;
	}
	return false;
}

bool Conversion::_isFloat(const std::string &str)
{
	if (str.length() && str.at(str.length() - 1) == 'f')
	{
		return Conversion::_isDouble(str.substr(0, str.length() - 1));
	}
	return false;
}

void Conversion::_convertToChar(void)
{
	_char = _str.at(0);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	return;
};

void Conversion::_convertToInt(void)
{
	const char *strPtr;
	char *err;
	double nb;
	strPtr = _str.c_str();
	nb = strtod(strPtr, &err);
	if (strPtr == err || nb < INT_MIN || nb > INT_MAX)
	{
		_type = ERROR;
	}
	else
	{
		_int = static_cast<int>(nb);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	return;
};

void Conversion::_convertToFloat(void)
{
	double nb;
	errno = 0;
	nb = strtod(_str.c_str(), NULL);
	if (errno || nb <= std::numeric_limits<float>::max() * -1 ||
		nb > std::numeric_limits<float>::max())
	{
		_type = ERROR;
	}
	else
	{
		_float = static_cast<float >(nb);
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	return;
};

void Conversion::_convertToDouble(void)
{
	double nb;
	errno = 0;
	nb = strtod(_str.c_str(), NULL);
	if (errno)
	{
		_type = ERROR;
	}
	else
	{
		_double = nb;
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	return;
};

void Conversion::_printChar() const
{
	if (_type == ERROR || _pseudoLiteralType != NON_DEFINED)
	{
		std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<int>(this->_char)))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << this->_char << std::endl;
	}
	return;
}

void Conversion::_printInt(void) const
{
	if (_type == ERROR || _pseudoLiteralType != NON_DEFINED)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << this->_int << std::endl;
	}
	return;
}

size_t Conversion::_getPrecision() const
{
	size_t precision = 0;
	switch (_type)
	{
		case CHAR:
			precision = 1;
			break;
		case INT:
			precision = 1;
			break;
		case FLOAT:
			precision = _str.length() - _str.find_first_of('.') - 2;
			break;
		case DOUBLE:
			precision = _str.length() - _str.find_first_of('.') - 1;
			break;
		default:
			break;
	}
	return precision;
}

void Conversion::_printFloat() const
{
	if (_type == ERROR || _pseudoLiteralType != NON_DEFINED)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		if (_pseudoLiteralType == NON_DEFINED)
		{
			std::cout << std::setprecision(_getPrecision())
					  << std::setiosflags(std::ios::fixed) << this->_float;
		}
		else
		{
			switch (_pseudoLiteralType)
			{
				case MINUS_INF:
					std::cout << "-inf";
					break;
				case PLUS_INF:
					std::cout << "+inf";
					break;
				case NAN:
					std::cout << "nan";
					break;
				default:
					break;
			}
		}
		std::cout << "f" << std::endl;
	}
	return;
}

void Conversion::_printDouble() const
{
	if (_type == ERROR || _pseudoLiteralType != NON_DEFINED)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		if (_pseudoLiteralType == NON_DEFINED)
		{
			std::cout << std::setprecision(_getPrecision())
					  << std::setiosflags(std::ios::fixed) << this->_double;
		}
		else
		{
			switch (_pseudoLiteralType)
			{
				case MINUS_INF:
					std::cout << "-inf";
					break;
				case PLUS_INF:
					std::cout << "+inf";
					break;
				case NAN:
					std::cout << "nan";
					break;
				default:
					break;
			}
		}
		std::cout << std::endl;
	}
	return;
}

void Conversion::print(void) const
{
	std::cout << "char: ";
	_printChar();
	std::cout << "int: ";
	_printInt();
	std::cout << "float: ";
	_printFloat();
	std::cout << "double: ";
	_printDouble();
	return;
}
