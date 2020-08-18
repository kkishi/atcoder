#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(x, y);
  bool ok = false;
  rep(t, 101) rep(k, 101) {
    if (t + k == x && 2 * t + 4 * k == y) ok = true;
  }
  wt(ok);
}
