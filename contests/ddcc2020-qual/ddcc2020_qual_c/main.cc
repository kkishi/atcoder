#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w, k);
  V<string> s(h);
  cin >> s;
  VV<int> g(h, V<int>(w, -1));
  int ki = 0;
  V<int> last(h, -1);
  rep(i, h) rep(j, w) if (s[i][j] == '#') {
    ++ki;
    for (int k = j; k >= 0 && g[i][k] == -1; --k) {
      g[i][k] = ki;
    }
    last[i] = ki;
  }
  rep(i, h) if (g[i][w - 1] == -1 && last[i] != -1) {
    for (int k = w - 1; g[i][k] == -1; --k) {
      g[i][k] = last[i];
    }
  }
  rep(i, h) if (g[i][0] != -1) {
    for (int k = i - 1; k >= 0 && g[k][0] == -1; --k) {
      g[k] = g[i];
    }
    for (int k = i + 1; k < h && g[k][0] == -1; ++k) {
      g[k] = g[i];
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (j) cout << " ";
      cout << g[i][j];
    }
    cout << endl;
  }
}
