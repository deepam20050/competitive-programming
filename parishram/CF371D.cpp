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

const int N = 2e5 + 5;

int capacity[N];
int quantity[N];
set < int > not_full;
int n;

void solve (int p, int x) {
  auto it = not_full.lower_bound(p);
  while (it != not_full.end()) {
    int i = *it;
    int rem = 0;
    if (x + quantity[i] >= capacity[i]) {
      x -= (capacity[i] - quantity[i]); 
      quantity[i] = capacity[i];
      not_full.erase(i);
      it = not_full.lower_bound(i);
      if (x == 0) {
        break;
      }
    } else {
      quantity[i] += x;
      break;
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    not_full.insert(i);
    scanf("%d", capacity + i);
  }
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int p, x;
      scanf("%d %d", &p, &x);
      --p;
      solve(p, x);
    } else {
      int k;
      scanf("%d", &k);
      --k;
      printf("%d\n", quantity[k]);
    }
  }
  return 0;
}
