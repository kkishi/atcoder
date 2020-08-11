#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct Trie {
  array<int, 26> value = {};
  array<unique_ptr<Trie>, 26> children;
};

int main() {
  rd(int, n);

  V<string> s(n);
  rep(i, n) {
    cin >> s[i];
    reverse(all(s[i]));
  }

  Trie trie;
  function<bitset<26>(Trie&, const string&, int)> add_trie =
      [&](Trie& t, const string& si, int i) {
        bitset<26> have;
        if (i < si.size()) {
          if (t.children[si[i] - 'a'] == nullptr) {
            t.children[si[i] - 'a'].reset(new Trie);
          }
          Trie& c = *t.children[si[i] - 'a'];
          have |= add_trie(c, si, i + 1);
          have.set((si[i] - 'a'));
        }
        if (si.size() - i >= 2) {
          rep(i, 26) if (have.test(i))++ t.value[i];
        }
        return have;
      };
  for (const auto& si : s) {
    add_trie(trie, si, 0);
  }
  ll ans = 0;
  for (const auto& si : s) {
    const Trie* t = &trie;
    rep(i, si.size() - 1) t = t->children[si[i] - 'a'].get();
    ans += t->value[si.back() - 'a'];
  }
  wt(ans);
}
