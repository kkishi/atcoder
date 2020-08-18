#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(X, Y, A, B, C);
  V<int> p(A), q(B), r(C);
  cin >> p >> q >> r;

  sort(all(p));
  sort(all(q));
  sort(all(r));

  int ai = A - X;
  int bi = B - Y;
  int ci = C;
  while (true) {
    if (ci == 0) {
      break;
    }
    bool a = ai < A && p[ai] < r[ci - 1];
    bool b = bi < B && q[bi] < r[ci - 1];
    if (!a && !b) {
      break;
    }
    if (a && (!b || p[ai] < q[bi])) {
      ++ai;
    } else {
      ++bi;
    }
    --ci;
  }

  long long ans = 0;
  rep(i, ai, A) ans += p[i];
  rep(i, bi, B) ans += q[i];
  rep(i, ci, C) ans += r[i];
  wt(ans);
}
