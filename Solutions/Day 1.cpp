#include <bits/stdc++.h>
using namespace std;

const int Size = 200;
// Solution to part A
int findPair(int array[], int head, int tail){

    int total = array[head] + array[tail];
    if (total == 2020){
        return array[head] * array[tail];
    }
    else if (total > 2020){
        findPair(array, head, tail - 1);
    }
    else {
        findPair(array, head + 1, tail);
    }
}

// Solution to part B
int findTriplets(int array[], int arraySize){
    for (int i = 0; i < arraySize - 2; ++i){
        unordered_set<int> set;
        int currentSum = 2020 - array[i];
        for (int j = i + 1; j < arraySize; ++j){
            if (set.find(currentSum - array[j]) != set.end()){
                return array[i] * array[j] * (currentSum - array[j]);
            }
            set.insert(array[j]);
        }
    }
}
int main(){

    ifstream file("Inputs/Day1");

    if (!file){
        cout << "Error";
    }
    if (file.is_open()) {
        int myArray[Size];

        for (int i = 0; i < Size; ++i) {
            file >> myArray[i];
        }
        sort(myArray, myArray + Size);
        cout << "The solution to part A is: " << findPair(myArray, 0, 199 ) << endl;
        cout << "The solution to part B is: " << findTriplets(myArray, Size);
    }
    return 0;
}

