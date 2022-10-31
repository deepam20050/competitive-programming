// AC 
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e6 + 5;

int a[N], b[N], pos[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", a + i);
    --a[i];
    pos[a[i]] = i;
    b[i] = i;
    pos[b[i]] = i;
  }
  int cnt = 0;
  FOR(i, 0, n) {
    if (a[i] != b[i]) {
      ++cnt;
      int p1 = i, p2 = pos[b[i]];
      pos[a[p1]] = p2;
      pos[a[p2]] = p1;
      swap(a[p1], a[p2]);
    }
  }
  (3 * n - cnt) & 1 ? puts("Um_nik") : puts("Petr");
  return 0;
}
