#include <bits/stdc++.h>

using namespace std;

class Loot {
   public:
    double value, weight;
    Loot(double value, double weight) : value(value), weight(weight) {}
};

bool cmp(Loot a, Loot b) {
    double l1 = (double)a.value / a.weight;
    double l2 = (double)b.value / b.weight;

    return l1 > l2;
}

double get_optimal_value(int capacity, int n, vector<Loot> loot) {
    sort(loot.begin(), loot.end(), cmp);

    double cw = 0;
    double val = 0;

    for (int i = 0; i < n; i++) {
        if (cw + loot[i].weight <= capacity) {
            cw += loot[i].weight;
            val += loot[i].value;
        }

        else {
            double remain = capacity - cw;
            val += loot[i].value * ((double)remain / loot[i].weight);
            break;
        }
    }

    return val;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;

    vector<Loot> loot(n, Loot(0, 0));

    for (int i = 0; i < n; i++) {
        cin >> loot[i].value >> loot[i].weight;
    }

    double optimal_value = get_optimal_value(capacity, n, loot);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}
