#include <bits/stdc++.h>

#include <atcoder/convolution>

#include "atcoder.h"

using ll = long long;

void Main() {
  ints(n);
  strings(s, t);
  reverse(all(s));
  string rgb = "RGB";
  map<char, V<ll>> C;
  each(e, rgb) C[e].resize(n * 2 - 1);
  each(e, rgb) each(f, rgb) {
    if (e > f) continue;
    V<ll> S(n), T(n);
    char to;
    if (e == f) {
      to = e;
      rep(i, n) {
        S[i] = s[i] == e;
        T[i] = t[i] == e;
      }
    } else {
      to = 'R' + 'G' + 'B' - e - f;
      rep(i, n) {
        S[i] = s[i] == e ? 1 : s[i] == f ? -1 : 0;
        T[i] = t[i] == e ? -1 : t[i] == f ? 1 : 0;
      }
    }
    V<ll> c = atcoder::convolution(T, S);
    rep(i, sz(c)) C[to][i] += c[i];
  }
  int ans = 0;
  each(_, c, C) rep(i, sz(c)) {
    int x = i + 1;
    if (x > n) x = 2 * n - x;
    if (c[i] == x) ++ans;
  }
  wt(ans);
}
