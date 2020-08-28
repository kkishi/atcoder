#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  rep(2) {
    while (true) {
      int open = 0;
      bool ok = true;
      for (char c : s) {
        if (c == '(') {
          ++open;
        } else if (open == 0) {
          ok = false;
          break;
        } else {
          --open;
        }
      }
      if (ok) break;
      s = '(' + s;
    }
    reverse(all(s));
    rep(i, sz(s)) s[i] = s[i] == '(' ? ')' : '(';
  }
  wt(s);
}
