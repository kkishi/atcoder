#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;
#include "rational.h"

using namespace std;

using rat = Rational<ll>;

bool operator<(const rat& a, const rat& b) {
  if (a.p() != b.p()) {
    return a.p() < b.p();
  }
  return a.q() < b.q();
}

map<rat, int> s1;
map<rat, int> s2;

int main() {
  ints(N);

  ll zeros = 0;

  ll A_zeros = 0;
  ll B_zeros = 0;

  rep(i, N) {
    rd(ll, A, B);

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
    groups.push_back({c2, c1});
  }
  groups.push_back({A_zeros, B_zeros});

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
