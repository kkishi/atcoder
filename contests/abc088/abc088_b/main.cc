#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  V<int> a(n);
  cin >> a;
  sort(all(a), greater());
  int alice = 0, bob = 0;
  rep(i, n)((i & 1) ? bob : alice) += a[i];
  wt(alice - bob);
}
