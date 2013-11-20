#include <iostream>
#include <set>

using namespace std;

int GetSig(int n) {
  int ret = 0;
  while (n) {
    int digit = n % 10;
    ret |= 1 << digit;
    n /= 10;
  }
  return ret;
}

int CountGood(int* a, int n, int k) {
  int cnt = 0;
  int bmp = (1 << (k + 1)) - 1;
  for (int i = 0; i < n; ++i) {
    if ((GetSig(a[i]) & bmp) == bmp) ++cnt;   
  }
  return cnt;
}

int main() {
  int n, k;
  int a[100 + 10];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << CountGood(a, n, k) << endl;
  return 0;
}
