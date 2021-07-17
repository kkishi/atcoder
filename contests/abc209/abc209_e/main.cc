#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  map<string, V<string>> in, out;
  map<string, int> out_deg;
  set<string> nod;
  each(e, s) {
    string pre = e.substr(0, 3);
    string suf = e.substr(e.size() - 3);
    dbg(e, pre, suf);
    out[pre].pb(suf);
    ++out_deg[pre];
    in[suf].pb(pre);
    nod.insert(pre);
    nod.insert(suf);
  }
  const int LOSE = 1, WIN = 2;
  map<string, int> col;
  queue<string> que;
  each(e, nod) {
    if (out[e].empty()) {
      col[e] = LOSE;
      que.push(e);
    }
  }
  while (!que.empty()) {
    string s = que.front();
    que.pop();
    dbg(s, col[s]);
    each(e, in[s])-- out_deg[e];
    if (col[s] == LOSE) {
      each(e, in[s]) {
        if (col[e] == WIN) continue;
        assert(col[e] != LOSE);
        col[e] = WIN;
        que.push(e);
      }
    } else {
      assert(col[s] == WIN);
      each(e, in[s]) {
        if (out_deg[e] > 0) continue;
        if (col[e] != 0) continue;
        int w = 0;
        each(E, out[e]) {
          int c = col[E];
          assert(c != LOSE);
          if (c == WIN) ++w;
        }
        if (w == sz(out[e])) {
          col[e] = LOSE;
          que.push(e);
          dbg(e);
        }
      }
    }
  }
  each(e, s) {
    string suf = e.substr(e.size() - 3);
    int c = col[suf];
    if (c == 0) {
      wt("Draw");
    } else if (c == 1) {
      wt("Takahashi");
    } else {
      wt("Aoki");
    }
  }
}
