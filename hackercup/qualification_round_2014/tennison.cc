#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int k; 
double ps, pr, pi, pu, pw, pd, pl;
double pa[101][101][1001];

double Solve(int w, int l, double p) {
  int px = 1000 * p;
  if (w == k) return 1;
  if (l == k) return 0;
  if (pa[w][l][px] != -1) return pa[w][l][px];
  double up = p + pu >= 1 ? 1 : p + pu;
  double down = p - pd <= 0 ? 0 : p - pd;
  double ret = p * ps * pw * Solve(w + 1, l, up) +
               p * ps * (1 - pw) * Solve(w + 1, l, p) +
               p * (1 - ps) * pl * Solve(w, l + 1, down) +
               p * (1 - ps) * (1 - pl) * Solve(w, l + 1, p) +
               (1 - p) * pr * pw * Solve(w + 1, l, up) +
               (1 - p) * pr * (1 - pw) * Solve(w + 1, l, p) +
               (1 - p) * (1 - pr) * pl * Solve(w, l + 1, down) +
               (1 - p) * (1 - pr) * (1 - pl) * Solve(w, l + 1, p);
  pa[w][l][px] = ret;
  return ret;
}

void ClearPa() {
  for (int i = 0; i < 101; ++i)
    for (int j = 0; j < 101; ++j)
      for (int k = 0; k < 1001; ++k)
        pa[i][j][k] = -1;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    ClearPa();
    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    cout << "Case #" << i + 1 << ": " << fixed << setprecision(6)
      << Solve(0, 0, pi) << endl;
  }
  return 0;
}
