#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, v, b, w, t);
  if (w >= v) {
    wt("NO");
    return 0;
  }
  if (abs(a - b) <= t * abs(v - w)) {
    wt("YES");
  } else {
    wt("NO");
  }
}
