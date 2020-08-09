#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  int ans = 0;
  while (s.size() > 1) {
    if (s[0] != s[s.size() - 1]) {
      ++ans;
    }
    s = s.substr(1, s.size() - 2);
  }
  wt(ans);
}
