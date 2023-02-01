// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"


void InsertionSort(std::vector<int>* numbers, int& com, int& mem) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
	
    
	while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
	         
         // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         --j;
          com++;
          mem=mem+6;
      }if(j>0){com++;mem=mem+2;};
   };
   
   return;
};