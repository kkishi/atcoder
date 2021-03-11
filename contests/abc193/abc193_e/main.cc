#include <bits/stdc++.h>

#include "atcoder.h"
#include "extgcd.h"

int Solve() {
  ints(X, Y, P, Q);
  int oA = 2 * (X + Y);
  int oB = P + Q;
  int G = gcd(oA, oB);
  int ans = big;
  rep(dy, Y) rep(dq, Q) {
    int C = P + dq - (X + dy);
    C %= oB;
    if (C < 0) C += oB;
    if (C % G != 0) continue;
    int A = oA / G;
    int B = oB / G;
    C /= G;
    dbg(A, B, C);
    auto [G2, x, y] = ExtGcd(A, B);
    assert(G2 == 1);
    dbg(x, y);
    x *= C;
    y *= C;
    y = -y;
    dbg(x, y);
    if (x < 0) {
      int t = div_ceil(-x, B);
      x += B * t;
      y += A * t;
    }
    if (y < 0) {
      int t = div_ceil(-y, A);
      x += B * t;
      y += A * t;
    }
    {
      int t = max(x / B, y / A);
      x -= B * t;
      y -= A * t;
    }
    chmin(ans, A * x + X + dy);
  }
  return ans;
}

void Main() {
  ints(t);
  rep(t) {
    int ans = Solve();
    if (ans == big) {
      wt("infinity");
    } else {
      wt(ans);
    }
  }
}
