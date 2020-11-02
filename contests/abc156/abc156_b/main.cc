#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int N, K;
  cin >> N >> K;

  int digits = 0;
  while (N > 0) {
    N /= K;
    ++digits;
  }
  cout << digits << endl;
}
