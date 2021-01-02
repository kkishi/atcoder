#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(int, D);
  vector<int> c(26);
  rep(i, 26) cin >> c[i];
  vector<vector<int>> s(D, vector<int>(26));
  rep(i, D) rep(j, 26) cin >> s[i][j];

  int sat = 0;
  vector<int> last(26);
  rep(i, D) {
    int d = i + 1;
    int maxi = -big;
    int chosen;
    rep(j, 26) {
      int change = s[i][j];
      rep(k, 26) {
        int last_day = k == j ? d : last[k];
        change -= c[k] * (d - last_day);
      }
      // HACK
      change += (d - last[j]) * c[j] * 6;
      if (chmax(maxi, change)) {
        chosen = j;
      }
    }
    last[chosen] = d;
    sat += maxi;
    dbg(sat, maxi, chosen);
#if DEBUG
    rep(i, 26) {
      if (i) cerr << " ";
      cerr << last[i];
    }
    cerr << endl;
#endif
    wt(chosen + 1);
  }
  dbg(max(1000000 + sat, 0));
}
