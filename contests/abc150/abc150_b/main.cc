#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  int ans = 0;
  for (int i = 0; i < s.size() - 2; ++i) {
    if (s.substr(i, 3) == "ABC") ++ans;
  }
  wt(ans);
}
