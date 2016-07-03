#include <iostream>

int gcd(int a, int b) {

    if (b == 0){
        return a;
    }
    int prime = a%b;
    return gcd(b, prime);
}


int main() {
    int a, b;
    std::cin >> a >> b;

    int start1 = clock();
    int result1 = (a*b)/gcd(a, b);
    int stop1 = clock();

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;

    printf("%d %lf \n", result1, took1);

    return 0;
}
