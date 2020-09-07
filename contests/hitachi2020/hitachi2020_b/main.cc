#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(A, B, m);
  V<int> a(A), b(B);
  cin >> a >> b;
  int ans = *min_element(all(a)) + *min_element(all(b));
  rep(m) {
    ints(x, y, c);
    chmin(ans, a[x - 1] + b[y - 1] - c);
  }
  wt(ans);
}
