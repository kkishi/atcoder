#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  vector<vector<bool>> connected(m, vector(n, false));
  rep(i, m) {
    rd(int, k);
    while (k--) {
      rd(int, s);
      connected[i][s - 1] = true;
    }
  }
  vector<int> p(m);
  cin >> p;
  int ans = 0;
  rep(s, 1 << n) {
    rep(i, m) {
      int cnt = 0;
      rep(j, n) {
        if (connected[i][j] && ((s >> j) & 1)) {
          ++cnt;
        }
      }
      if (cnt % 2 != p[i]) goto next;
    }
    ++ans;
  next:
    continue;
  }
  wt(ans);
}
