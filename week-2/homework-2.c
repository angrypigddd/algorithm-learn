class Solution {
public:
   int findShortestSubArray(vector<int>& nums) {
        map<int,int> pos;
        map<int,int> num;
        int ans=std::numeric_limits<int>::max();
        int tmp=0;
        for(int i=0;i<nums.size();++i){
            ++num[nums[i]];
            if(num[nums[i]]==1){
                pos[nums[i]]=i;
            }
            if(num[nums[i]]>tmp){
                ans=i-pos[nums[i]]+1;
                tmp=num[nums[i]];
            }
            else if(num[nums[i]]==tmp){
                ans=min(ans,i-pos[nums[i]]+1);
                tmp=num[nums[i]];
            }
        }
        return ans;
    }
};
