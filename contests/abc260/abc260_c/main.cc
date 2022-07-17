#include <bits/stdc++.h>

#include "atcoder.h"

int x, y;

int blue(int n);
int red(int n) { return n == 1 ? 0 : red(n - 1) + x * blue(n); }
int blue(int n) { return n == 1 ? 1 : red(n - 1) + y * blue(n - 1); }

void Main() {
  ints(n);
  cin >> x >> y;
  wt(red(n));
}
