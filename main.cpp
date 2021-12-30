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

void swapPos(vector<int> &numArr, int firstPos, int secPos){
    int temp = numArr[firstPos];
    numArr[firstPos] = numArr[secPos];
    numArr[secPos] = temp;//swap with the stored first number
}

void bubbleSort(vector<int> &numArr){
    bool swapped;
    for(int i = 0; numArr.size()-1; i++){
        swapped = false;
        for(int j = 0; j < numArr.size()-i-1; j++){//bring largest number to the end of vector/array
            if(numArr[j] > numArr[j+1]){
                swapPos(numArr, j, j+1);
                swapped = true;
            }
        }
        if(swapped == false)
            break;

    }
}

void selectionSort(vector<int> &numArr){
    //current minimum index/item variable
    //set current minimum to the first unsorted element

    for(int i = 0; i < numArr.size(); i++){
        int curMinI = i;
        //look for smaller number
        for(int j = i+1; j < numArr.size(); j++){
            if(numArr[j] < numArr[curMinI]){
                curMinI = j;
            }
        }
        //swap numbers
        //go to next unsorted position        
        swapPos(numArr, i, curMinI);
    }
    


}

void insertionSort(vector<int> &numArr){
    for(int i = 1; i < numArr.size(); i++){//go through all elements, creating sorted partition to the left
    int j = i;
        while(numArr[j] < numArr[j-1] && j > 0){
            swapPos(numArr, j, j-1);
            j-=1;
        }
    }

}

void quickSort(){

}

void mergeSort(){

}

void heapSort(){

}


int main(int argc, char *argv[]){

    const int A_SIZE = 10;
    vector<int> numArr;

    insertRandNum(numArr, A_SIZE);

    printArray(numArr);
    //bubbleSort(numArr);
    //selectionSort(numArr);
    insertionSort(numArr);
    //cout << "----BUBBLE SORTED----" << endl;
    //cout << "-----SELECTION SORTED-----" << endl;
    cout << "----INSERTION SORT----" << endl;
    printArray(numArr);

    return 0;
}
