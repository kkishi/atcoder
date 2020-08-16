#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  rd(int, n, k);
  V<int> p(n), c(n);
  cin >> p >> c;
  int ans = numeric_limits<int>::min();
  rep(init, n) {
    V<int> score(n, -1);
    V<int> prev(n, -1);
    score[init] = 0;
    prev[init] = 0;
    int pos = init;
    int curs = 0;
    for (int move = 1; move <= k; ++move) {
      int npos = p[pos] - 1;
      curs += c[npos];
      chmax(ans, curs);
      int ps = score[npos];
      if (ps == -1) {
        score[npos] = curs;
        prev[npos] = move;
        pos = npos;
        continue;
      }
      if (curs <= ps) {
        chmax(ans, curs);
        break;
      }
      int pm = prev[npos];
      int rk = k - move;
      int lm = move - pm;
      if (lm <= rk) {
        int repeat = rk / lm;
        if (repeat >= 2) {
          --repeat;
          curs += repeat * (curs - ps);
          move += repeat * lm;
          chmax(ans, curs);
        }
      }
      score[npos] = curs;
      prev[npos] = move;
      pos = npos;
    }
  }
  wt(ans);
#undef int
}
