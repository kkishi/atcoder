#include <bits/stdc++.h>

#include "grid.h"
#include "macros.h"

using namespace std;

int main() {
  ints(h, w);
  V<string> s(h);
  cin >> s;

  Grid<int> g(h, w);
  rep(i, h) rep(j, w) g.Set(i, j, (s[i][j] == '#' ? -1 : 1));
  optional<int> d = g.Distance(0, 0, h - 1, w - 1);
  if (!d) {
    wt(-1);
  } else {
    int black = 0;
    rep(i, h) black += count(all(s[i]), '#');
    wt(h * w - black - *d - 1);
  }
}
