#include <bits/stdc++.h>

#include <atcoder/convolution>
#include <atcoder/modint>

#include "atcoder.h"

using mint = atcoder::modint998244353;

template <typename T>
class comb {
 public:
  static T C(int n, int k) { return !valid(n, k) ? 0 : P(n, k) * inv_fact(k); }
  static T P(int n, int k) {
    return !valid(n, k) ? 0 : fact(n) * inv_fact(n - k);
  }

 private:
  static bool valid(i64 n, i64 k) { return 0 <= n && 0 <= k && k <= n; }
  static T fact(int n) {
    for (i64 i = fact_.size(); i <= n; ++i) {
      fact_.push_back(i == 0 ? 1 : fact_.back() * i);
    }
    return fact_[n];
  }
  static T inv(int n) {
    for (i64 i = inv_.size(); i <= n; ++i) {
      inv_.push_back(i <= 1 ? i : (T::mod() / i * -inv_[T::mod() % i]));
    }
    return inv_[n];
  }
  static T inv_fact(int n) {
    for (i64 i = inv_fact_.size(); i <= n; ++i) {
      inv_fact_.push_back(i == 0 ? 1 : inv_fact_.back() * inv(i));
    }
    return inv_fact_[n];
  }

  inline static V<T> fact_, inv_, inv_fact_;
};

using c = comb<mint>;

void Main() {
  ints(r, g, b, k, x, y, z);
  auto f = [&](int l, int h) {
    V<mint> v(k + 1);
    rep(i, k + 1) if (l <= i && i <= h) v[i] = c::C(h, i);
    return v;
  };
  vector R = f(k - y, r), G = f(k - z, g), B = f(k - x, b);
  wt(atcoder::convolution(atcoder::convolution(R, G), B)[k].val());
}
