#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("Inputs/Day3");

    string line;
    int count = 0;
    int check = 0;
    int tree = 0;

    while (getline(file, line)){
        check = (count*3) % 31;
        if (line[check] == '#'){
            tree++;
        }

        count += 1;
    }

    cout << "The solution to part A is : " << tree << endl;
}