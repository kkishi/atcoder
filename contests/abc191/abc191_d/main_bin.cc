#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  rd(long double, X, Y, R);
  const int c = 10000;
  int x = round(X * c) + 200000 * c;
  int y = round(Y * c) + 200000 * c;
  int r = round(R * c);

  auto floor = [&](int x) { return x - x % c; };
  auto ceil = [&](int x) { return floor(x + c - 1); };
  int lx = ceil(x - r);
  int hx = floor(x + r);

  int ans = 0;
  for (int xi = lx; xi <= hx; xi += c) {
    int d = abs(x - xi);
    int y2 = r * r - d * d;
    int l = BinarySearch<int>(y, -1, [&](int z) {
      int dy = y - z;
      return dy * dy <= y2;
    });
    int L = ceil(l);
    int h = BinarySearch<int>(y, 400000 * c + 1, [&](int z) {
      int dy = z - y;
      return dy * dy <= y2;
    });
    int H = floor(h);
    if (H >= L) ans += (H - L) / c + 1;
  }
  wt(ans);
}
