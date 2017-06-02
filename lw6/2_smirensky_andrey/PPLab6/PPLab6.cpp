#include "stdafx.h"
#include <iostream>
#include "Sort.h"


int main(int argc, char * argv[])
{
	if (argc < 3)
		return 1;

	std::ifstream inFile(argv[1]);

	std::vector<int> arr;

	while (!inFile.eof())
	{
		int num;
		inFile >> num;
		arr.push_back(num);
	}

	std::string type = argv[2];

	auto start = std::chrono::system_clock::now();

	if (type == "par")
		MergeSortPar(arr, 0, arr.size() - 1);
	else
		MergeSort(arr, 0, arr.size() - 1);

	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> dif = end - start;
	std::cout << "Time: " << dif.count() << std::endl;
	return 0;
}

