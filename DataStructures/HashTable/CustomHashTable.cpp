
#include <vector>
#include <string>
#include <iostream>
#include "CustomHashTableInterface.cpp"

using namespace std;

template <typename Key, typename Value>
class CustomHashTable : public IHashTable<Key, Value>
{
    vector<Value> Array;

public:
    CustomHashTable(int initialCapacity = 100)
    {
        Array = vector<Value>(initialCapacity);
    }

    ~CustomHashTable() override {}

    void insert(const Key &key, const Value &value) override
    {
        int index = Hashing(key);
        Array[index] = value;
    }

    bool remove(const Key &key) override
    {
        return false;
    }

    bool find(const Key &key, Value &outValue) const override
    {
        return false;
    }

    bool contains(const Key &key) const override
    {
        return false;
    }

    int size() const override
    {
        return 0;
    }

    bool empty() const override
    {
        return true;
    }

    void clear() override
    {
    }

    Value operator[](Key target) const override
    {
        int index = Hashing(target);
        return Array[index];
    };

private:
    // 해쉬 구현은 일단 std::hash<T>사용
    int Hashing(Key target) const
    {
        return static_cast<int>(std::hash<Key>{}(target)) % Array.size();
    }
};

int main()
{
    string s = "test";

    CustomHashTable<string, int> hash;
    hash.insert(s, 10);

    cout << hash[s] << endl;
}