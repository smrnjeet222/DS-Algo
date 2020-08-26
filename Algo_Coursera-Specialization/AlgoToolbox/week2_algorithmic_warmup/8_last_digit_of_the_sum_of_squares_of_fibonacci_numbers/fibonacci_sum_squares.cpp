#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {
    n = n % 60;

    if (n==0) return 0;
    if (n==1) return 1;

    int previous = 0, current = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        int tmp_previous = previous;
        previous = current;
        current = ((tmp_previous % 10) + (current % 10));
    }
    return current%10;
}

int last_digit(unsigned long long n) {
    if (n==0) return 0;
    long long v_side = fibonacci_sum_squares_fast(n);
    long long h_side = fibonacci_sum_squares_fast(n+1);

    return (v_side*h_side)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n);
    std::cout << last_digit(n);
}
