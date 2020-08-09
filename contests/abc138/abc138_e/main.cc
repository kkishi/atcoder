#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s, t);
  s = s + s;
  vector<ll> last(26, -1);
  vector<vector<ll>> next(s.size(), vector(26, 0LL));
  for (int i = s.size() - 1; i >= 0; --i) {
    last[s[i] - 'a'] = i;
    rep(j, 26) {
      // dbg((char)('a'+j), last[j]);
      next[i][j] = last[j] == -1 ? -1 : last[j] - i;
    }
  }
  ll ans = 0;
  ll si = 0;
  rep(i, t.size()) {
    ll n = next[si][t[i] - 'a'];
    // dbg(t[i], n);
    if (n == -1) {
      wt(-1);
      return 0;
    }
    ans += n + 1;
    si = (si + n + 1) % (s.size() / 2);
    // dbg(si);
  }
  wt(ans);
}
