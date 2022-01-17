/*   DUPLICATE IN ARRAY USING CPP\


Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


CODE 

*/

int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int c=0;
        sort(nums.begin(),nums.end());
        int index=nums[0];
        for(int x=1;x<len;x++){
            if(index==nums[x]){
                index=nums[x];
                break;
            }else{
                index=nums[x];
            }
        }
        
        return index;
    } 
