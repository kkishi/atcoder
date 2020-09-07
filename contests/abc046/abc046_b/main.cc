#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  int ans = k;
  rep(i, n - 1) ans *= k - 1;
  wt(ans);
}
