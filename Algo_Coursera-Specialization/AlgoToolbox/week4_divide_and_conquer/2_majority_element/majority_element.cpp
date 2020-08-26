#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    // if (left == right) return -1;
    if (left == right) return a[left];
    //write your code here
    int mid = (left + right) / 2;
    int l_e = get_majority_element(a, left, mid);
    int r_e = get_majority_element(a, mid+1, right);

    if (l_e == r_e) return l_e;

    int rc = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == r_e) rc += 1;
    }
    if (rc > (right - left) / 2) return r_e;

    int lc = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == l_e) lc += 1;
    }
    if (lc > (right - left) / 2) return l_e;

    return -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}