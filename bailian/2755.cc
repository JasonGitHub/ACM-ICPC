#include <iostream>
#include <vector>

using namespace std;

const int MAX = 40;

int CountWays(const vector<int> &a, int n, int w) {
  if (w == 0) return 1;
  if (n <= 0) return 0;
  return CountWays(a, n - 1, w) + CountWays(a, n - 1, w - a[n]);
}

int CountWays(const vector<int> &a, int n) {
  vector<vector<int> > count(n + 1, vector<int>(MAX + 1, 0));
  for (int i = 0; i <= n; ++i) {
    count[i][0] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= MAX; ++j) {
      count[i][j] += count[i - 1][j];
      if (a[i] <= j) count[i][j] += count[i - 1][j - a[i]];
    }
  }
  return count[n][MAX];
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cout << CountWays(a, n) << endl;
  return 0;
}
