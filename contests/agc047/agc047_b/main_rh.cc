#include <bits/stdc++.h>

#include "macros.h"
#include "rolling_hash.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }
  sort(all(s), [](auto &a, auto &b) { return a.size() > b.size(); });

  ll ans = 0;
  unordered_map<RollingHash, array<int, 26>> m;
  for (auto &si : s) {
    vector<bitset<26>> cum(si.size() + 1);
    for (int i = si.size() - 1; i >= 0; --i) {
      cum[i] = cum[i + 1];
      cum[i].set(si[i] - 'a');
    }
    RollingHash h;
    rep(i, si.size() - 1) {
      rep(j, 26) {
        if (cum[i][j]) {
          m[h][j]++;
        }
      }
      h.Add(si[i]);
    }
    ans += m[h][si.back() - 'a'];
  }
  wt(ans);
}
