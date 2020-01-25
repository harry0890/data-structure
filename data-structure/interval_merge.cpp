


i = 0 i < 4 ;i++

if ( [1][0] <= [0][1] )
     [1][0] = [0][0]   // [1,3] [1,6] 
	 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n= intervals.size();
        vector<vector<int>> ans;

        if(n == 0) return ans;

        std::sort(intervals.begin(),intervals.end(),[](vector<int> &v1,vector<int> &v2){
            return v1[0]<v2[0];
        });
        
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else 
				ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
        return ans;   
    }
};

        head,end
           | |
Input  = [[1,3], [2,6], [8,10], [15,18]]
Output = [[1,6], [8,10], [15,18]]

head = [1]
end = [6]

i = 1 i < 4; i++

 if end < interval[1][0] // 2
     push_back 
	 
 if end < interval[1][1] // 6
    end = interval[1][1] // 3
 




















