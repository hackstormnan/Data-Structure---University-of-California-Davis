#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
#include <ctime>
#include "quicksort.h"
#include "mergesort.h"
#include "insertionsort.h"
#include <iomanip>

using namespace std;



int main(int argc, char** argv) {



    std::ofstream output;
    output.open ("out.csv");

    output<<"Sample,"<<"InsertionSortTime,"<<"InsertionSortCompares,"<<"InsertionSortMemaccess,"<<
    "MergeSortTime,"<<"MergeSortCompares,"<<"MergeSortMemaccess,"<<"QuickSortTime,"<<
    "QuickSortCompares,"<<"QuickSortMemaccess"<<"\n";

    cout<<"Sample,"<<"InsertionSortTime,"<<"InsertionSortCompares,"<<"InsertionSortMemaccess,"<<
    "MergeSortTime,"<<"MergeSortCompares,"<<"MergeSortMemaccess,"<<"QuickSortTime,"<<
    "QuickSortCompares,"<<"QuickSortMemaccess"<<"\n";

    string user_input=argv[1];

    std::ifstream file;
    file.open(user_input);
    nlohmann::json jsonObject;
    nlohmann::json outjason;
    if (file.is_open()) { file >> jsonObject; }
    int size_s = jsonObject["metadata"]["numSamples"];
    int size_a = jsonObject["metadata"]["arraySize"];

    for(int j=1;j<size_s+1;j++){



      int i_comparasion=0, i_mem_acess=0;
      int q_comparasion=0, q_mem_acess=0;
      int m_comparasion=0, m_mem_acess=0;
      std::clock_t i_start;
      std::clock_t q_start;
      std::clock_t m_start;
      double duration1,duration2,duration3;
      vector<int> num1,num2,num3;


            string sample="Sample";


            if(j<10){

            sample= sample+'0';

              }

            sample=sample + to_string(j);

    for(int i=0;i<size_a;i++){
        num1.push_back(jsonObject[sample][i]);
        num2.push_back(jsonObject[sample][i]);
        num3.push_back(jsonObject[sample][i]);

         }

    i_start = std::clock();
    InsertionSort(&num1, i_comparasion, i_mem_acess);
    duration1 = ( std::clock() - i_start ) / (double) CLOCKS_PER_SEC;


    q_start = std::clock();
    QuickSort(&num2, q_comparasion,q_mem_acess);
    duration2 = ( std::clock() - q_start ) / (double) CLOCKS_PER_SEC;


    m_start = std::clock();
    MergeSort(&num3,m_comparasion,m_mem_acess);
    duration3 = ( std::clock() - m_start ) / (double) CLOCKS_PER_SEC;

    cout<<sample<<","<<fixed<<setprecision(6)<<duration1<<","<<i_comparasion<<","<<i_mem_acess<<","<<fixed<<setprecision(6)<<
    duration2<<","<<q_comparasion<<","<<q_mem_acess<<","<<fixed<<setprecision(6)<<duration3<<","<<m_comparasion<<","<<m_mem_acess<<","<<"\n";



output<<sample<<","<<fixed<<setprecision(6)<<duration1<<","<<i_comparasion<<","<<i_mem_acess<<","<<fixed<<setprecision(6)<<
duration2<<","<<q_comparasion<<","<<q_mem_acess<<","<<fixed<<setprecision(6)<<duration3<<","<<m_comparasion<<","<<m_mem_acess<<","<<"\n";

}
output.close();


}
