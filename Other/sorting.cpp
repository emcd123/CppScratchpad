//g++  5.4.0

#include <iostream>
#include <stdlib.h> //To use random number functions

using namespace std;

#define MAX_SIZE 10
class BubbleSort{
 public:
    void Swap(int &p1, int &p2 );
    void Sort( int* array ,int arrSize);
    BubbleSort(void);
    ~BubbleSort(void);
};
BubbleSort::BubbleSort(void){
}

BubbleSort::~BubbleSort(){
}
void BubbleSort::Sort(int* array,int arrSize){
  for(int i=(arrSize-1); i>1; i--){
    for(int k=0; k<i; k++){
      if(array[k] > array[k+1]){
        swap(array[k], array[k+1]);
      }
    }
  }
}

void BubbleSort::Swap(int &p1, int &p2) {
     int temp = p1;
     p1 = p2;
     p2 = temp;
}
int main()
{
  const int n = 5;
  int array[n];
  /* initialize random seed: */
  srand (time(NULL));
  //populate array with random integers
  for(int i = 0; i< n; i++){
    array[i] = rand() %10;
   }
   
     cout << "Unsorted random generted list: ";
  for(int j= 0; j< n; j++){
    cout << array[j];
   }
   BubbleSort bsort;
   bsort.Sort(array, n);
     cout << "Sorted random generted list: ";
  for(int j= 0; j< n; j++){
    cout << array[j];
   }
}
