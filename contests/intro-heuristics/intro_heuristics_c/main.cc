#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

struct Problem {
  int D;
  vector<int> c;
  vector<vector<int>> s;
};

class Solution {
 public:
  Solution(const Problem& p, const vector<int>& t)
      : problem_(p), types_(t), held_(26, {0, p.D + 1}), sat_(0) {
    rep(i, p.D) {
      sat_ += p.s[i][t[i]];
      held_[t[i]].insert(i + 1);
    }

    rep(i, 26) {
      const set<int>& h = held_[i];
      auto it = h.begin();
      ++it;
      for (; it != h.end(); ++it) {
        auto jt = it;
        --jt;
        int n = (*it - *jt - 1);
        sat_ -= p.c[i] * n * (n + 1) / 2;
      }
    }
  }
  void Change(int d, int q) {
    assert(d < types_.size());
    assert(types_[d] != q);

    auto change = [&](int date) {
      int t = types_[date];
      int ret = problem_.s[date][t];
      auto it = held_[t].find(date + 1);
      assert(it != held_[t].end());
      auto jt = it;
      --jt;
      int n = (*it - *jt);
      auto kt = it;
      ++kt;
      int m = (*kt - *it);
      ret += problem_.c[t] * m * n;
      return ret;
    };

    sat_ -= change(d);
    held_[types_[d]].erase(d + 1);
    types_[d] = q;
    assert(held_[types_[d]].count(d + 1) == 0);
    held_[types_[d]].insert(d + 1);
    sat_ += change(d);
  }
  int Sat() const { return sat_; }

 private:
  const Problem& problem_;
  vector<int> types_;
  vector<set<int>> held_;
  int sat_;
};

int main() {
  Problem p;
  cin >> p.D;
  p.c.resize(26);
  rep(i, 26) cin >> p.c[i];
  p.s.resize(p.D);
  rep(i, p.D) {
    p.s[i].resize(26);
    rep(j, 26) cin >> p.s[i][j];
  }

  vector<int> t(p.D);
  rep(i, p.D) {
    cin >> t[i];
    --t[i];
  }

  Solution s(p, t);

  in(int, m);
  while (m--) {
    in(int, d, q);
    --d, --q;
    s.Change(d, q);
    out(s.Sat());
  }
}
