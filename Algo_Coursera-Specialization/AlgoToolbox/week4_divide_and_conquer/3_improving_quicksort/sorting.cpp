#include <cstdlib>
#include <iostream>
#include <vector>

using std::swap;
using std::vector;

int partition2(vector<int> &a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

vector<int> partition3(vector<int> &a, int l, int r) {
    int x = a[l];
    vector<int> m(2);
    int j = l;
    int k = r;
    int i = l;
    while (i <= k) {
        if (a[i] < x) {
            swap(a[j], a[i]);
            j++;
            i++;
        } else if (a[i] == x) {
            i++;
        } else {
            swap(a[i], a[k]);
            k -= 1;
        }
        m[0] = j;
        m[1] = k;
    }
    return m;
}
void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1 = partition3(a, l, r)[0];
    int m2 = partition3(a, l, r)[1];

    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
