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

void swapPos(vector<int> &numArr, int first, int sec){
    int temp = numArr[first];
    numArr[first] = numArr[sec];
    numArr[sec] = temp;
}

void bubbleSort(vector<int> &numArr){
    bool swapped;
    for(int i = 0; numArr.size()-1; i++){
        swapped = false;
        for(int j = 0; j < numArr.size()-i-1; j++){
            if(numArr[j] > numArr[j+1]){
                swapPos(numArr, j, j+1);
                swapped = true;
            }
        }
        if(swapped == false)
            break;

    }
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

    printArray(numArr);
    bubbleSort(numArr);
    
    cout << "----BUBBLE SORTED----" << endl;
    printArray(numArr);

    return 0;
}
