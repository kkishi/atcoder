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

template <typename T>
struct Edge {
  int from, to;
  T weight;
};

template <typename T>
class Graph {
 public:
  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight = T()) {
    edges_[from].push_back({from, to, weight});
  }
  const std::vector<Edge<T>>& Edges(int from) const { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge<T>>> edges_;
};

struct Weight {
  int color, length;
};

int main() {
  in(int, n, q);
  Graph<Weight> g(n);
  rep(i, n - 1) {
    in(int, a, b, c, d);
    --a, --b;
    g.AddEdge(a, b, {c, d});
    g.AddEdge(b, a, {c, d});
  }
  vector<int> ins(n), outs(n);
  vector<int> depths;
  function<void(int, int, int)> dfs = [&](int node, int parent, int depth) {
    int index = depths.size();
    ins[node] = index;
    depths.push_back(depth);
    for (const auto& e : g.Edges(node)) {
      if (e.to == parent) continue;
      dfs(e.to, node, depth + 1);
    }
  };
  dfs(0, -1, 0);
}
