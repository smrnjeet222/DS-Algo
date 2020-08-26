#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

vector<int> sequence_greedy(int n) {
    std::vector<int> sequence;
    while (n >= 1) {
        sequence.push_back(n);
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int sequence_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 2 || n == 3 || n == 1) return 1;

    int one = (n >= 1) ? sequence_recursive(n - 1) + 1 : 9999;
    int two = !(n % 2) ? sequence_recursive(n / 2) + 1 : 9999;
    int three = !(n % 3) ? sequence_recursive(n / 3) + 1 : 9999;

    return std::min(one, std::min(three, two));
}

vector<int> optimal_sequence(int n) {
    std::vector<int> sequence;
    std::vector<int> n_op(n + 1, 9999);
    n_op[0] = 0;
    n_op[1] = 0;

    for (int i = 2; i < n + 1; i++) {
        int a = 9999, b = 9999, c = 9999;

        a = n_op[i - 1] + 1;
        if (i % 2 == 0) b = n_op[i / 2] + 1;
        if (i % 3 == 0) c = n_op[i / 3] + 1;

        int min_ops = std::min(a, std::min(b, c));

        n_op[i] = min_ops;
    }
    sequence.emplace_back(n);
    while (n != 1) {
        if (n % 3 == 0 && n_op[n] - 1 == n_op[n / 3]) {
            sequence.emplace_back(n / 3);
            n = n / 3;
        } else if (n % 2 == 0 && n_op[n] - 1 == n_op[n / 2]) {
            sequence.emplace_back(n / 2);
            n = n / 2;
        } else {
            sequence.emplace_back(n - 1);
            n -= 1;
        }
    }

    reverse(sequence.begin(), sequence.end());

    return sequence;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
}
