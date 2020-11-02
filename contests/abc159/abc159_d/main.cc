#include <bits/stdc++.h>

#include "atcoder.h"

int A[2 * 100000];

int choose2(int n) { return n * (n - 1) / 2; }

void Main() {
  ints(N);
  map<int, int> m;
  rep(i, N) {
    cin >> A[i];
    m[A[i]]++;
  }
  int total = 0;
  for (const auto it : m) {
    total += choose2(it.second);
  }
  rep(i, N) {
    int n = m[A[i]];
    wt(total - choose2(n) + choose2(n - 1));
  }
}
