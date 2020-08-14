#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, k);
  vector<ll> a(n);
  cin >> a;
  map<ll, ll> seen;
  queue<ll> que;
  auto add = [&](ll x) {
    seen[x]++;
    que.push(x);
    if (que.size() == k) {
      ll y = que.front();
      dbg(x, y);
      que.pop();
      seen[y]--;
    }
  };
  add(0);
  ll sum = 0;
  ll ans = 0;
  rep(i, n) {
    sum += a[i];
    ll adj = (sum - (i + 1)) % k;
    ans += seen[adj];
    add(adj);
  }
  wt(ans);
}
