#include <iostream>
#include<ctime>

using namespace std;

int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}

int calc_fib2(int n) {

    int first=1, second =1, current;

    for (int i=0; i<n; i++){
        if (i>1){
            current = first+second;
            first = second;
            second = current;
        }
    }

    if (n==0){
        return 0;
    }else if(n<=2){
        return 1;
    }else {
        return current;
    }


}


int main() {
    int n = 0;
    std::cin >> n;

    int start1 = clock();
    int result1 = calc_fib(n);
    int stop1 = clock();

    int start2 = clock();
    int result2 = calc_fib2(n);
    int stop2 = clock();

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;
    double took2 = (stop2-start2)/double(CLOCKS_PER_SEC)*1000;

    printf("%d %lf \n", result1, took1);
    printf("%d %lf\n", result2, took2);

    return 0;
}
