#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n, m);

  V<int> ox(n), oy(m);
  cin >> ox >> oy;
  sort(all(ox));
  sort(all(oy));

  V<mint> x, y;
  rep(i, n - 1) x.push_back(ox[i + 1] - ox[i]);
  rep(i, m - 1) y.push_back(oy[i + 1] - oy[i]);

  mint x2 = 0;
  rep(i, sz(x)) x2 += x[i] * (i + 1) * (n - 1 - i);
  mint y2 = 0;
  rep(i, sz(y)) y2 += y[i] * (i + 1) * (m - 1 - i);
  wt(x2 * y2);
}