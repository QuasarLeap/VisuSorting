using namespace std;
#include <iostream>
#include <random>
#include <vector>


void insertRandNum(vector<int> &numArr, int size){
    std::random_device rdSeed;
    for(int i = 0; i < size; i++){
        std::mt19937 GEN(rdSeed());
        std::uniform_int_distribution<int> dist(1, size);

        int rNum = dist(GEN);

        numArr.push_back(rNum); 

    }

}

void printArray(vector<int> &numArr){
    for(int i = 0; i < numArr.size(); i++){
        cout << numArr[i] << endl;
    }
}

void bubbleSort(){

}

void selectionSort(){
    
}

void insertionSort(){

}

void quickSort(){

}

void mergeSort(){

}

void heapSort(){

}


int main(int argc, char *argv[]){

    const int A_SIZE = 10000;
    vector<int> numArr;

    insertRandNum(numArr, A_SIZE);



    return 0;
}
