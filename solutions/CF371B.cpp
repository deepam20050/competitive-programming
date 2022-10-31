#include "bits/stdc++.h"

using namespace std;

int solve (int &x, const int &d) {
  int s = 0;
  while (x % d == 0) {
    x /= d;
    ++s;
  }
  return s;
}

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  int a2 = solve(a, 2), b2 = solve(b, 2);
  int a3 = solve(a, 3), b3 = solve(b, 3);
  int a5 = solve(a, 5), b5 = solve(b, 5);
  int steps = max(a2, b2) - min(a2, b2) + max(a3, b3) - min(a3, b3) + max(a5, b5) - min(a5, b5);
  a == b ? printf("%d\n", steps) : printf("-1\n");
  return 0;
}
