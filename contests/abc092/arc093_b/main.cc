#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  const int N = 100;
  VV<bool> white(N, V<bool>(N));
  rep(col, N / 2, N) rep(row, 0, N) white[row][col] = true;
  if (a > 1) {
    for (int col = 0; col < N; col += 2) {
      for (int row = 0; row < N; row += 2) {
        white[row][col] = true;
        --a;
        if (a == 1) goto out1;
      }
    }
  }
out1:
  if (b > 1) {
    for (int col = N / 2 + 1; col < N; col += 2) {
      for (int row = 0; row < N; row += 2) {
        white[row][col] = false;
        --b;
        if (b == 1) goto out2;
      }
    }
  }
out2:
  wt(N, N);
  rep(i, N) {
    rep(j, N) cout << (white[i][j] ? '.' : '#');
    cout << endl;
  }
}
