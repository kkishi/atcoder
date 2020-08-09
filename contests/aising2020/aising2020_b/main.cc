#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  int ans = 0;
  rep(i, n) {
    rd(int, a);
    if (((i + 1) & 1) && (a & 1)) {
      ++ans;
    }
  }
  wt(ans);
}
