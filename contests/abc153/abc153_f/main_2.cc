#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const { return X < m.X; }
};

Monster monster[200000];

ll Add(ll a, ll b) { return a + b; }

int main() {
  rd(ll, N, D, A);
  rep(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  ll ans = 0;
  queue<pair<ll, ll>> que;
  ll damage_sum = 0;
  rep(i, N) {
    while (!que.empty() && que.front().first < monster[i].X) {
      damage_sum -= que.front().second;
      que.pop();
    }
    ll remaining = monster[i].H - damage_sum;
    if (remaining > 0) {
      ll cnt = (remaining + A - 1) / A;
      ans += cnt;
      damage_sum += cnt * A;
      que.push({monster[i].X + 2 * D, cnt * A});
    }
  }
  wt(ans);
}
