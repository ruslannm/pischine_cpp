#include <iostream>
#include "Data.hpp"

int main(void)
{
	Data data("serialization");
	std::cout << "Create object" << std::endl;
	std::cout << "Data address: " << &data << ", value : " << data.getData()
			  << std::endl;

	uintptr_t ptr = serialize(&data);

	std::cout << "Address returned by serialize : " << ptr << std::endl;
	std::cout << "Returned object" << std::endl;
	Data *dataNew = deserialize(ptr);
	std::cout << "Data address: " << dataNew << ", value : "
			  << dataNew->getData() << std::endl;
	return 0;
}
