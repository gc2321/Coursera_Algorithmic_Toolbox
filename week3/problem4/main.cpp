#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

bool compareSegment(const Segment &a, const Segment &b){
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
    vector<int> points;

    //write your code here
    sort(segments.begin(), segments.end(), compareSegment);

    int current = segments[0].end;
    points.push_back(segments[0].end);

    for (int i = 1; i < segments.size(); i++){
        //printf("%d\n", segments[i].start);
        if (current >= segments[i].start && current <= segments[i].end){
            ;
        }else{
            current = segments[i].end;
            points.push_back(segments[i].end);
        }
    }

    for (size_t i = 0; i < segments.size(); ++i) {
        //points.push_back(segments[i].start);
        //points.push_back(segments[i].end);
    }
    return points;
}


int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }

    int start1 = clock();
    vector<int> points = optimal_points(segments);
    int stop1 = clock();

    std::cout << points.size() << "\n";

    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }

    double took1 = (stop1-start1)/double(CLOCKS_PER_SEC)*1000;
    printf("\n");
    printf("Computed in %lf ms.\n",took1);


}

