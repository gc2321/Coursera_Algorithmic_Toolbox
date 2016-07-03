#include <iostream>

int gcd(int a, int b) {
  //write your code here
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd2(int a, int b) {

  if (b == 0){
    return a;
  }

  int prime = a%b;

  return gcd2(b, prime);
}




int main() {
  int a, b;
  std::cin >> a >> b;

  int start1 = clock();
  int result1 = gcd(a, b);
  int stop1 = clock();

  int start2 = clock();
  int result2 = gcd2(a, b);
  int stop2 = clock();

  double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;
  double took2 = (stop2-start2)/double(CLOCKS_PER_SEC)*1000;

  printf("%d %lf \n", result1, took1);
  printf("%d %lf \n", result2, took2);

  return 0;
}
