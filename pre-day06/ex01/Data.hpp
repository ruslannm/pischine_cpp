#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>
#include <string>

class Data
{
public:
	Data(void);

	Data(std::string const &);

	Data(const Data &);

	~Data(void);

	Data &operator=(const Data &);

	std::string getData(void) const;

private:
	std::string _data;
};

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif
