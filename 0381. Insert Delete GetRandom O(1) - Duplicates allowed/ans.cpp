class RandomizedCollection
{
private:
    vector<int> v;
    unordered_map<int, int> m;

public:
    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        if (m[val] == 0)
        {
            v.push_back(val);
            m[val]++;
            return true;
        }
        else if (m[val] > 0)
        {
            v.push_back(val);
            m[val]++;
            return false;
        }
        return false;
    }

    bool remove(int val)
    {
        if (m[val] > 0)
        {
            auto it = find(v.begin(), v.end(), val);
            v.erase(it);
            m[val]--;
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */