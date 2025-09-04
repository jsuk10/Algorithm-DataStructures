#include <vector>
#include <string>
#include <iostream>
#include "CustomHashTableInterface.cpp"

using namespace std;

template <typename Key, typename Value>
class CustomHashTable2 : public IHashTable<Key, Value>
{
public:
    // note.jsuk10 Using Chaining for duplicate handling
    struct Entry
    {
        Entry(const Key &key, const Value &value) : key(key), value(value) { nextEntry = nullptr; };

        Key key;
        Value value;
        Entry *nextEntry;
    };

    int tableSize = 0;

    vector<Entry *> array;

public:
    CustomHashTable2(int size = 100)
    {
        array = vector<Entry *>(size, nullptr);
        tableSize = 0;
    }

    virtual ~CustomHashTable2()
    {
        for (auto a : array)
            delete a;
    }

    // 값 추가 또는 업데이트
    virtual void insert(const Key &key, const Value &value) override
    {
        Entry *entry = new Entry(key, value);
        int index = Hashing(key);
        Entry *target = array[index];

        if (target == nullptr)
        {
            array[index] = entry;
        }
        else
        {
            while (target->nextEntry != nullptr)
            {
                target = target->nextEntry;
            }
            target->nextEntry = entry;
        }
        tableSize++;
    };

    // 키 삭제 (성공하면 true, 없으면 false)
    virtual bool remove(const Key &key) override
    {
        int index = Hashing(key);
        if (array[index] == nullptr)
        {
            return false;
        }
        Entry *target = array[index];
        Entry *prev = nullptr;
        while (target != nullptr && target->key != key)
        {
            prev = target;
            target = target->nextEntry;
        }

        if (target == nullptr)
            return false;

        if (prev == nullptr)
        {
            array[index] = target->nextEntry;
        }
        else
        {
            prev->nextEntry = target->nextEntry;
        }
        delete target;
        tableSize--;

        return true;
    }

    // 키 검색 (있으면 outValue에 대입하고 true 반환)
    virtual Value *find(const Key &key) const override
    {
        int index = Hashing(key);
        Entry *target = array[index];

        while (target != nullptr && target->key != key)
        {
            target = target->nextEntry;
        }

        return target == nullptr ? nullptr : &target->value;
    }

    // 키 존재 여부
    virtual bool contains(const Key &key) const override
    {
        return find(key) != nullptr;
    }

    // 저장된 원소 개수
    virtual int size() const override
    {
        return tableSize;
    }

    // 비었는지 여부
    virtual bool empty() const override
    {
        return tableSize == 0;
    }

    // 전체 초기화
    virtual void clear() override
    {
        int capacity = array.size();
        for (int i = 0; i < array.size(); ++i)
        {
            Entry *current = array[i];
            while (current)
            {
                Entry *tmp = current;
                current = current->nextEntry;
                delete tmp;
            }
            array[i] = nullptr; // 실제 벡터 원소를 nullptr로 초기화
        }
        tableSize = 0;
    }

    virtual Value *operator[](const Key &target) override
    {
        return find(target);
    }

private:
    // 해쉬 구현은 일단 std::hash<T>사용
    int Hashing(const Key &key) const
    {
        return static_cast<int>(std::hash<Key>{}(key)) % array.size();
    }
};

int main()
{
    CustomHashTable2<string, int> h(1);
    h.insert("tt", 10);
    h.insert("b", 11);
    h.insert("c", 12);

    h.remove("b");
    cout << *h.find("tt") << endl;
    h.clear();
}