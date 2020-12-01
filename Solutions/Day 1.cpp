
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int Size = 200;

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
        cout << findPair(myArray, 0, 199);
    }
    return 0;
}

