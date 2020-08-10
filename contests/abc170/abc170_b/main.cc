#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, x, y);
  rep(t, 101) rep(k, 101) {
    if (t + k == x && 2 * t + 4 * k == y) {
      wt("Yes");
      return 0;
    }
  }
  wt("No");
}
