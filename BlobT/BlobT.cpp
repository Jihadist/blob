// BlobT.cpp: определяет точку входа для приложения.
//

#include "BlobT.h"
#include "Blob.h"


int main()
{
	Blob<int> b1{ 1,2,3 };
	Blob<int> b11{ 1,2,3,4 };
	Blob<char>  b2{ 'a','b','c' };
	if (b1 == b11)
		std::cout << true;
	else if (b1 == b1)
		std::cout << "uncorrect " << true;
	else std::cout << false;
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
