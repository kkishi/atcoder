#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;
  int mir = big, mar = -big, mic = big, mac = -big;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') {
      chmin(mir, i);
      chmax(mar, i);
      chmin(mic, j);
      chmax(mac, j);
    }
  }
  rep(i, mir, mar + 1) rep(j, mic, mac + 1) if (s[i][j] == '.') {
    wt(i + 1, j + 1);
  }
}
