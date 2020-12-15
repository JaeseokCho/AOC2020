#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream file("Inputs/Day4");
    string line, line2;
    int count = 0, fields = 0, cid = 0;
    char field[100], value[100];

    do{
        (getline(file, line));
        if (line != "") {
            istringstream check;
            check.str(line);
            while (check >> line2){
                sscanf(line2.c_str(), "%[^:]:%s", field, value);
                if (strcmp(field, "cid") == 0){
                    cid = 1;
                }
                ++fields;
            }
        }
        else {
            if (fields == 8 || (fields == 7 && !cid)){
                ++count;
            }
            fields = 0;
            cid = 0;
        }
    }
    while (!file.eof());

    cout << "The solution to part A is : " << count << endl;

    return 0;
}