#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b);
  rep(i, 3) if (a * (i + 1) * b % 2 == 1) {
    wt("Yes");
    return 0;
  }
  wt("No");
}
