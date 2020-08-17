#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"

using namespace std;

ll n, m;
ll a[100000];
ll s[100001];

pair<ll, ll> count(ll x) {
  ll cnt = 0;
  ll sum = 0;
  rep(i, n) {
    ll lb = lower_bound(a, a + n, x - a[i]) - a;
    cnt += n - lb;
    sum += s[lb] + (n - lb) * a[i];
  }
  return {cnt, sum};
}

int main() {
  cin >> n >> m;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  rrep(i, n) s[i] = s[i + 1] + a[i];

  ll x = BinarySearch<ll>(0, a[n - 1] * 2 + 1,
                          [&](ll x) { return count(x).first >= m; });
  auto p = count(x);
  wt(p.second - (p.first - m) * x);
}
