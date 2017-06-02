#include "stdafx.h"
#include "Sort.h"

void merge(std::vector<int>& vec, int startPos, int endPos, int half)
{
	if (startPos >= endPos || half < startPos || half > endPos)
		return;
	if (endPos == startPos + 1 && vec[startPos] > vec[endPos])
	{
		std::swap(vec[startPos], vec[endPos]);
		return;
	}

	std::vector<int> tmp(&vec[startPos], &vec[startPos] + (endPos + 1));

	for (int i = startPos, j = 0, k = half - startPos + 1; i <= endPos; ++i)
	{
		if (j > half - startPos)
		{
			vec[i] = tmp[k++];
		}
		else if (k > endPos - startPos)
		{
			vec[i] = tmp[j++];
		}
		else
		{
			vec[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
		}
	}
}

void MergeSort(std::vector<int>& vec, int startPos, int endPos)
{
	if (startPos >= endPos) return;

	int half = startPos + (endPos - startPos) / 2;

	MergeSort(vec, startPos, half);
	MergeSort(vec, half + 1, endPos);

	merge(vec, startPos, endPos, half);
}

void MergeSortPar(std::vector<int>& vec, int startPos, int endPos)
{
	if (startPos >= endPos) return;

	int half = startPos + (endPos - startPos) / 2;

	std::thread thread_one([&vec, startPos, half] { MergeSortPar(vec, startPos, half); });
	std::thread thread_two([&vec, half, endPos] { MergeSortPar(vec, half + 1, endPos); });

	thread_one.join();
	thread_two.join();

	merge(vec, startPos, endPos, half);
}