#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

template <typename T>
std::map<T, int> Factorize(T x) {
  std::map<T, int> m;
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

bool Divisable(const map<int, int>& n, const map<int, int>& d) {
  for (const auto p : d) {
    const auto it = n.find(p.first);
    int cnt = it == n.end() ? 0 : it->second;
    if (cnt < p.second) {
      return false;
    }
  }
  return true;
}

bool Eq(const map<int, int>& a, const map<int, int>& b) {
  if (a.size() != b.size()) return false;
  for (const auto p : a) {
    const auto it = b.find(p.first);
    if (it == b.end() || it->second != p.second) return false;
  }
  return true;
}

int main() {
  rd(int, n);
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<map<int, int>> fs(n);
  rep(i, n) { fs[i] = Factorize(a[i]); }
  map<map<int, int>, int> cnt;
  rep(i, n) { cnt[fs[i]]++; }
  for (const auto p : cnt) {
    dbg(p.second);
    for (auto kv : p.first) {
      dbg(kv.first, kv.second);
    }
  }
  ll ans = 0;
  rep(i, n) {
    bool ok = true;
    for (const auto p : cnt) {
      for (const auto kv : fs[i]) {
        dbg(kv.first, kv.second);
      }
      for (const auto kv : p.first) {
        dbg(kv.first, kv.second);
      }
      if (Eq(fs[i], p.first) && p.second == 1) continue;
      if (Divisable(fs[i], p.first)) {
        ok = false;
      }
    }
    dbg(i, ok);
    if (ok) ++ans;
  }
  wt(ans);
}
