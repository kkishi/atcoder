#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  for (;; ++n) {
    string s = to_string(n);
    bool ok = true;
    for (char c : s)
      if (c != s[0]) ok = false;
    if (ok) {
      wt(n);
      return 0;
    }
  }
}
