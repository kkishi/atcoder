#include <bits/stdc++.h>

#include "atcoder.h"

string hand = "rsp";
map<char, int> score;

int Score(char t, char m) {
  if ((hand.find(t) + 1) % 3 == hand.find(m)) {
    return score[t];
  }
  return 0;
}

int solve(const string& t) {
  vector<int> curr(3), prev(3);
  rep(i, t.size()) {
    rep(j, 3) {
      rep(k, 3) {
        if (k != j) {
          chmax(curr[j], prev[k]);
        }
      }
      curr[j] += Score(hand[j], t[i]);
    }
    swap(curr, prev);
  }
  int ret = 0;
  rep(i, 3) chmax(ret, prev[i]);
  return ret;
}

void Main() {
  ints(n, k);
  rep(i, 3) cin >> score[hand[i]];
  strings(t);
  vector<string> ts(k);
  rep(i, t.size()) { ts[i % k] += t[i]; }
  int ans = 0;
  rep(i, k) { ans += solve(ts[i]); }
  wt(ans);
}
