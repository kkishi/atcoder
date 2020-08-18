#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s, t);
  s += s;
  V<ll> last(26, -1);
  VV<ll> next(s.size(), V<ll>(26));
  rrep(i, s.size()) {
    last[s[i] - 'a'] = i;
    rep(j, 26) next[i][j] = last[j] == -1 ? -1 : last[j] - i;
  }
  ll ans = 0;
  ll si = 0;
  rep(i, t.size()) {
    ll n = next[si][t[i] - 'a'];
    if (n == -1) {
      wt(-1);
      return 0;
    }
    ans += n + 1;
    si = (si + n + 1) % (s.size() / 2);
  }
  wt(ans);
}
