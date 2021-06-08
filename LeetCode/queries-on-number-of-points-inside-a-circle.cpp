class Solution {
public:
    bool isInside(double x1, double y1, double x2, double y2, double r) {
        return hypot(x1 - x2, y1 - y2) <= r;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> pointsCounted;
        int count;

        for (int i = 0; i < queries.size(); ++i) {
            count = 0;

            for (int j = 0; j < points.size(); ++j) {
                if (isInside(
                    points[j][0],
                    points[j][1],
                    queries[i][0],
                    queries[i][1],
                    queries[i][2])) {
                    ++count;
                }
            }
            
            pointsCounted.push_back(count);
        }
        
        return pointsCounted;
    }
};