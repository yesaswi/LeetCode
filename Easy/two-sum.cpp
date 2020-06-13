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

// Two Pointers approach
// Note : Given Elements must be sorted
// Time Complexity O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int low, high;
        low = 0, high = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            if( nums [low] + nums [high] == target){
                result.push_back(low);
                result.push_back(high);
                return result;
            }
            else if(nums [low] + nums [high] < target && high!=low)
                low+=1;
            else if(nums [low] + nums [high] > target && high!=low)
                high-=1;
        }
        return result;
    }
};
