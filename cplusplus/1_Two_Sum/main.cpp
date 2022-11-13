#include <iostream>
//#include <vector>
//#include <map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> result(vector<int>& nums,int target){
        vector<int> result;
        unordered_map<int, int> nums_map;
        for(int i = 0; i<nums.size(); i++){
            nums_map[nums[i]] = i;
        }

        for(int i = 0;i < nums.size();i++){
            auto position = nums_map.find(target - nums[i]);
           // cout <<"find "<<i << ' '<< nums[i] << ' ' << endl;
            if( position != nums_map.end() && position->second != i){
               // cout <<i << ' '<< nums[i] << ' ' << endl;
                result.push_back(i);
                result.push_back(position->second);
                break;
            }
        }
        return std::move(result);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    Solution sol;
    vector<int> nums = {2,7,11,15};
    vector<int> result = sol.result(nums,9);
    for(int i = 0; i < result.size() ;i++)
        cout << result[i] <<endl;
    return 0;
}
