#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(sx, sy, tx, ty);
  int dx = tx - sx, dy = ty - sy;
  V<pair<char, int>> v{{'U', dy}, {'R', dx},     {'D', dy},     {'L', dx},
                       {'L', 1},  {'U', dy + 1}, {'R', dx + 1}, {'D', 1},
                       {'R', 1},  {'D', dy + 1}, {'L', dx + 1}, {'U', 1}};
  for (auto [c, x] : v) rep(x) cout << c;
  cout << endl;
}
