#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(const T& value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
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
  std::cout << value << '\n';
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

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

struct D {
  int l, r, s;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, n, m);
  dbg(n, m);
  V<D> ds;
  rep(i, n) {
    in(int, l, r, s);
    ds.push_back({l, r, s});
  }

  sort(all(ds), [](const D& a, const D& b) { return a.r < b.r; });
  V<int> l(m + 2);
  {
    auto it = ds.begin();
    for (int i = 1; i <= m; ++i) {
      int sum = 0;
      while (it != ds.end() && it->r < i) {
        sum += it->s;
        ++it;
      }
      l[i] = l[i - 1] + sum;
    }
  }

  sort(all(ds), [](const D& a, const D& b) { return a.l < b.l; });
  V<int> r(m + 2);
  {
    auto it = ds.rbegin();
    for (int i = m; i >= 1; --i) {
      int sum = 0;
      while (it != ds.rend() && it->l > i) {
        sum += it->s;
        ++it;
      }
      r[i] = r[i + 1] + sum;
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = max(ans, l[i] + r[i]);
  }
  out(ans);
}
