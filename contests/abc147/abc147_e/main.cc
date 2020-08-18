#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int kMax = 80 * 80 * 2;
using bs = bitset<kMax * 2 + 1>;
bs dp[81][81];

int main() {
  ints(h, w);
  VV<int> a(h, V<int>(w)), b = a;
  cin >> a >> b;
  dp[0][1][kMax] = 1;
  rep(i, h) rep(j, w) {
    int d = abs(a[i][j] - b[i][j]);
    bs b = (dp[i][j + 1] | dp[i + 1][j]);
    dp[i + 1][j + 1] = (b << d) | (b >> d);
  }
  rep(i, 80 * 80 * 40 + 1) if (dp[h][w][i + kMax]) {
    wt(i);
    return 0;
  }
}
