#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, m, k);

  if (m == 0) {
    if (k == 0) {
      wt(0, 0);
    } else {
      wt(-1);
    }
    return 0;
  }
  if (m == 1) {
    if (k == 0) {
      wt(0, 0, 1, 1);
    } else {
      wt(-1);
    }
    return 0;
  }

  int pow2 = 1 << m;

  int xors = 0;
  rep(i, pow2) xors ^= i;
  dbg(xors);

  if (0 <= k && k < pow2) {
    for (int i = 0; i < pow2; ++i) {
      if (i == k) continue;
      cout << i << " ";
    }
    cout << k << " ";
    for (int i = pow2 - 1; i >= 0; --i) {
      if (i == k) continue;
      cout << i << " ";
    }
    cout << k << endl;
  } else {
    wt(-1);
  }
}
