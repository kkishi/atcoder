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

struct Point {
  int x, y;
};

int main() {
  in(int, n);
  vector<Point> ps(n);
  rep(i, n) cin >> ps[i].x >> ps[i].y;
  const int kMax = 100001;
  vector<set<int>> xs(kMax);
  for (const Point& p : ps) {
    xs[p.y].insert(p.x);
  }

  ll ans = 0;
  {
    DisjointSet dsx(kMax);
    for (const set<int>& s : xs)
      for (int x : s) dsx.Union(x, *s.begin());
    vector<int> y_count(kMax);
    vector<set<int>> y_unique(kMax);
    set<int> roots;
    for (const Point& p : ps) {
      int root = dsx.Find(p.x);
      ++y_count[root];
      y_unique[root].insert(p.y);
      roots.insert(root);
    }
    for (int r : roots) {
      ans += ll(dsx.Size(r)) * ll(y_unique[r].size()) - y_count[r];
    }
  }
  out(ans);
}
