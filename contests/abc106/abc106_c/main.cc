#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  rd(int, k);
  rep(i, s.size()) {
    if (k == 1 || s[i] != '1') {
      wt(s[i]);
      return 0;
    }
    --k;
  }
}
