#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;
const int LN = 26;

int trie[N * 10][LN];
int siz[N * 10][LN];
int idx;
bool win[N], lose[N];

void insert (string s) {
  int curr = 0;
  for (auto e : s) {
    int c = e - 'a';
    if (!trie[curr][c]) {
      trie[curr][c] = ++idx;
    }
    curr = trie[curr][c];
  }
}

void dfs (int u) {
  bool leaf = 1;
  FOR(i, 0, LN) {
    if (trie[u][i]) {
      int to = trie[u][i];
      leaf = 0;
      dfs(to);
    }
  }
  if (leaf) {
    win[u] = 0;
    lose[u] = 1;
  } else {
    FOR(i, 0, LN) {
      if (trie[u][i]) {
        int nxt = trie[u][i];
        if (!win[nxt]) {
          win[u] = 1;
        } 
        if (!lose[nxt]) {
          lose[u] = 1;
        }
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  FOR(i, 0, n) {
    string s;
    cin >> s;
    insert(s);
  }
  dfs(0);
  if (!win[0]) cout << "Second\n";
  else if (win[0] && lose[0]) cout << "First\n";
  else cout << ((k&1) ? "First\n" : "Second\n");
  return 0;
}
