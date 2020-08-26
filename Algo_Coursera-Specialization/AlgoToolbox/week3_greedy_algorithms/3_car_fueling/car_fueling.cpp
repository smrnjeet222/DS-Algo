#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> stops) {
    // write your code here
    int f = tank;
    int count = 0;

    stops.emplace_back(dist);

    if (stops[0] > tank) return -1;

    for (int i = 0; i < stops.size()-1; ++i) {
        if (i==0) f -= stops[i];
        else f -= (stops[i]-stops[i-1]);
        if ((stops[i + 1] - stops[i]) > f && (stops[i + 1]-stops[i]) <= tank) {
            count++;
            f = tank;
        } else if((stops[i + 1]-stops[i]) > tank)
            return -1;
    }
    return count;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
