#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, c, k);
  int m = max({a, b, c});
  int ans = a + b + c - m;
  rep(i, k) m *= 2;
  wt(ans + m);
}
