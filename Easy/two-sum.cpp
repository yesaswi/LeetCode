// Brute Force Approach
// Time Complexity O(N^2)
// Runtime: 580 ms
// Memory Usage: 9.1 MB
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++ ){
                if( nums [i] + nums [j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        return result;
    }
};
