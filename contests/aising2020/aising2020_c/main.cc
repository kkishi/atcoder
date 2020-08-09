#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int s(int x) { return x * x; }
int v(int x, int y, int z) {
  return s(x) + s(y) + s(z) + x * y + y * z + z * x;
}

int main() {
  rd(int, n);
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int x = 1; v(x, 1, 1) <= i; ++x) {
      for (int y = 1; v(x, y, 1) <= i; ++y) {
        for (int z = 1; v(x, y, z) <= i; ++z) {
          if (v(x, y, z) == i) ++ans;
        }
      }
    }
    wt(ans);
  }
}
