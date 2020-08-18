#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b);
  bool ok = false;
  rep(i, 3) if (a * (i + 1) * b % 2 == 1) ok = true;
  wt(ok);
}
