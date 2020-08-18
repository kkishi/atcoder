#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  bool ok = false;
  for (int i = 0; i * 4 <= n; ++i) {
    if ((n - i * 4) % 7 == 0) {
      ok = true;
    }
  }
  wt(ok);
}
