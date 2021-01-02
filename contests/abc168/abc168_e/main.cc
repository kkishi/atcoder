#include <bits/stdc++.h>

#include "atcoder.h"
#include "modint.h"
#include "rational.h"

using mint = ModInt<>;
using rat = Rational<int>;

bool operator<(const rat& a, const rat& b) {
  if (a.p() != b.p()) {
    return a.p() < b.p();
  }
  return a.q() < b.q();
}

map<rat, int> s1;
map<rat, int> s2;

void Main() {
  ints(N);

  int zeros = 0;

  int A_zeros = 0;
  int B_zeros = 0;

  rep(i, N) {
    ints(A, B);

    if (A == 0 && B == 0) {
      ++zeros;
      continue;
    }
    if (A == 0) {
      ++A_zeros;
      continue;
    }
    if (B == 0) {
      ++B_zeros;
      continue;
    }

    s1[rat(-B, A)]++;
    s2[rat(A, B)]++;
  }

  vector<pair<int, int>> groups;
  for (auto [r, c2] : s2) {
    int c1 = s1[r];
    if (c1 != 0 && r.p() < 0) continue;
    groups.pb({c2, c1});
  }
  groups.pb({A_zeros, B_zeros});

  mint mul = 1;
  for (auto [a, b] : groups) {
    mint m;
    if (b == 0) {
      m = mint(2).Pow(a);
    } else {
      m = mint(2).Pow(a) + mint(2).Pow(b) - 1;
    }
    mul *= m;
  }
  wt(mul - 1 + zeros);
}
