#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  V<int> a(n);
  cin >> a;
  sort(all(a));
  wt(a[n - m] * 4 * m >= accumulate(all(a), 0));
}
