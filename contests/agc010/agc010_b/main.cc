#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  int sum = accumulate(a);
  int N = n * (n + 1) / 2;
  if (sum % N != 0) return false;
  int k = sum / N;
  int cnt = 0;
  rep(i, n) {
    int diff = a[(i + 1) % n] - a[i];
    if (diff > k) return false;
    if ((k - diff) % n != 0) return false;
    cnt += (k - diff) / n;
  }
  return cnt == k;
}

void Main() { wt(Solve() ? "YES" : "NO"); }
