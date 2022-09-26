#include "Data.hpp"

Data::Data(void) : _data("data") {};

Data::Data(std::string const &str) : _data(str) {};

Data::Data(const Data &src) : _data(src._data) {};

Data::~Data(void) {};

Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
	}
	return *this;
}

std::string Data::getData(void) const { return (this->_data); }

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}