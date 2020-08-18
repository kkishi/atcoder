#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int N, M;
int s[5], c[5];

bool ok(int i) {
  rep(m, M) {
    int j = i;
    rep(si, N - s[m]) j /= 10;
    if (i == 702) dbg(N, m, s[m], c[m], j);
    if (j % 10 != c[m]) return false;
  }
  return true;
}

int main() {
  cin >> N >> M;
  rep(i, M) cin >> s[i] >> c[i];

  int minimum = 1;
  rep(n, N - 1) minimum *= 10;
  if (N == 1) minimum = 0;
  int maximum = 1;
  rep(n, N) maximum *= 10;

  int ans = -1;
  rep(i, minimum, maximum) {
    if (ok(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
