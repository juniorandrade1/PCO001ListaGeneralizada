#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(NULL));
  const int N = 10000000;
  for(int i = 0; i < N; ++i) {
    if(i % 3 == 0) {
      int x = ((rand() << 16) + (rand())) % 32;
      printf("%d ", x);
    }
    else if(i % 3 == 1) {
      long long x = ((rand() << 16) + (rand())) % 64;
      printf("%lld ", x);
    }
    else {
      int x = (rand()) % 26;
      printf("%c ", x + 'A');
    }
  }
  return 0;
}