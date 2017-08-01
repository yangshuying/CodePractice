#include <vector>
#include <unordered_map>

using namespace std;
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		bool flag = false;
		for (int i = 0;i<nums.size() - 1;i++) {
			flag = false;
			int num2 = target - nums[i];
			for (int j = i + 1;j<nums.size();j++) {
				if (nums[j] == num2) {
					result.push_back(i);
					result.push_back(j);
					flag = true;
					break;
				}
			}
			if (flag == true) break;
		}
		return result;
	}


//2刷，采用unordered_map 但是注意 要选没选过的
	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> vec;
		unordered_map<int, int> m;
		for (int i = 0;i<nums.size();i++) {
			m[nums[i]] = i;
		}
		for (int i = 0;i<nums.size();i++) {
			if (m.find(target - nums[i]) != m.end()) {
				if (m[target - nums[i]] != i) {
					vec.push_back(i);
					vec.push_back(m[target - nums[i]]);
					break;
				}
			}
		}
		return vec;
	}
