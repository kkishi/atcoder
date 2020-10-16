#include <bits/stdc++.h>

#include "atcoder.h"

int A[3][3];

bool bingo() {
  rep(i, 3) if (!A[i][0] && !A[i][1] && !A[i][2]) return true;
  rep(i, 3) if (!A[0][i] && !A[1][i] && !A[2][i]) return true;
  if (!A[0][0] && !A[1][1] && !A[2][2]) return true;
  if (!A[2][0] && !A[1][1] && !A[2][0]) return true;
  return false;
}

void Main() {
  rep(i, 3) rep(j, 3) cin >> A[i][j];
  int N;
  cin >> N;
  rep(n, N) {
    int b;
    cin >> b;
    rep(i, 3) rep(j, 3) if (A[i][j] == b) A[i][j] = 0;
  }
  wt(bingo());
}
