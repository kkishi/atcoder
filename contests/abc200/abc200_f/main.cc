#include <bits/stdc++.h>

#include "atcoder.h"
#include "matrix.h"
#include "modint.h"

using mint = ModInt<>;
using mat = Matrix<mint, 4, 4>;
using vec = Matrix<mint, 4, 1>;

V<mat> f = []() {
  V<mat> f(3);
  f[0] = {{
      {1, 1, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 1, 1},
      {0, 0, 0, 0},
  }};
  f[1] = {{
      {0, 0, 0, 0},
      {1, 1, 1, 0},
      {0, 0, 0, 0},
      {0, 0, 1, 1},
  }};
  f[2] = Plus(f[0], f[1]);
  return f;
}();

mat prod(const string& s) {
  mat m = Identity<mint, 4>();
  each(e, s) m = Mult(f[e == '?' ? 2 : (e - '0')], m);
  return m;
}

void Main() {
  strings(s);
  ints(k);

  auto flip = [](string s) {
    each(e, s) if (e != '?') e ^= 1;
    return s;
  };

  vec a = {{
      {0},
      {0},
      {1},
      {0},
  }};

  if (s[0] == '?') {
    string s0 = s;
    s0[0] = '0';
    vec a0 = Mult(Mult(Pow(prod(s), k - 1), prod(s0)), a);

    string s1 = s;
    s1[0] = '1';
    vec a1 = Mult(Mult(Pow(prod(flip(s)), k - 1), prod(flip(s1))), a);

    a = Plus(a0, a1);
  } else {
    if (s[0] == '1') s = flip(s);
    a = Mult(Pow(prod(s), k), a);
  }
  wt(a[0][0] + a[1][0]);
}
