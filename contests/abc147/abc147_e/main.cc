#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int h, w;
int a[80][80];
int b[80][80];

const int kMax = 80 * 80 * 2;
using bs = bitset<kMax * 2 + 1>;
bs dp[81][81];

int main() {
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];
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
