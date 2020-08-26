#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisanoPeriod(long long m){
    long long prev = 0, cur = 1;
    long long temp = prev + cur;
    for (int i = 0; i < m * m; i++) {
        temp = (prev + cur) % m;
        prev = cur;
        cur = temp;
        if (prev == 0 && cur == 1) return i + 1;
    }
    return m;
} 

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    long long x = n % pisanoPeriod(m);

    for (long long i = 1; i < x; i++) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }
    if (x==0) return 0;
    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

}
