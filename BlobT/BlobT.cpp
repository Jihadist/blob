// BlobT.cpp: определяет точку входа для приложения.
//

#include "BlobT.h"
#include "Blob.h"
#include "BlobPtr.h"
using namespace std;

int main()
{
	Blob<int> numbers = { 1,2,3 };
	cout << "Hello CMake." << endl;
	return 0;
}
