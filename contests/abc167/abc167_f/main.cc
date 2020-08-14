#include <bits/stdc++.h>

#include "macros.h"
#include "setmin.h"

using namespace std;

struct S {
  int lowest, change;
  bool operator<(const S& s) const { return lowest > s.lowest; }
};

int main() {
  rd(int, n);
  vector<string> s(n);
  cin >> s;
  vector<S> left, right;
  for (const string& si : s) {
    int lowest = 0, change = 0;
    for (char c : si) {
      change += c == '(' ? 1 : -1;
      Setmin(lowest, change);
    }
    if (change >= 0) {
      left.push_back({lowest, change});
      continue;
    }
    lowest = 0, change = 0;
    for (int i = si.size() - 1; i >= 0; --i) {
      change += si[i] == ')' ? 1 : -1;
      Setmin(lowest, change);
    }
    right.push_back({lowest, change});
  }
  sort(all(left));
  sort(all(right));
  auto height = [&](const vector<S>& v) -> optional<int> {
    int curr = 0;
    for (const auto& s : v) {
      if (curr + s.lowest < 0) {
        return nullopt;
      }
      curr += s.change;
    }
    return curr;
  };
  optional<int> l = height(left), r = height(right);
  if (l && r && *l == *r) {
    wt("Yes");
  } else {
    wt("No");
  }
}
