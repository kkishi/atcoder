#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long increment(long long x) {
  if (x < 10) {
    return x + 1;
  }
  long long a = x % 10;
  long long b = x / 10 % 10;
  if (a + 1 < 10 && a + 1 <= b + 1) {
    return x + 1;
  }
  long long res = increment(x / 10);
  if (res % 10 == 0) {
    return res * 10;
  }
  return res * 10 + (res % 10 - 1);
}

int main() {
  int K;
  cin >> K;

  long long x = 0;
  for (int i = 0; i < K; ++i) {
    x = increment(x);
  }
  cout << x << endl;
}
