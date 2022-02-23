using namespace std;
#include <iostream>
#include <random>
#include <vector>


void InsertRandNum(vector<int> &numArr, int size){
    random_device rdSeed;
    for(int i = 0; i < size; i++){
        mt19937 GEN(rdSeed());
        uniform_int_distribution<int> dist(1, size);

        int rNum = dist(GEN);

        numArr.push_back(rNum); 

    }

}


void PrintArray(vector<int> &numArr, int N){
    for(int i = 0; i < N; i++){
        cout << numArr[i] << endl;
    }
}

void SwapPos(vector<int> &numArr, int firstPos, int secPos){
    int temp = numArr[firstPos];
    numArr[firstPos] = numArr[secPos];
    numArr[secPos] = temp;//swap with the stored first number
}//don't even need this?use std lib?



int Partition(vector<int> &numArr, int leftPos,  int rightPos){
    random_device rd_seed;
    mt19937 GEN(rd_seed());
    uniform_int_distribution<int> dist(leftPos, rightPos);

    int pivotPos = dist(GEN);

    SwapPos(numArr, pivotPos, rightPos);

    int posLastSmaller = leftPos;//position that indicates position before this has values lower than pivot
    
    for(int i = leftPos; i < rightPos; i++){//i is the current position of number being compared
        if(numArr[i] < numArr[rightPos]){//remember to actually compare the pivot value that is in the new index(i.e. right index when swapped above)
            SwapPos(numArr, i, posLastSmaller);
            posLastSmaller += 1;//increment to show that the position before has smaller number than pivot
        }
        //cout << "i=" << i << " posLastSmaller=" << posLastSmaller << "PivotPos=" << pivotPos << endl;
        //PrintArray(numArr);
        //cout << "*******************\n" << endl; //test outputs/////////////
    }

    SwapPos(numArr, posLastSmaller, rightPos);

    //PrintArray(numArr);
    //cout << "+++++++++++" << endl;
    return posLastSmaller;

}


void Merge(vector<int> &numArr, int left, int mid, int right){
    vector<int> sortedArr;
    int lpointer = left;
    int rpointer = right;
    int mpointer = mid;
    cout << "TEST: " << endl;
    PrintArray(numArr, numArr.size());
    cout << "LPOINTER: " << lpointer << " RPOINTER: " << rpointer << endl;
    for(int i = 0; i <= right-left; i++){
        if(numArr[lpointer] < numArr[mpointer]){
            sortedArr.push_back(numArr[lpointer]);
            lpointer++;
        }
        else{
            sortedArr.push_back(numArr[mpointer]);
            mpointer++;
        }
    }

    for(int i = 0; i <= right-left; i++){
        numArr[left] = sortedArr[i];
        left++;
    }


    
}



void BubbleSort(vector<int> &numArr, int N){
    bool swapped;
    for(int i = 0; N-1; i++){
        swapped = false;
        for(int j = 0; j < N-i-1; j++){//bring largest number to the end of vector/array
            if(numArr[j] > numArr[j+1]){
                SwapPos(numArr, j, j+1);
                swapped = true;
            }
        }
        if(swapped == false)
            break;

    }
}

void SelectionSort(vector<int> &numArr, int N){
    //current minimum index/item variable
    //set current minimum to the first unsorted element

    for(int i = 0; i < N; i++){
        int curMinI = i;
        //look for smaller number
        for(int j = i+1; j < N; j++){
            if(numArr[j] < numArr[curMinI]){
                curMinI = j;
            }
        }
        //swap numbers
        //go to next unsorted position        
        SwapPos(numArr, i, curMinI);
    }
    


}

void InsertionSort(vector<int> &numArr, int N){
    for(int i = 1; i < N; i++){//go through all elements, creating sorted partition to the left
    int j = i;
        while(numArr[j] < numArr[j-1] && j > 0){
            SwapPos(numArr, j, j-1);
            j-=1;
        }
    }

}

void QuickSort(vector<int> &numArr, int leftPos, int rightPos){
    if(leftPos >= rightPos){//will be the check if this partition is size 1?
        return;
    }
    
    int pIndex = Partition(numArr, leftPos, rightPos);//sort current partition around the pivot
    //cout << "-----Partition FInished----" << endl;
    //PrintArray(numArr);
    QuickSort(numArr, leftPos, pIndex-1);//sort left partition
    QuickSort(numArr, pIndex+1, rightPos);//sort right partition

}

void MergeSort(vector<int> &numArr, int start, int end){//NOT DONE
    if(start == end){
        return;
    }

    MergeSort(numArr, start, end/2);
    MergeSort(numArr, (end/2)+1, end);
    Merge(numArr, start, (end/2)+1, end);
    

}//NOT DONE

void HeapSort(){

}

void RadixSort(){

}


int main(int argc, char *argv[]){

    const int A_SIZE = 10;
    vector<int> numArr;

    InsertRandNum(numArr, A_SIZE);

    PrintArray(numArr, A_SIZE);
    //BubbleSort(numArr, A_SIZE);
    //SelectionSort(numArr, A_SIZE);
    //InsertionSort(numArr, A_SIZE);
    //QuickSort(numArr, 0, A_SIZE-1);
    //MergeSort(numArr, 0, A_SIZE-1);
    //cout << "----BUBBLE SORTED----" << endl;
    //cout << "-----SELECTION SORTED-----" << endl;
    //cout << "----INSERTION SORT----" << endl;
    //cout << "----QUICK SORT----" << endl;
    //cout << "----MERGE SORT----" << endl;
    PrintArray(numArr, A_SIZE);

    return 0;
}
