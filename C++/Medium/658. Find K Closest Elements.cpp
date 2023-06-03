class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> max_heap;
        vector<int> res;

        for(int i=0; i<arr.size(); i++){
            max_heap.push({abs(arr[i]-x), arr[i]});
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }

        while(max_heap.size()>0){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(res.begin(), res.end());
        return res;    
    }
};
