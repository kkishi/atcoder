#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

bool OK(ll N, ll K) {
  while (N != 1) {
    if (N % K == 0) {
      N /= K;
      continue;
    } else if (N > K) {
      N %= K;
      continue;
    }
    return false;
  }
  return true;
}

using iter = map<ll, int>::const_iterator;

void dfs(set<ll>& s, ll K, iter it, iter end) {
  if (it == end) {
    if (K > 1) {
      s.insert(K);
    }
    return;
  }
  auto [k, v] = *it;
  ++it;
  dfs(s, K, it, end);
  rep(i, v) {
    K *= k;
    dfs(s, K, it, end);
  }
}

int main() {
  rd(ll, N);

  map<ll, int> f1 = Factorize(N - 1);
  set<ll> s1;
  dfs(s1, 1, all(f1));

  map<ll, int> f2 = Factorize(N);
  set<ll> s2;
  dfs(s2, 1, all(f2));

  ll ans = s1.size();
  for (ll x : s2) {
    if (OK(N, x)) {
      ++ans;
    }
  }
  wt(ans);
}
