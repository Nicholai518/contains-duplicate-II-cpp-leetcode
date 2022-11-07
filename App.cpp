#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        // contains numbers and index
        unordered_map<int, int> mp;

        int size_of_nums = nums.size();

        // iterate through the vector
        for (int i = 0; i < size_of_nums; i++)
        {

            // check map for current element
            if (mp.count(nums[i]))
            {
                // if element exists in map
                // check the k requirements
                if (abs(i - mp[nums[i]]) <= k)
                {
                    return true;
                }
            }

            // otherwise add to map
            mp[nums[i]] = i;
        }

        // if we iterate through entire vector
        // return false
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> example_one = { 1, 2, 3, 1 };
    int k = 3;

    cout << "Example One : " << solution.containsNearbyDuplicate(example_one, k);

	return 0;
}
