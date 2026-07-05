class Solution {
public:
    void findComb(int index, int target, vector<int>& candidates,vector<vector<int>> &ans, vector<int> ds){
       if(index==candidates.size()) {
        if(target==0) {ans.push_back(ds);
       }
        return;
       }

       // pick 
       if(candidates[index]<=target){
        ds.push_back(candidates[index]);
        findComb(index,target-candidates[index],candidates,ans,ds);
        ds.pop_back();
       }

       // not pick leave it
       findComb(index+1,target,candidates,ans,ds);

    }
        vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};