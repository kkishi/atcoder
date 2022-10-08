#include <bits/stdc++.h>

#include <atcoder/string>

#include "atcoder.h"
#include "rolling_hash.h"

void Main() {
  ints(n);
  strings(s, t);

  using u64 = uint64_t;
  auto f = [&](const string& s) {
    RollingHash h;
    rep(i, n) h.PushBack(s[i]);
    V<u64> ret(n);
    rep(i, n) {
      ret[i] = h.hash();
      h.PopFront();
      h.PushBack(s[i]);
    }
    return ret;
  };
  V<u64> sh = f(s), th = f(t);

  string u = s + s + t + t;
  vector sa = atcoder::suffix_array(u);
  V<int> v;
  each(e, sa) {
    if (n <= e && e < n * 2) continue;
    if (n * 3 <= e) continue;
    v.eb(e);
  }

  int ans = 0;
  int cnt_s = 0;
  int cnt_t = 0;
  rep(i, sz(v)) {
    int cnt_t_curr = 0;
    while (true) {
      if (v[i] < n) {
        ++cnt_s;
      } else {
        ++cnt_t_curr;
      }
      if (i + 1 < sz(v)) {
        // Check if equal, if so continue.
        u64 x = v[i] < n ? sh[v[i]] : th[v[i] - 2 * n];
        int j = i + 1;
        u64 y = v[j] < n ? sh[v[j]] : th[v[j] - 2 * n];
        if (x == y) {
          ++i;
          continue;
        }
      }
      break;
    }
    ans += cnt_s * cnt_t_curr;
    cnt_t += cnt_t_curr;
  }
  wt(ans);
}
