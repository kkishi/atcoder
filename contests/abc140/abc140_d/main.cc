#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k);
  rd(string, s);
  int ans = 0;
  rep(i, n - 1) if (s[i] == s[i + 1])++ ans;
  wt(min(ans + k * 2, n - 1));
}
