class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> index;
    RandomizedSet() {   
    }
    bool insert(int val) {
        if (index.find(val) != index.end()) {
            return false;
        }
        nums.push_back(val);
        index[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (index.find(val) == index.end()) {
            return false;
        }
        int removeIndex = index[val];
        int lastValue = nums.back();
        nums[removeIndex] = lastValue;
        index[lastValue] = removeIndex;
        nums.pop_back();
        index.erase(val);
        return true;
    }
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};