#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int cnt[1000001];

int main() {
  rd(int, n);
  rep(i, n) {
    rd(int, a);
    ++cnt[a];
  }
  for (int i = 1; i <= 1000000; ++i) {
    if (cnt[i] == 0) continue;
    if (cnt[i] > 1) cnt[i] = 0;
    for (int j = i * 2; j <= 1000000; j += i) {
      cnt[j] = 0;
    }
  }
  int ans = 0;
  rep(i, 1000001) ans += cnt[i];
  wt(ans);
}
