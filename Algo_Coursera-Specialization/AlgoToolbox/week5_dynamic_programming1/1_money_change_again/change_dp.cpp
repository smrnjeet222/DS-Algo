#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int get_change_recursive(int m) {
    //write your code here
    if (m <= 0) return 0;

    int one = (m >= 1) ? get_change_recursive(m - 1) + 1 : 9999;
    int three = (m >= 3) ? get_change_recursive(m - 3) + 1 : 9999;
    int four = (m >= 4) ? get_change_recursive(m - 4) + 1 : 9999;

    return min(one, min(three, four));
}

int get_change(int m) {
    //write your code here
    vector<int> table(m + 1, 9999);
    table[0] = 0;

    int coins[] = {1, 3, 4};

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            if (i >= coins[j]) {
                int minCoin = table[i - coins[j]] + 1;
                if (minCoin < table[i]) table[i] = minCoin;
            }
        }
    }
    return table[m];
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
