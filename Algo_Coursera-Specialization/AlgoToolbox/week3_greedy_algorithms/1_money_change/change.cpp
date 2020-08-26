#include <iostream>

long long get_change(long long m, long long n = 0) {
  //write your code here
  if (m==0) return n;

  if (m>=10) return get_change(m%10, n+(m/10));
  else if (m>=5) return get_change(m%5, n+(m/5));
  else if (m>=1) return get_change(m-1, n+1);

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
