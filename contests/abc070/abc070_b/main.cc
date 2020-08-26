#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, c, d);
  int ans = 0;
  rep(i, 0, 101) if (a <= i && i < b && c <= i && i < d)++ ans;
  wt(ans);
}
