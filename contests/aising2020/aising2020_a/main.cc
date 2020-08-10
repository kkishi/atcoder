#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, l, r, d);
  int ans = 0;
  for (int i = l; i <= r; ++i) {
    if (i % d == 0) ++ans;
  }
  wt(ans);
}
