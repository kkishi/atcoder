#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b);
  if (a == b) {
    wt(0);
  } else if ((a + b) % 2 == 0) {
    wt((a + b) / 2);
  } else {
    wt("IMPOSSIBLE");
  }
}
