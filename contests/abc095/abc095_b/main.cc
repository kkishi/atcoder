#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, x);
  V<int> m(n);
  rep(i, n) cin >> m[i];
  wt((x - accumulate(all(m), 0)) / *min_element(all(m)) + n);
}
