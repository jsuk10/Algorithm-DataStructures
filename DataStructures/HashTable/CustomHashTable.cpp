
#include <vector>
#include <string>
#include <iostream>
#include "CustomHashTableInterface.cpp"

using namespace std;

template <typename Key, typename Value>
class CustomHashTable : public IHashTable<Key, Value>
{
    vector<Value *> Array;

public:
    CustomHashTable(int initialCapacity = 100)
    {
        // init nullptr
        Array = vector<Value *>(initialCapacity, nullptr);
    }

    ~CustomHashTable() override
    {
        for (auto Item : Array)
        {
            delete Item;
        }
    }

    void insert(const Key &key, const Value &value) override
    {
        int index = Hashing(key);
        Array[index] = new Value(value);
    }

    bool remove(const Key &key) override
    {
        Value *target = find(key);
        if (target == nullptr)
        {
            return false;
        }
        else
        {
            delete target;
            // init nullptr, Invalid memory access defense
            Array[index] = nullptr;
            return true;
        }
    }

    Value *find(const Key &key) const override
    {
        return Array[Hashing(key)];
    }

    bool contains(const Key &key) const override
    {
        return find(key) != nullptr;
    }

    int size() const override
    {
        return Array.size();
    }

    bool empty() const override
    {
        return Array.size() == 0;
    }

    void clear() override
    {
        // add memeory free
        for (auto item : array)
            delete item;
        Array.clear();
    }

    Value *operator[](Key &key) const override
    {
        Value *target = find(key);
        if (target == nullptr)
        {
            throw std::runtime_error("Invalie Key is not contain!");
        }
        return target;
    };

private:
    // 해쉬 구현은 일단 std::hash<T>사용
    int Hashing(Key &key) const
    {
        return static_cast<int>(std::hash<Key>{}(key)) % Array.size();
    }
};

int main()
{
    string s = "test";

    CustomHashTable<string, int> hash;
    hash.insert(s, 10);

    cout << *hash[s] << endl;
}