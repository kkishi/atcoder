#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(x);
  int ans = 0;
  for (int y = 1; y * 100 <= x; ++y) {
    if (x - y * 100 <= 5 * y) {
      ans = 1;
    }
  }
  wt(ans);
}
