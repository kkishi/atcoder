#include <bits/stdc++.h>

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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  DisjointSet ds(N);
  vector<set<int>> friends(N);
  vector<set<int>> blocks(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    friends[a].insert(b);
    friends[b].insert(a);
    ds.Union(a, b);
    DBG(a, b, ds.Find(a), ds.Find(b), ds.Size(a), ds.Size(b));
  }
  REP(i, K) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    blocks[a].insert(b);
    blocks[b].insert(a);
  }

  REP(i, N) {
    int cnt = ds.Size(i) - 1 - friends[i].size();
    FOR(b, blocks[i]) if (ds.Same(b, i)) --cnt;
    if (i) cout << " ";
    cout << cnt;
  }
  cout << endl;
}
