#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

long long get_maximum_value(const string &exp) {

    vector<long long>numbers;
    vector<char>op;

    for (int i = 0; i <  exp.size(); i++){
        if (i%2==0){
            numbers.push_back((long long) exp[i] - 48);
        }else{
            op.push_back(exp[i]);
        }
    }

    vector<vector<long long>>M(numbers.size());
    vector<vector<long long>>m(numbers.size());

    for (int i=0; i< numbers.size(); i++){
        M[i].resize(numbers.size());
        m[i].resize(numbers.size());
    }

    // generate Max and Min Matrix
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers.size(); ++j) {
            if (i==j){
                M[i][j] = numbers[i];
                m[i][j] = numbers[i];
            }
        }
    }

    for (int s=1; s < numbers.size(); s++){
        //printf("\ns is ------------ %d", s);

        for (int i=0; i < numbers.size()-s; i++){
            int j = i+s;
            //printf("\ni is %d, j is %d", i,j);

            long long max_value = std::numeric_limits<long long>::min();
            long long min_value = std::numeric_limits<long long>::max();

            for (int k = i; k <=  j-1; k++) {
                //printf("\ni=%d, k=%d,  k+1=%d, j=%d,", i, k, k+1, j);

                long long a = eval(M[i][k], M[k+1][j], op[k]);
                long long b = eval(M[i][k], m[k+1][j], op[k]);
                long long c = eval(m[i][k], M[k+1][j], op[k]);
                long long d = eval(m[i][k], m[k+1][j], op[k]);

                max_value = std::max(max_value,std::max(a, std::max(b, std::max(c, d))));
                min_value = std::min(min_value,std::min(a, std::min(b, std::min(c, d))));

            }

            std::pair<long, long>min_max;
            min_max.first = min_value;
            min_max.second = max_value;

            //printf("\n%lld", min_max.first);
            m[i][j] = min_max.first;
            M[i][j] = min_max.second;

            //printf("\nMin: %lld", min_max.first);
            //printf("\nMax: %lld\n", min_max.second);
        }
    }
    printf("\nMax\n");
    // print max matrix
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers.size(); ++j) {
            printf("%lld|", M[i][j]);
        }
        printf("\n");
    }
    printf("\nMin\n");

    // print max matrix
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers.size(); ++j) {
            printf("%lld|", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return M[0][numbers.size()-1];

}

int main() {
    string s;
    std::cin >> s;

    std::cout << get_maximum_value(s) << '\n';

}
