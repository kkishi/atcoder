#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(h, w, a, b);
  mint ans = mint::Comb((h - 1) + (w - 1), (h - 1));
  rep(i, a) {
    ans -= mint::Comb((h - 1) - i + (b - 1), (b - 1)) *
           mint::Comb(i + w - b - 1, i);
  }
  wt(ans);
}
