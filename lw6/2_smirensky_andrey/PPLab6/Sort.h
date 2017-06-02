#pragma once
#include <thread>
#include <vector>
#include <string>

void merge(std::vector<int>& vec, int startPos, int endPos, int half);
void MergeSort(std::vector<int>& vec, int startPos, int endPos);
void MergeSortPar(std::vector<int>& vec, int startPos, int endPos);

