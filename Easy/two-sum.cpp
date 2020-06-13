/*1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

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

// Using STL Find
// Note : Given Elements must be sorted
// Time Complexity O(NLogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int compEle = target - ele;
            vector <int>::iterator i1;
            i1 = std::find(nums.begin(), nums.end(), compEle);
            if(i1 != nums.end()){
                result.push_back(i);
                result.push_back(i1-nums.begin());
                return result;
            }
        }
        return result;
    }
};

// Using Binary Search
// Note : Given Elements must be sorted
// Time Complexity O(NLogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int ele = nums[i];
            int compEle = target - ele;
            int index = binarySearch(nums, 0, nums.size() -1, compEle);
            if(index != - 1){
                result.push_back(i);
                result.push_back(index);
                return result;
            }
        }
        return result;
    }
    
    int binarySearch(vector<int> arr, int p, int r, int num) {
        if (p <= r) {
            int mid = (p + r)/2; 
        if (arr[mid] == num)   
            return mid ; 
        if (arr[mid] > num)  
            return binarySearch(arr, p, mid-1, num);            
        if (arr[mid] > num)
            return binarySearch(arr, mid+1, r, num); 
   }
   return -1; 
}   
};

// Map Approach
// Time Complexity O(logN)
// Runtime: 20 ms
// Memory Usage: 10.2 MB
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map <int, int> HashMap;
        for(int i = 0; i < nums.size(); i++){
            HashMap.insert(make_pair(nums[i],i));
            auto it = HashMap.find(target - nums [i] );
            if(it != HashMap.end() && it->second!= i){
                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }
};