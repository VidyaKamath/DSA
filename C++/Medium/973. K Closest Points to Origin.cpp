class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> max_heap;
        vector<vector<int>> res;
        double distance;
        for(int i=0; i<points.size(); i++){
            distance = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            max_heap.push({distance, points[i]});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }

        //fetch the k closest elements to the origin
        while(max_heap.size()>0){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
    
};
