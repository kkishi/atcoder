#include <bits/stdc++.h>

#include "binary_search.h"
#include "bit.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }
  sort(all(s));

  V<pair<int, int>> len(n);
  rep(i, n) len[i] = {s[i].size(), i};
  sort(all(len), greater());

  ll ans = 0;
  for (char alpha = 'a'; alpha <= 'z'; ++alpha) {
    auto lit = len.begin();
    set<int> avail_set;
    BIT<int> avail(n);
    auto add = [&](int i) {
      if (avail_set.insert(i).second) {
        avail.Add(i, 1);
      }
    };
    set<int> longer;
    for (int cl = len[0].first; cl >= 1; --cl) {
      for (int i : longer) {
        if (s[i][cl - 1] == alpha) add(i);
      }
      set<int> same;
      while (lit != len.end() && lit->first == cl) {
        same.insert(lit->second);
        ++lit;
      }
      for (int i : same) {
        if (s[i][cl - 1] == alpha) {
          string prefix = s[i].substr(0, cl - 1);
          auto match = [&](int k) {
            const string &si = s[k];
            if (si.size() < prefix.size()) return false;
            rrep(j, prefix.size()) {
              if (si[j] != prefix[j]) return false;
            }
            return true;
          };
          int lo = BinarySearch<int>(i, -1, match);
          int hi = BinarySearch<int>(i, n, match);
          ans += avail.Sum(hi) - avail.Sum(lo - 1);
        }
      }
      for (int i : same) {
        if (s[i][cl - 1] == alpha) add(i);
        longer.insert(i);
      }
    }
  }
  wt(ans);
}
