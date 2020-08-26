#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }
    return sum % 10;
}

long long get_sum(long long n){
    n = (n+2)%60; 

    long long previous = 0;
    long long current  = 1;

    if (n == 0)
        return previous;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }
    if(current == 0){
        return 9;
    }
    return (current-1);
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    long long x = get_sum(to);
    long long y = get_sum(from-1);
    return (x+10 - y)%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
