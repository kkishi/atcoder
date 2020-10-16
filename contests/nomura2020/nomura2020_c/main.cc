#include <bits/stdc++.h>

#include "atcoder.h"

int solve() {
  ints(N);
  V<int> A(N + 1);
  cin >> A;

  if (N == 0) return A[0] == 1 ? 1 : -1;

  V<int> maxi(100001);
  maxi[0] = 1;
  rep(i, N) {
    if (maxi[i] - A[i] < 0) return -1;
    maxi[i + 1] = min((maxi[i] - A[i]) * 2, 100000000000000000LL);
  }

  if (A[0] > 0 || maxi[N] < A[N]) return -1;

  int nodes = A[N];
  int ans = A[N];
  rrep(i, N) {
    if (nodes / 2 + nodes % 2 + A[i] > maxi[i]) return -1;
    nodes = min(nodes + A[i], maxi[i]);
    ans += nodes;
  }
  return ans;
}

void Main() { wt(solve()); }
