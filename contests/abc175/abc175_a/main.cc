#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  int ans = 0, cont = 0;
  rep(i, 3) {
    if (s[i] == 'R') {
      ++cont;
    } else {
      cont = 0;
    }
    chmax(ans, cont);
  }
  wt(ans);
}
