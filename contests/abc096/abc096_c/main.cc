#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
  rd(int, h, w);
  V<string> s(h);
  rep(r, h) cin >> s[r];
  VV<bool> b(h + 2, V<bool>(w + 2));
  rep(r, h) rep(c, w) b[r + 1][c + 1] = s[r][c] == '#';
  rep(r, h) rep(c, w) if (b[r + 1][c + 1]) {
    bool ok = false;
    rep(i, 4) if (b[r + 1 + dr[i]][c + 1 + dc[i]]) ok = true;
    if (!ok) {
      wt("No");
      return 0;
    }
  }
  wt("Yes");
}
