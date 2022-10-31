#include "bits/stdc++.h"

using namespace std;
using pi = pair < int, int >;

const int N = 2e5 + 5;

map < int, bool > vis;
priority_queue < pi, vector < pi >, greater < pi > > pq;

int arr[N];
int print[N];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    vis[arr[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[arr[i] - 1]) {
      vis[arr[i] - 1] = 1;
      pq.emplace(1, arr[i] - 1);
    } 
    if (!vis[arr[i] + 1]) {
      vis[arr[i] + 1] = 1;
      pq.emplace(1, arr[i] + 1);
    }
  }
  long long d = 0;
  for (int i = 0; i < m; ++i) {
    auto top = pq.top();
    int dist = top.first, x = top.second;
    pq.pop();
    d += dist;
    print[i] = x;
    vis[x] = 1;
    if (!vis[x + 1]) {
      vis[x + 1] = 1;
      pq.emplace(dist + 1, x + 1);
    }
    if (!vis[x - 1]) {
      vis[x - 1] = 1;
      pq.emplace(dist + 1, x - 1);
    }
  }
  printf("%lld\n", d);
  for (int i = 0; i < m; ++i) {
    printf("%d ", print[i]);
  }
  return 0;
}
