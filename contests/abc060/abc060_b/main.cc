#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(a, b, c);
  bool ok = false;
  rep(i, 1, 100) if (a * i % b == c) ok = true;
  wt(ok ? "YES" : "NO");
}
