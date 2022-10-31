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

const int N = 1.5e5 + 5;

vector < int > v[N];
int p[N];
int n;

void init () {
  FOR(i, 1, n + 1) {
    p[i] = i;
    v[i] = {i};
  }
}

int find (int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

void join (int x, int y) {
  x = find(x);
  y = find(y);
  if (sz(v[x]) < sz(v[y])){
    swap(x, y);
  }
  v[x].insert(v[x].end(), all(v[y]));
  p[y] = x;
}

int main () {
  scanf("%d", &n);
  init();
  FOR(i, 1, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    join(x, y);
  }
  int x = find(1);
  for (auto &e : v[x]) {
    printf("%d ", e);
  }
  return 0;
}
