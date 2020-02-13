#include "Replica1.h"
#include <iostream>

Replica1::Replica1()
{
	std::cout << "\nThe replica";
}


void Replica1::Talk()
{
	std::cout << "\nThunder roars\n";
}

Replica1::~Replica1()
{
	std::cout << "\nThe replica has expired";
}