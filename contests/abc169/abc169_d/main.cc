#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  ll N;
  cin >> N;
  map<ll, int> m = Factorize(N);
  int ans = 0;
  for (const auto p : m) {
    dbg(p.first, p.second);
    int x = p.second;
    for (int i = 1; i <= x; ++i) {
      x -= i;
      ++ans;
      dbg(i, x);
    }
  }
  wt(ans);
}
