#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0; 
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j <points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    double determinant = points[i][0]*(points[j][1] - points[k][1]) + points[j][0]*(points[k][1] - points[i][1]) + points[k][0]*(points[i][1] - points[j][1]);
                    double temp_area = 0.5 * abs(determinant);
                    area = max(area, temp_area);
                }
            }
        }
        return area;
    }
};