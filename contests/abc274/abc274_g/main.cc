// https://gist.github.com/koyumeishi/e94f37de9757c12126ba38dd8cec3e5b
// Modified to use the ACL maxflow implementation.
#include <bits/stdc++.h>

#include <atcoder/maxflow>

using namespace std;

class UnionFindTree {
  struct base_node {
    int parent;
    int rank;
    int size;
  };

  vector<base_node> node;

 public:
  UnionFindTree(int n) {
    node.resize(n);
    for (int i = 0; i < n; i++) {
      node[i].parent = i;
      node[i].rank = 0;
      node[i].size = 1;
    }
  }

  int find(int x) {  // return root node of x
    if (node[x].parent == x)
      return x;
    else {
      return node[x].parent = find(node[x].parent);
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int at) { return node[find(at)].size; }

  void unite(int x, int y) {
    x = find(node[x].parent);
    y = find(node[y].parent);

    if (x == y) return;

    if (node[x].rank < node[y].rank) {
      node[x].parent = y;
      node[y].size += node[x].size;
    } else if (node[x].rank > node[y].rank) {
      node[y].parent = x;
      node[x].size += node[y].size;
    } else {
      node[x].rank++;
      unite(x, y);
    }
  }
};

// to burn or to bury problem solver
namespace burny {

struct Variable {
  size_t id;
  int x = 1;

  Variable operator~() {
    Variable res;
    res.id = id;
    res.x = 1 - x;
    return res;
  }

  bool operator<(const Variable& v) const {
    return id == v.id ? x < v.x : id < v.id;
  }
};

enum class State {
  INFEASIBLE,
  NOT_SOLVED,
  OPTIMAL,
};

ostream& operator<<(ostream& os, const State& state) {
  if (state == State::INFEASIBLE) return os << "INFEASIBLE";
  if (state == State::NOT_SOLVED) return os << "NOT_SOLVED";
  if (state == State::OPTIMAL) return os << "OPTIMAL";
  return os;
}

// minimize a + sum_i c_{i1} * x_i + c_{i0} * (1-x_i) + sum_{i,j} c_{i1,j0} x_i
// * (1-x_j) x_i = {0, 1}
template <class Integer>
class Model {
  vector<Variable> variables;
  Integer cost_d0;

  using table_2 = array<Integer, 2>;
  map<size_t, table_2> cost_d1;

  using table_4 = array<Integer, 4>;
  map<pair<size_t, size_t>, table_4> cost_d2;

 public:
  State state = State::NOT_SOLVED;
  Integer answer;
  vector<int> assignments;

  Variable add_variable() {
    size_t id = variables.size();
    Variable v;
    v.id = id;
    v.x = 1;
    variables.emplace_back(v);
    return variables.back();
  }

  void add_constraint(Variable x, Integer cost) { cost_d1[x.id][x.x] += cost; }

  void add_constraint(Variable x, Variable y, Integer cost) {
    if (y < x) swap(x, y);
    assert(x.id != y.id);

    int t = (x.x << 1) | (y.x << 0);
    cost_d2[{x.id, y.id}][t] += cost;
  }

  pair<Integer, State> solve() {
    assert(state == State::NOT_SOLVED);
    cost_d0 = 0;

    int n = variables.size();
    UnionFindTree uft(n * 2);
    for (auto& c : cost_d2) {
      size_t i, j;
      tie(i, j) = c.first;
      const auto& t = c.second;

      Integer s = -t[0b00] + t[0b01] + t[0b10] - t[0b11];

      if (s < 0) {  // must flip
        uft.unite(i, j + n);
        uft.unite(i + n, j);
      } else if (s > 0) {
        uft.unite(i, j);
        uft.unite(i + n, j + n);
      } else {
        // s = 0, any flip
      }
    }

    // find feasible flip
    vector<int> flip(n, -1);
    {
      for (int i = 0; i < n; i++) {
        if (uft.same(i, i + n)) {
          state = State::INFEASIBLE;
          return {0, State::INFEASIBLE};
        }
      }

      map<int, vector<int>> s;
      for (int i = 0; i < n + n; i++) s[uft.find(i)].push_back(i);

      for (auto& w : s) {
        int r = w.first;
        if (flip[r % n] != -1) continue;
        for (auto v : w.second) {
          flip[v % n] = v >= n;
        }
      }
    }

    for (auto& c : cost_d2) {
      size_t i, j;
      tie(i, j) = c.first;
      auto& t = c.second;
      if (flip[i]) {
        swap(t[0b00], t[0b10]);
        swap(t[0b01], t[0b11]);
      }
      if (flip[j]) {
        swap(t[0b00], t[0b01]);
        swap(t[0b10], t[0b11]);
      }
      //     j=0 j=1
      // i=0 | a b = a + 0     0     + 0 (d-c) + 0 (c+b-a-d)
      // i=1 | c d       (c-a) (c-a)   0 (d-c)   0 0
      Integer s = -t[0b00] + t[0b01] + t[0b10] - t[0b11];
      cost_d0 += t[0b00];
      cost_d1[i][flip[i] == 0 ? 1 : 0] += t[0b10] - t[0b00];
      cost_d1[j][flip[j] == 0 ? 1 : 0] += t[0b11] - t[0b10];
      t[0b01] = s;
      t[0b00] = t[0b10] = t[0b11] = 0;
      assert(s >= 0);
    }

    for (auto& c : cost_d1) {
      size_t id = c.first;
      auto& t = c.second;
      if (flip[id]) {
        swap(t[0], t[1]);
      }
      if (t[1] >= t[0]) {
        cost_d0 += t[0];
        t[1] -= t[0];
        t[0] = 0;
      } else {
        cost_d0 += t[1];
        t[0] -= t[1];
        t[1] = 0;
      }
      assert(t[0] >= 0);
      assert(t[1] >= 0);
    }

    // make graph
    atcoder::mf_graph<Integer> g(n + 2);
    int source = n + 0;
    int sink = source + 1;

    for (auto& c : cost_d1) {
      size_t id = c.first;
      auto& t = c.second;
      if (t[1] > 0) {
        g.add_edge(id, sink, t[1]);
      }
      if (t[0] > 0) {
        g.add_edge(source, id, t[0]);
      }
    }

    for (auto& c : cost_d2) {
      size_t i, j;
      tie(i, j) = c.first;
      const auto& t = c.second;

      if (t[0b10] > 0) {
        g.add_edge(i, j, t[0b10]);
      }
      if (t[0b01] > 0) {
        g.add_edge(j, i, t[0b01]);
      }
    }

    // solve max flow (min cut)
    Integer cut = g.flow(source, sink);
    answer = cut + cost_d0;
    state = State::OPTIMAL;

    // assignment
    assignments = vector<int>(n, 0);
    {
      vector<vector<int>> graph(n + 2);
      auto edges = g.edges();
      for (int i = 0; i < edges.size(); ++i) {
        const auto& e = edges[i];
        if (e.cap > e.flow) {
          graph[e.from].push_back(i);
        }
      }
      // find S set
      set<int> visit;
      queue<int> q;
      visit.insert(source);
      q.push(source);
      while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i : graph[v]) {
          const auto& e = edges[i];
          if (visit.count(e.to)) continue;
          visit.insert(e.to);
          q.push(e.to);

          assignments[e.to] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (flip[i]) {
        assignments[i] = 1 - assignments[i];
      }
    }

    return {answer, state};
  }
};

}  // namespace burny

int main() {
  long long h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) cin >> s[i];

  burny::Model<long long> model;
  vector vars(h, vector(w, vector(2, burny::Variable{})));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '#') continue;
      for (int k = 0; k < 2; ++k) {
        vars[i][j][k] = model.add_variable();
        // Cost for adding a camera, either vertically (k = 0) or horizontally
        // (k = 1).
        model.add_constraint(vars[i][j][k], 1);
      }
      // The cell must have at least one camera.
      model.add_constraint(~vars[i][j][0], ~vars[i][j][1], h * w);
      if (i > 0 && s[i - 1][j] != '#') {
        // Merge vertical cameras.
        model.add_constraint(vars[i][j][0], vars[i - 1][j][0], -1);
      }
      if (j > 0 && s[i][j - 1] != '#') {
        // Merge horizontal cameras.
        model.add_constraint(vars[i][j][1], vars[i][j - 1][1], -1);
      }
    }
  }

  model.solve();
  cout << model.answer << endl;
  cerr << model.state << endl;

  for (auto v : model.assignments) {
    cerr << v;
  }
  cerr << endl;

  return 0;
}
