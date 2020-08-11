#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  rd(string, s);
  int ans = 0;
  rep(i, n + 1) {
    set<char> a, b;
    rep(j, n)(j < i ? a : b).insert(s[j]);
    int cnt = 0;
    for (char c : a)
      if (b.count(c)) ++cnt;
    ans = max(ans, cnt);
  }
  wt(ans);
}
