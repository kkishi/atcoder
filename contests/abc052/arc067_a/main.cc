#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  map<int, int> fs;
  rep(i, 2, n + 1) for (auto [k, v] : Factorize(i)) fs[k] += v;
  mint ans = 1;
  for (auto [_, v] : fs) ans *= v + 1;
  wt(ans);
}
