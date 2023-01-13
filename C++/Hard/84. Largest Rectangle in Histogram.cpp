class Solution {
public:
    
    vector<int> NearestSmallestLeft(vector<int>& heights){

        stack<pair<int, int>> s;
        vector<int> nsl;
        int pseudo_idx  = -1;

        for(int i=0;i<heights.size();i++){
            while(s.size()!=0 && s.top().first >= heights[i]){
                s.pop();
            }

            if(s.size()==0){
                nsl.push_back(pseudo_idx);
            }
            else if(s.size()!=0 && s.top().first < heights[i]){
                nsl.push_back(s.top().second);
            }
        
            s.push({heights[i], i});
        
        }

        return nsl;
    }

    vector<int> NearestSmallestRight(vector<int>& heights){

        stack<pair<int, int>> s;
        vector<int> nsr;
        int pseudo_idx  = heights.size();

        for(int i=heights.size()-1;i>=0;i--){
            while(s.size()!=0 && s.top().first >= heights[i]){
                s.pop();
            }

            if(s.size()==0){
                nsr.push_back(pseudo_idx);
            }
            else if(s.top().first< heights[i]){
                nsr.push_back(s.top().second);
            }
            s.push({heights[i], i});
        
        }
        reverse(nsr.begin(), nsr.end());
        return nsr;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> area;
        // NSL
        vector<int> nsl = NearestSmallestLeft(heights);
        // NSR
        vector<int> nsr = NearestSmallestRight(heights);
        // Calculate area
        for(int i =0; i<heights.size(); i++){
            int width = nsr[i] - nsl[i] - 1;
            area.push_back(width*heights[i]);
        }
        return *max_element(area.begin(), area.end());
    }   

};
