#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"

using mint = ModInt<998244353>;

template <typename T>
class CumulativeSum {
 public:
  CumulativeSum(int h, int w, int dr, int dc)
      : h_(h), w_(w), dr_(dr), dc_(dc), v_(h_, std::vector<T>(w_)) {}
  void Add(T v, int r0, int c0, int n) {
    auto min_t = [](int a, int b, int mi, int ma) -> int {
      if (a == 0) {
        if (mi <= b && b <= ma) {
          return -big;
        } else {
          return big;
        }
      } else if (a > 0) {
        return div_ceil(-b, a);
      } else {  // a < 0
        return div_ceil(ma - b, a);
      }
    };
    int t0 = 0;
    chmax(t0, min_t(dr_, r0, 0, h_ - 1));
    chmax(t0, min_t(dc_, c0, 0, w_ - 1));
    if (t0 <= n) {
      if (int r = r0 + dr_ * t0, c = c0 + dc_ * t0; inside(r, c, h_, w_)) {
        v_[r][c] += v;
        if (int r = r0 + dr_ * n, c = c0 + dc_ * n; inside(r, c, h_, w_)) {
          v_[r][c] -= v;
        }
      }
    }
  }
  void Eval() {
    int r_begin = 0, r_end = h_, r_inc = 1;
    if (dr_ < 0) r_begin = h_ - 1, r_end = -1, r_inc = -1;
    int c_begin = 0, c_end = w_, c_inc = 1;
    if (dc_ < 0) c_begin = w_ - 1, c_end = -1, c_inc = -1;
    for (int r = r_begin; r != r_end; r += r_inc) {
      for (int c = c_begin; c != c_end; c += c_inc) {
        if (inside(r + dr_, c + dc_, h_, w_)) {
          v_[r + dr_][c + dc_] += v_[r][c];
        }
      }
    }
  }
  const std::vector<std::vector<T>>& v() const { return v_; };

 private:
  const int h_, w_, dr_, dc_;
  std::vector<std::vector<T>> v_;
};

void Main() {
  ints(n, d);
  V<int> p(n), q(n);
  cin >> p >> q;
  vector dp(d + 1, vector(d + 1, mint(0)));
  dp[0][0] = 1;
  rep(i, n) {
    /*
      x....
      ...b.
      a...b
      .a...
      ..a..
     */
    CumulativeSum<mint> cs0(d + 1, d + 1, 1, 1);
    /*
      x.c..
      .c...
      .....
      .....
      .....
     */
    CumulativeSum<mint> cs1(d + 1, d + 1, -1, 1);
    rep(j, d + 1) rep(k, d + 1) {
      const mint x = dp[j][k];
      if (x == 0) continue;
      const int s = abs(p[i] - q[i]);
      cs0.Add(x, j + s, k, d * 4);          // a in the diagram above.
      cs0.Add(x, j + 1, k + s + 1, d * 4);  // b in the diagram above.
      cs1.Add(x, j + s - 1, k + 1, s);      // c in the diagram above.
    }
    cs0.Eval();
    cs1.Eval();
    /*
      x.c..
      .c.b.
      a...b
      .a...
      ..a..
     */
    rep(j, d + 1) rep(k, d + 1) dp[j][k] = cs0.v()[j][k] + cs1.v()[j][k];
  }
  mint ans = 0;
  each(e, dp) ans += accumulate(e);
  wt(ans);
}
