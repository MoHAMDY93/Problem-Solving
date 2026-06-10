// Last updated: 6/10/2026, 7:25:00 PM
class RandomizedSet {
public:
    vector<int> values;
    unordered_map<int, int> valToIndex;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;

        int index = valToIndex[val];
        int lastVal = values.back();

        values[index] = lastVal;                  // move last element to the 'index' position
        valToIndex[lastVal] = index;              // update map with new index for lastVal

        values.pop_back();                        // remove last element
        valToIndex.erase(val);                    // erase val from map

        return true;   
    }
    
    int getRandom() {
        int randIndex = rand() % values.size();
        return values[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */