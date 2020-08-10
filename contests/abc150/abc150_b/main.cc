#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  rd(string, s);
  int ans = 0;
  for (int i = 0; i < s.size() - 2; ++i) {
    if (s.substr(i, 3) == "ABC") ++ans;
  }
  wt(ans);
}
