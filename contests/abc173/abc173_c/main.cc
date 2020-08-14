#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, h, w, k);
  vector<string> c(h);
  cin >> c;
  int ans = 0;
  rep(hs, 1 << h) rep(ws, 1 << w) {
    int black = 0;
    rep(i, h) rep(j, w) {
      bool red = ((hs >> i) & 1) || ((ws >> j) & 1);
      if (c[i][j] == '#' && !red) ++black;
    }
    if (black == k) ++ans;
  }
  wt(ans);
}
