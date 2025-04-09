class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> hashMap;
        vector<int> ans;
        for(int num:nums2){
            while(!st.empty()&&num>st.top()){
                hashMap[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
            while(!st.empty()){
                hashMap[st.top()]=-1;
                st.pop();
            }
           
            for(auto num:nums1){
                if(hashMap.find(num)!=hashMap.end()){
                   ans.push_back(hashMap[num]);
                }
            }

        
        return ans;
    }
};
