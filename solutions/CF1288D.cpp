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

const int N = 3e5 + 5;
const int M = 8;
int valid[1 << M];
int arr[N][M];
int ansi, ansj;
int n, m;

bool f (int x) {
  memset(valid, -1, sizeof valid);
  FOR(i, 0, n) {
    int mask = 0;
    FOR(j, 0, m) {
      if (arr[i][j] >= x) {
        mask ^= 1 << j;
      }
    }
    valid[mask] = i;
  }
  if (valid[(1 << m) - 1] != -1) {
    ansi = valid[(1 << m) - 1];
    ansj = ansi;
    return 1;
  }
  FOR(i, 0, 1 << m) FOR(j, 0, 1 << m) {
    if (valid[i] != -1 && valid[j] != -1 && ((i | j) == (1 << m) - 1)) {
      ansi = valid[i];
      ansj = valid[j];
      return 1;
    }
  }
  return 0;
}

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, n) FOR(j, 0, m) {
    scanf("%d", arr[i] + j);
  }
  int l = 0, r = 1e9 + 500;
  FOR(i, 0, 30) {
    int m = l + r >> 1;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  f(l);
  printf("%d %d\n", ansi + 1, ansj + 1);
  return 0;
}
