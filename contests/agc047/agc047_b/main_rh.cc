#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

class RollingHash {
 public:
  void Add(char c) {
    const unsigned long long base = 100000007;
    hash_ = hash_ * base + c;
  }
  unsigned long long hash() const { return hash_; }
  bool operator==(const RollingHash &h) const { return hash_ == h.hash_; }

 private:
  unsigned long long hash_ = 0;
};

namespace std {
template <>
class hash<RollingHash> {
 public:
  size_t operator()(const RollingHash &h) const {
    return hash<unsigned long long>()(h.hash());
  }
};
}  // namespace std

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }
  sort(all(s),
       [](const string &a, const string &b) { return a.size() > b.size(); });

  ll ans = 0;
  unordered_map<RollingHash, array<int, 26>> m;
  for (const auto &si : s) {
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
