#include <bits/stdc++.h>

using namespace std;

int trees(int right, int down, vector<string> forest){

    int x = 0, y = 0;
    long long tree = 0;
    int rows = forest.size();
    int columns = forest[0].size();
    while (y < rows){
        if (forest[y][x] == '#'){
            ++tree;
        }
        x = (x + right) % columns;
        y += down;
    }

    return tree;
}

int main() {
    ifstream file("Inputs/Day3");
    vector<string> forest;
    string line;
    while(getline(file, line)){
        forest.push_back(line);
    }
    int answer = 0;
    answer = trees(3, 1, forest);
    cout << "The solution to part A is : " << answer << endl;

    answer *= trees(1, 1, forest);
    answer *= trees(5, 1, forest);
    answer *= trees(7, 1, forest);
    answer *= trees(1, 2, forest);

    cout << "The solution to part B is : " << answer << endl;

    return 0;
}