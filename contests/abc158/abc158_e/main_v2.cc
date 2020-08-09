#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int kMax = 2 * 100000;
ll tens[kMax];
ll cnt[10000];

int main() {
  ll N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  int p[] = {2, 5};
  rep(i, 2) if (P == p[i]) {
    ll cnt = 0;
    rep(j, S.size()) if ((S[j] - '0') % p[i] == 0) { cnt += j + 1; }
    cout << cnt << endl;
    return 0;
  }

  // dbg(N, S, P);

  tens[0] = 1;
  for (int i = 1; i < kMax; ++i) {
    tens[i] = tens[i - 1] * 10 % P;
    // dbg(i, tens[i]);
  }

  ll mod = 0;
  map<ll, ll> cnt;
  reverse(all(S));
  rep(i, N) {
    mod = (mod + (S[i] - '0') * tens[i]) % P;
    cnt[mod]++;
    dbg(S[i], mod, cnt[mod]);
  }
  ll ans = 0;
  for (auto it : cnt) {
    ll k, v;
    tie(k, v) = it;
    if (k != 0) --v;
    ans += v * (v + 1) / 2;
  }
  cout << ans << endl;
}
