#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  mint ans = 1;
  rep(i, n) ans *= i + 1;
  wt(ans);
}
