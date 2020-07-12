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

struct Camel {
  ll k, x;
  bool operator<(const Camel& c) const { return x < c.x; }
};

void solve() {
  in(int, n);
  ll ans = 0;
  vector<Camel> lc, rc;
  rep(i, n) {
    in(ll, k, l, r);
    if (l >= r) {
      ans += r;
      lc.push_back({k, l - r});
    } else {
      ans += l;
      rc.push_back({k, r - l});
    }
  }
  auto calc = [&ans](const vector<Camel>& cs) {
    multiset<Camel> m;
    for (const auto& c : cs) {
      if (m.size() == c.k) {
        auto it = m.begin();
        if (it->x >= c.x) {
          continue;
        }
        ans -= it->x;
        m.erase(it);
      }
      assert(m.size() < c.k);
      ans += c.x;
      m.insert(c);
    }
  };

  auto less = [](const Camel& a, const Camel& b) { return a.k < b.k; };
  sort(all(lc), less);
  calc(lc);

  for (auto& c : rc) {
    c.k = n - c.k;
  }
  sort(all(rc), less);
  calc(rc);

  out(ans);
}

int main() {
  in(int, t);
  while (t--) solve();
}
