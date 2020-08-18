#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int digits(int x) {
  int ret = 0;
  while (x) {
    ++ret;
    x /= 10;
  }
  return ret;
}

int main() {
  ints(n);
  int ans = 0;
  rep(i, n) if (digits(i + 1) % 2 == 1)++ ans;
  wt(ans);
}
