#include <bits/stdc++.h>

using namespace std;

const int Size = 1000;

int main(){
    std::ifstream file("Inputs/Day2");

    if (!file){
        cout << "Error";
    }
    if (file.is_open()) {
        int count = 0;
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
                ++count;
            }
            chCount.clear();
        }
        cout << count << endl;
        return 0;
    }
}