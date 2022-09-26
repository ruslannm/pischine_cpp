#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>

enum LiteralType
{
	ERROR, CHAR, INT, FLOAT, DOUBLE
};
enum PseudoLiteralType
{
	NON_DEFINED, PLUS_INF, MINUS_INF, NAN
};

class Conversion
{
public :
	Conversion();

	Conversion(const std::string &);

	Conversion(Conversion const &);

	Conversion &operator=(Conversion const &);

	~Conversion();

	std::string getStr(void) const;

	std::string getType(void) const;

	void print(void) const;

private :

	void _detectType(void);

	bool _isChar(void);

	static bool _isDigit(char);

	static bool _isNumber(const std::string &, bool, bool);

	static bool _isInt(const std::string &);

	static bool _isFloat(const std::string &);

	static bool _isDouble(const std::string &);

	bool _checkOverflow(void);

	void _convertToChar(void);

	void _convertToInt(void);

	void _convertToFloat(void);

	void _convertToDouble(void);

	size_t _getPrecision(void) const;

	void _printChar(void) const;

	void _printInt(void) const;

	void _printFloat(void) const;

	void _printDouble(void) const;

	std::string _str;

	LiteralType _type;
	PseudoLiteralType _pseudoLiteralType;
	char _char;
	int _int;
	float _float;
	double _double;
};

#endif
