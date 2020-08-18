#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<int> p(n), q(n);
  cin >> p >> q;

  auto count = [&n](const V<int>& a) {
    V<int> x(n);
    rep(i, n) x[i] = i + 1;
    int c = 0;
    do {
      bool ok = true;
      rep(i, n) if (x[i] != a[i]) ok = false;
      if (ok) return c;
      ++c;
    } while (next_permutation(all(x)));
  };
  wt(abs(count(p) - count(q)));
}
