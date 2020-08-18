#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  s += ' ';
  int ans = 0;
  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i + 1] != s[i]) ++ans;
  }
  wt(ans);
}
