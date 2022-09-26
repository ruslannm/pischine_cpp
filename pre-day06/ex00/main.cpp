#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: conversion <string>" << std::endl;
		return 1;
	}

	Conversion conversion(argv[1]);
	conversion.print();
	return 0;
}

