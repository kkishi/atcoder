#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "i128.h"

void Main() {
  ints(n, q, x);
  V<int> w(n);
  cin >> w;
  int tot = accumulate(w);
  V<int> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + w[i];

  int N = 50;
  vector dbl(N, vector(n, i128(0)));
  rep(i, n) {
    i128 y = BinarySearch<i128>(0, x + 1, [&](i128 y) {
      auto f = [&](i128 z) { return z / n * tot + s[(z % n)]; };
      i128 z = f(y + i) - f(i);
      return z < x;
    });
    dbl[0][i] = y + 1;
  }
  rep(i, N - 1) {
    rep(j, n) {
      i128 y = dbl[i][j];
      y += dbl[i][(j + y) % n];
      dbl[i + 1][j] = y;
    }
  }
  rep(q) {
    auto f = [&](int k) {
      i128 p = 0;
      i128 s = 0;
      rep(j, N) if (hasbit(k, j)) {
        i128 y = dbl[j][p];
        p = (p + y) % n;
        s += y;
      }
      return s;
    };
    ints(k);
    wt(f(k) - f(k - 1));
  }
}
