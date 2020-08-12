#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  rd(ll, n, m);
  map<ll, int> fs = Factorize(m);
  mint ans = 1;
  for (auto [_, v] : fs) {
    ans *= mint::Comb(n - 1 + v, n - 1);
  }
  wt(ans);
}
