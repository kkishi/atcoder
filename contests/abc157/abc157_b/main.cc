#include <bits/stdc++.h>

#include "atcoder.h"

int A[3][3];

bool bingo() {
  rep(i, 3) {
    bool ok = true;
    rep(j, 3) if (A[i][j] > 0) ok = false;
    if (ok) return true;
  }
  rep(i, 3) {
    bool ok = true;
    rep(j, 3) if (A[j][i] > 0) ok = false;
    if (ok) return true;
  }
  {
    bool ok = true;
    rep(i, 3) {
      if (A[i][i] > 0) ok = false;
    }
    if (ok) return true;
  }
  {
    bool ok = true;
    rep(i, 3) {
      if (A[i][2 - i] > 0) ok = false;
    }
    if (ok) return true;
  }
  return false;
}

void Main() {
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  ints(N);
  rep(n, N) {
    ints(b);
    rep(i, 3) rep(j, 3) if (A[i][j] == b) A[i][j] = 0;
  }
  wt(bingo());
}
