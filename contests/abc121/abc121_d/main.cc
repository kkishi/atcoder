#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

ll y(ll x) {
  switch (x % 4) {
    case 0:
      return x;
    case 1:
      return 1;
    case 2:
      return x + 1;
    default:
      return 0;
  }
}

int main() {
  rd(ll, a, b);
  wt(y(b) ^ y(a - 1));
}
