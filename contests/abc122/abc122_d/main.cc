#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int main() {
  rd(int, n);
  map<string, mint> m;
  m[""] = 1;
  while (n--) {
    map<string, mint> nm;
    for (auto [s, cnt] : m) {
      const string acgt = "ACGT";
      for (char c : acgt) {
        string ns = s + c;
        auto agc = [&]() { return ns.find("AGC") != string::npos; };
        bool ok = !agc();
        rep(i, ns.size() - 1) {
          swap(ns[i], ns[i + 1]);
          if (agc()) ok = false;
          swap(ns[i], ns[i + 1]);
        }
        // dbg(ns, ok);
        if (ok) {
          if (ns.size() == 4) ns = ns.substr(1);
          nm[ns] += cnt;
        }
      }
    }
    swap(m, nm);
  }
  mint ans = 0;
  for (auto [_, cnt] : m) {
    ans += cnt;
  }
  wt(ans);
}
