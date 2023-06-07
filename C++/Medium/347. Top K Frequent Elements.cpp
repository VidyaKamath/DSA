class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> res;

        //find the frequency of elements and stor it in a map
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        //use the frequency as the key in prioroty_queue
        for(auto i: mp){
            min_heap.push({i.second, i.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }

        //fetch the top k frequent elements
        while(min_heap.size() > 0){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
