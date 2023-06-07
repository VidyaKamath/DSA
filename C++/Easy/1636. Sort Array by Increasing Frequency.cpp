class myComparator{
public:
   bool operator()(pair<int,int>&p1,pair<int,int>&p2){
       if(p1.first>p2.first){   
           return true;
       }
            
       else if(p1.first<p2.first){
           return false;
       }
       else{
           if(p1.second<p2.second){
               return true;
           }
           else return false; 
       }
   }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int,int>>, myComparator> min_heap;
        vector<int> res;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i: mp){
            min_heap.push({i.second, i.first});
        }

        while(min_heap.size() > 0){
            for(int i=0; i<min_heap.top().first; i++){
                res.push_back(min_heap.top().second);
            }
            min_heap.pop();     
        } 
        return res;   
    }
};
