#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string>
#include <vector>

using namespace std;

bool isG(string dg, string mx_dg) {
    return stoi(dg + mx_dg) >= stoi(mx_dg + dg);
}

string largest_number(vector<string> a) {
    string res = "";
    int x = a.size();
    while (x--) {
        string mx_dg = "0";
        int r = 0;
        for (int i = 0; i < a.size(); i++) {
            if (isG(a[i], mx_dg)) {
                mx_dg = a[i];
                r = i;
            }
        }
        res += mx_dg;
        a.erase(a.begin()+r);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    cout << largest_number(a);
}
