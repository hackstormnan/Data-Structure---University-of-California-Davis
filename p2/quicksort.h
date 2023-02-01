// Quicksort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include <vector>


void QuickSort(std::vector<int>* numbers,int& com,int& mem);
void QuickSortRecurse(std::vector<int>* numbers, int i, int k,int& com,int& mem);
int Partition(std::vector<int>* numbers, int i, int k,int& com,int& mem);
