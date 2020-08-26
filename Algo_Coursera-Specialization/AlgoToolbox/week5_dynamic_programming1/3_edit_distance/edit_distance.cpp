#include <iostream>
#include <string>
#include <vector>

using namespace std;

int edit_distance(string str1, string str2) {
    int l1 = str1.size();
    int l2 = str2.size();

    vector<vector<int>> dp_grid(l2, vector<int>(l1, 0));

    return dp_grid[l2][l1];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << edit_distance(str1, str2) << endl;
    return 0;
}
