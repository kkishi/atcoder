#include <bits/stdc++.h>

#include "binary_search.h"
#include "bit.h"
#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }
  sort(all(s));

  for (auto si : s) dbg(si);

  V<pair<int, int>> len(n);
  rep(i, n) len[i] = {s[i].size(), i};
  sort(all(len), greater());

  for (auto [a, b] : len) dbg(a, b);

#ifdef DEBUG
  ll very_naive = 0;
  rep(i, n) rep(j, i) {
    auto check = [](const string &a, const string &b) {
      string prefix = a.substr(0, a.size() - 1);
      if (b.substr(0, prefix.size()) != prefix) {
        return false;
      }
      for (int i = a.size() - 1; i < b.size(); ++i) {
        if (b[i] == a.back()) {
          return true;
        }
      }
      return false;
    };
    assert(check("xyc", "xyxcba"));
    assert(check("b", "cba"));
    assert(check("a", "cba"));
    assert(check("c", "cba"));
    assert(check("b", "ba"));
    assert(check("a", "ba"));
    if (check(s[i], s[j]) || check(s[j], s[i])) {
      ++very_naive;
    }
  }
#endif

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

#ifdef DEBUG
          int naive = 0;
          for (int j = 0; j < n; ++j) {
            if (s[j].substr(0, cl - 1) == prefix) {
              if (avail.Get(j)) {
                ++naive;
                // dbg(prefix, i, j, avail.Get(j));
              }
            }
          }
#endif

          int fast;
          auto match = [&](int k) {
            const string &si = s[k];
            if (si.size() < prefix.size()) return false;
            for (int j = prefix.size() - 1; j >= 0; --j) {
              if (si[j] != prefix[j]) return false;
            }
            return true;
          };
          int lo, hi;
          {
            int ok = i, ng = -1;
            while (ok - ng > 1) {
              int mid = (ok + ng) / 2;
              (match(mid) ? ok : ng) = mid;
            }
            lo = ok;
          }
          {
            int ok = i, ng = n;
            while (ng - ok > 1) {
              int mid = (ok + ng) / 2;
              (match(mid) ? ok : ng) = mid;
            }
            hi = ok;
          }
          fast = avail.Sum(hi) - avail.Sum(lo - 1);
          /*
          if (cl > 1) {
            int j = BinarySearch<int>(i, n, [&](int k) {
              const string &si = s[k];
              if (si.size() < prefix.size()) return false;
              for (int j = prefix.size() - 1; j >= 0; --j) {
                if (si[j] != prefix[j]) return false;
              }
              return true;
            });
            // dbg(prefix, i, j, avail.Get(j));
            fast = avail.Sum(j) - avail.Sum(i);
          } else {
            fast = avail_set.size();
            // fast = avail.Sum(n - 1) - 1;
            // fast = avail.Sum(i - 1);
          }
          */

#ifdef DEBUG
          if (naive != fast) {
            dbg(cl, naive, fast, s[i], alpha);
          }
          assert(naive == fast);
#endif
          ans += fast;
        }
      }
      for (int i : same) {
        if (s[i][cl - 1] == alpha) add(i);
        longer.insert(i);
      }
    }
  }
#ifdef DEBUG
  if (very_naive != ans) {
    dbg(very_naive, ans);
    assert(false);
  }
#endif
  wt(ans);
}
