#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, D);
  vector<int> c(26);
  rep(i, 26) cin >> c[i];
  vector<vector<int>> s(D, vector<int>(26));
  rep(i, D) rep(j, 26) cin >> s[i][j];

  int sat = 0;
  vector<int> last(26);
  rep(i, D) {
    rd(int, t);
    --t;
    int d = i + 1;
    last[t] = d;
    sat += s[i][t];
    rep(k, 26) { sat -= c[k] * (d - last[k]); }
    wt(sat);
  }
}
