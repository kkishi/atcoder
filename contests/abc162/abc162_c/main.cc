#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int gcd(int a, int b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (b % a == 0) {
    return a;
  }
  return gcd(b % a, a);
}

int main() {
  int K;
  cin >> K;

  int sum = 0;
  for (int a = 1; a <= K; ++a) {
    for (int b = 1; b <= K; ++b) {
      for (int c = 1; c <= K; ++c) {
        sum += gcd(a, gcd(b, c));
      }
    }
  }
  cout << sum << endl;
}
