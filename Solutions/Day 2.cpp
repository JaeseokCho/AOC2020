#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ifstream file("Inputs/Day2");

    if (!file){
        cout << "Error";
    }
    if (file.is_open()) {
        int countA = 0, countB = 0;

        int min, max;
        char ch;
        char pw[100];
        map<char, int> chCount;
        std::string line;
        while (std::getline(file, line)) {
            sscanf(line.c_str(), "%d-%d %c: %s", &min, &max, &ch, &pw);

            for (int i = 0; pw[i] != '\0'; i++){
                chCount[pw[i]] += 1;
            }

            if (chCount[ch] >= min && chCount[ch] <= max){
                ++countA;
            }

            if (pw[min-1] == ch ^ pw[max-1] == ch){
                ++countB;
            }
            chCount.clear();
        }
        cout << "The solution to part A is : " << countA << endl;
        cout << "The solution to part B is : " << countB << endl;
        return 0;
    }
}