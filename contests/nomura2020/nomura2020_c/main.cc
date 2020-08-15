#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll solve() {
  rd(int, N);
  V<ll> A(N + 1);
  cin >> A;

  if (N == 0) return A[0] == 1 ? 1 : -1;

  V<ll> maxi(100001);
  maxi[0] = 1;
  rep(i, N) {
    if (maxi[i] - A[i] < 0) return -1;
    maxi[i + 1] = min((maxi[i] - A[i]) * 2, 100000000000000000LL);
  }

  if (A[0] > 0 || maxi[N] < A[N]) return -1;

  ll nodes = A[N];
  ll ans = A[N];
  rrep(i, N) {
    if (nodes / 2 + nodes % 2 + A[i] > maxi[i]) return -1;
    nodes = min(nodes + A[i], maxi[i]);
    ans += nodes;
  }
  return ans;
}

int main() { wt(solve()); }
