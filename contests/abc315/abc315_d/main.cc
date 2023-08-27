#include <bits/stdc++.h>

#include "atcoder.h"
#include "run_length_queue.h"

void Main() {
  ints(h, w);
  V<string> c(h);
  cin >> c;
  V<map<int, int>> hc(h), wc(w);
  rep(i, h) rep(j, w) {
    hc[i][c[i][j]]++;
    wc[j][c[i][j]]++;
  }
  set<int> hr, wr;
  rep(i, h) if (sz(hc[i]) == 1) hr.insert(i);
  rep(i, w) if (sz(wc[i]) == 1) wr.insert(i);
  int hs = 0, ws = 0;
  bool flipped = false;
  while (sz(hr) + sz(wr)) {
    set<int> skip;
    rep(i, w) if (sz(wc[i]) == 1) skip.insert(i);
    each(e, hr) {
      rep(i, w) {
        char C = flipped ? c[i][e] : c[e][i];
        if (--wc[i][C] == 0) wc[i].erase(C);
      }
    }
    hs += sz(hr);
    if (h - hs > 1) {
      rep(i, w) {
        if (!skip.count(i) && sz(wc[i]) == 1) wr.insert(i);
      }
    }
    hr.clear();
    flipped = !flipped;
    swap(h, w);
    swap(hc, wc);
    swap(hr, wr);
    swap(hs, ws);
  }
  wt((h - hs) * (w - ws));
}
