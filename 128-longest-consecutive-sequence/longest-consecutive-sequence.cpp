// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
        
//         int n = nums.size(),count=1,mx=1;
//         if(nums.size() == 0) return 0;

//         sort(nums.begin(), nums.end());
        
//         for(int i=0;i<n-1;i++)
//         {
//             if(nums[i] == nums[i+1]-1)
//                 count++;
//             else if(nums[i] != nums[i+1])
//             {
//                 count = 1;
//                 //mx = max(mx,count);
//             }
//             mx = max(mx,count);
//         }
//         return mx;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        if(n==0) return n;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt+=1;
                }
                longest=max(longest,cnt);

            }
           

        }
        return longest;
    }
};