#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  int ans = 10000;
  rep(i, s.size() - 2) ans = min(ans, abs(stoi(s.substr(i, 3)) - 753));
  wt(ans);
}
