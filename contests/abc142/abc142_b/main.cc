#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  int ans = 0;
  rep(i, n) {
    rd(int, h);
    if (h >= k) ++ans;
  }
  wt(ans);
}
