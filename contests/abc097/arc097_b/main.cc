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

class DisjointSet {
 public:
  DisjointSet(int size) : parent_(size), size_(size, 1) {
    for (int i = 0; i < size; ++i) {
      parent_[i] = i;
    }
  }
  int Find(int x) {
    int& p = parent_[x];
    if (p != x) p = Find(p);
    return p;
  }
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;
    if (Size(x) > Size(y)) std::swap(x, y);
    parent_[x] = parent_[y];
    size_[y] += size_[x];
  }
  int Size(int x) { return size_[Find(x)]; }
  bool Same(int x, int y) { return Find(x) == Find(y); }

 private:
  std::vector<int> parent_, size_;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, n, m);
  V<int> p(n);
  rep(i, n) cin >> p[i];
  DisjointSet ds(n);
  rep(i, m) {
    in(int, x, y);
    ds.Union(x - 1, y - 1);
  }
  int ans = 0;
  rep(i, n) if (ds.Same(i, p[i] - 1))++ ans;
  out(ans);
}
