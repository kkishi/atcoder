#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  int ans = 0;
  rep(n) {
    ints(l, r);
    ans += r - l + 1;
  }
  wt(ans);
}
