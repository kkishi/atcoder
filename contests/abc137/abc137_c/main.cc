#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  map<string, ll> m;
  rep(i, n) {
    rd(string, s);
    sort(all(s));
    ++m[s];
  }
  ll ans = 0;
  for (auto [_, cnt] : m) {
    ans += cnt * (cnt - 1) / 2;
  }
  wt(ans);
}
