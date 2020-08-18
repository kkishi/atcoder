#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, s.size() - 2) {
    if (s.substr(i, 3) == "ABC") ++ans;
  }
  wt(ans);
}
