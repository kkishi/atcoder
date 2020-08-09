#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  if (!n) {
    wt(0);
    return 0;
  }
  string ans;
  ll bit = 1;
  while (n) {
    if (abs(n) % 2 == 1) {
      n -= 1;
      ans = '1' + ans;
    } else {
      ans = '0' + ans;
    }
    n /= -2;
    bit <<= 1;
  }
  wt(ans);
}
