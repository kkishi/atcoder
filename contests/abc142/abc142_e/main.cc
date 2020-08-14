#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Key {
  int price;
  int bits;
};

const int INF = 1 << 30;

int main() {
  rd(int, n, m);
  vector<Key> keys(m);
  rep(i, m) {
    rd(int, a, b);
    keys[i].price = a;
    rep(j, b) {
      rd(int, c);
      keys[i].bits |= 1 << (c - 1);
    }
  }
  vector<int> dp(1 << n, INF);
  dp[0] = 0;
  rep(bits, (1 << n)) {
    rep(i, m) chmin(dp[bits | keys[i].bits], dp[bits] + keys[i].price);
  }
  int ans = dp[(1 << n) - 1];
  if (ans == INF) {
    wt(-1);
  } else {
    wt(ans);
  }
}
