#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

bool OK(ll N, ll K) {
  while (N != 1) {
    if (N % K == 0) {
      N /= K;
      continue;
    } else if (N > K) {
      N %= K;
      continue;
    } else {
      return false;
    }
  }
  return true;
}

template <typename T>
map<T, int> factorize(T x) {
  map<T, int> m;
  for (T i = 2; i * i <= x;) {
    if (x % i == 0) {
      m[i]++;
      x /= i;
    } else {
      ++i;
    }
  }
  if (x > 1) m[x]++;
  return m;
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
  for (int i = 0; i < v; ++i) {
    K *= k;
    dfs(s, K, it, end);
  }
}

int main() {
  ll N;
  cin >> N;

  map<ll, int> f1 = factorize(N - 1);
  set<ll> s1;
  dfs(s1, 1, f1.begin(), f1.end());

  map<ll, int> f2 = factorize(N);
  set<ll> s2;
  dfs(s2, 1, f2.begin(), f2.end());

  ll ans = s1.size();
  for (ll x : s2) {
    if (OK(N, x)) {
      ++ans;
    }
  }
  cout << ans << endl;
}
