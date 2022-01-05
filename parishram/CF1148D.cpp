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

const int N = 3e5 + 5;

int a[N], b[N];
int n;
vector < int > v1, v2;

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d %d", a + i, b + i);
    if (a[i] < b[i]) {
      v1.eb(i);
    } else {
      v2.eb(i);
    }
  }
  sort(all(v1), [] (const int &l, const int &r) {
      return a[l] > a[r];
      });
  sort(all(v2), [] (const int &l, const int &r) {
      return b[l] < b[r];
      });
  auto p = sz(v1) > sz(v2) ? v1 : v2;
  printf("%d\n", sz(p));
  for (auto &x : p) printf("%d ", x + 1);
  return 0;
}
