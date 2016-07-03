#include <iostream>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

double get_optimal_value(int capacity, vector<pair<int, int>>v) {
    double value = 0.0;

    double curr_cap = (double) capacity;

    for (unsigned i = v.size(); i-- > 0;){

        double ratio;

        if (curr_cap ==0) {
            break;
        }else if ((double) v[i].second >= curr_cap){
            ratio = (curr_cap/(double) v[i].second);
            value += ratio * (double) v[i].first;
            curr_cap -= ratio * (double) v[i].second;
        }else{
            while ( curr_cap > (double) v[i].second ){
                value += (double) v[i].first * floor (curr_cap /(double) v[i].second);
                curr_cap -= (double) v[i].second * floor (curr_cap /(double) v[i].second);
            }
        }

    }

    return value;
}




int main() {
    int number = 0, capacity = 0;
    cin >> number>> capacity;

    int i = 0;

    vector<pair<int, int>>knapsack;

    while (i < number){
        int value = 0, weight = 0;
        cin >>value>>weight;
        pair<int, int>p = {value, weight};
        knapsack.push_back(p);
        ++i;
    }

    //sort (knapsack.begin(), knapsack.end());

    sort(knapsack.begin(), knapsack.end(), [](const pair<int,int> &left, const pair<int,int> &right) {
        return left.first/left.second < right.first/right.second;
    });


    int start1 = clock();
    double result1 = get_optimal_value(capacity, knapsack);
    int stop1 = clock();

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;

    printf("The answer is %.5f, computed in %lf ms.\n", result1, took1);

    return 0;
}
