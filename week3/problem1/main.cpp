#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int get_change(int n) {

    int number = 0;
    if (n < 5){
        return n/1;
    }else if (n < 10){
        return floor (n/5) + n%5;
    }else{
        number = floor (n/10);
        number += get_change(n%6);
    }
    return number;
}

int main() {
    int n = 0;
    std::cin >> n;

    int start1 = clock();
    int result1 = get_change(n);
    int stop1 = clock();

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;

    printf("The answer is %d, computed in %lf ms.\n", result1, took1);

    return 0;
}