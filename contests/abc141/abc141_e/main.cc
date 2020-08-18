#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const ll kMods[] = {
    1000000007,
    1000992299,
    999119999,
};

struct Hash {
  ll hash[3];
  void Add(char c) {
    rep(i, 3) { hash[i] = (hash[i] * 26 + c - 'a') % kMods[i]; }
  }
  bool operator<(const Hash& h) const {
    rep(i, 3) if (hash[i] != h.hash[i]) return hash[i] < h.hash[i];
    return false;
  }
  bool operator==(const Hash& h) const {
    rep(i, 3) if (hash[i] != h.hash[i]) return false;
    return true;
  }
};

Hash hashes[5000];

int main() {
  ints(n);
  strings(s);
  rep(i, n) hashes[i].Add(s[i]);
  int ans = 0;
  for (int length = 2; length <= n / 2; ++length) {
    set<Hash> seen;
    for (int i = 0; i + length - 1 < n; ++i) {
      hashes[i].Add(s[i + length - 1]);
      if (ans == length) continue;
      if (i - length >= 0) {
        seen.insert(hashes[i - length]);
      }
      if (seen.count(hashes[i])) {
        ans = length;
      }
    }
  }
  wt(ans);
}
