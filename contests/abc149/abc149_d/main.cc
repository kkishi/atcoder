#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

string hand = "rsp";
map<char, ll> score;

ll Score(char t, char m) {
  if ((hand.find(t) + 1) % 3 == hand.find(m)) {
    return score[t];
  }
  return 0;
}

ll solve(const string& t) {
  vector<ll> curr(3), prev(3);
  rep(i, t.size()) {
    rep(j, 3) {
      rep(k, 3) {
        if (k != j) {
          curr[j] = max(curr[j], prev[k]);
        }
      }
      curr[j] += Score(hand[j], t[i]);
    }
    swap(curr, prev);
  }
  ll ret = 0;
  rep(i, 3) ret = max(ret, prev[i]);
  return ret;
}

int main() {
  rd(ll, n, k);
  rep(i, 3) cin >> score[hand[i]];
  rd(string, t);
  vector<string> ts(k);
  rep(i, t.size()) { ts[i % k] += t[i]; }
  ll ans = 0;
  rep(i, k) { ans += solve(ts[i]); }
  wt(ans);
}
