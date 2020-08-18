#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  map<string, ll> m;
  rep(i, n) {
    strings(s);
    sort(all(s));
    ++m[s];
  }
  ll ans = 0;
  for (auto [_, cnt] : m) {
    ans += cnt * (cnt - 1) / 2;
  }
  wt(ans);
}
