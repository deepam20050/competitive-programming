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

vector < pii > ans;
int b, w;

int main () {
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    scanf("%d %d", &b, &w);
    int mini = min(b, w);
    mini += mini;
    int x = max(b, w) - min(b, w);
    ans.clear();
    int row;
    if (b <= w) {
      row = 3;
    } else {
      row = 2;
    }
    FOR(i, 2, 2 + mini) {
      ans.eb(row, i);
      if (i & 1) continue;
      if (i == 2) {
        if (x) {
          ans.eb(row, i - 1);
          --x;
        }   
      }
      if (x) {
        ans.eb(row - 1, i);
        --x;
      }
      if (x) {
        ans.eb(row + 1, i);
        --x;
      }
    }
    if (x) {
      puts("NO");
    } else {
      puts("YES");
      for (auto [a, b] : ans) {
        printf("%d %d\n", a, b);
      }
    }
  }
  return 0;
}
