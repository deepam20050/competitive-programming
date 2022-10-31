#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int N = 500;
const ll inf = 1e15;

bitset < N > vis;
ll dist[N][N];
int del[N];
ll print[N];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%lld", dist[i] + j);  
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", del + i);
    --del[i];
  }
  for (int dd = n - 1; dd >= 0; --dd) {
    int k = del[dd];
    vis[k] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][k] != inf && dist[k][j] != inf) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        if (vis[i] && vis[j]) {
          print[dd] += dist[i][j];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld ", print[i]);
  }
  return 0;
}
