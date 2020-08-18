#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  s += ' ';
  int ans = 0;
  rep(i, s.size() - 1) {
    if (s[i + 1] != s[i]) ++ans;
  }
  wt(ans);
}
