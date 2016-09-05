#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	struct Number
	{
        int index;
        int value;
        
        Number()
        {
            this->index = -1;
            this->value = -1;
        }
        
        Number(int value)
        {
            this->index = -1;
            this->value = value;
        }
        
        Number(unsigned int index, int value)
        {
            this->index = index;
            this->value = value;
        }
        
        bool operator() (Number num1, Number num2)
        {
            return (num1.value < num2.value);
        }
	} number;
    
    int binarySearch(vector<Number>& nums, int start, int end, int num)
    {
        if (start > end) { return -1; }
        int mid = start + (end - start) / 2;
        if (nums[mid].value > num) { return binarySearch(nums, start, mid - 1, num); }
        if (nums[mid].value < num) { return binarySearch(nums, mid + 1, end, num); }
        return mid;
    }
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Number> newNums;
        for (int i = 0; i < nums.size(); ++i) {
            newNums.push_back(Number(i, nums[i]));
        }
    	sort(newNums.begin(), newNums.end(), number);
        vector<int> result;
        for (int i = 0; i < newNums.size(); ++i) {
            int index = this->binarySearch(newNums, i+1, newNums.size()-1, target - newNums[i].value);
            if (index >= 0) {
                result.push_back(newNums[i].index);
                result.push_back(newNums[index].index);
                break;
            }
        }
        return result;
    }
};

int main()
{
	Solution *solu = new Solution();
	int n[] = {2, 7, 23, 1, 3} ;
	vector<int> nums(n, n+5);
	vector<int> indexs = solu->twoSum(nums, 9);
	return 0;
}