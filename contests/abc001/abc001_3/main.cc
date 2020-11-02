#include <bits/stdc++.h>

#include "atcoder.h"

string dir(int deg) {
  V<string> a{"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S",
              "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
  rep(i, sz(a)) {
    int l = 1125 * (i * 2 + 1);
    int r = 1125 * ((i + 1) * 2 + 1);
    if (l <= deg && deg < r) return a[i];
  }
  return "N";
}

int w(int dis) {
  dis = int((dis / 60.0) * 10 + 0.5 + 1e-10) * 10;
  V<double> v = {20,   150,  330,  540,  790,  1070,
                 1380, 1710, 2070, 2440, 2840, 3260};
  rep(i, sz(v)) if (dis <= v[i]) return i;
  return 12;
}

void Main() {
  ints(deg, dis);
  int x = w(dis);
  if (x == 0) {
    wt("C 0");
  } else {
    wt(dir(deg * 10), x);
  }
}
