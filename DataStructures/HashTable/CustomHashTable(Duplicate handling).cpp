#include <vector>
#include <string>
#include <iostream>
#include "CustomHashTableInterface.cpp"

using namespace std;

template <typename Key, typename Value>
class CustomHashTable2 : public IHashTable<Key, Value>
{

public:
    virtual ~CustomHashTable2();

    // 값 추가 또는 업데이트
    virtual void insert(const Key &key, const Value &value)
    {
        return;
    };

    // 키 삭제 (성공하면 true, 없으면 false)
    virtual bool remove(const Key &key)
    {
        return false;
    }

    // 키 검색 (있으면 outValue에 대입하고 true 반환)
    virtual Value *find(const Key &key)
    {
        return nullptr;
    }

    // 키 존재 여부
    virtual bool contains(const Key &key) const
    {
        return true;
    }

    // 저장된 원소 개수
    virtual int size() const
    {
        return 0;
    }

    // 비었는지 여부
    virtual bool empty() const
    {
        return true;
    }

    // 전체 초기화
    virtual void clear()
    {
        return;
    }

    virtual Value *operator[](const Key &target) const
    {
        return nullptr;
    }

private:
    // 해쉬 구현은 일단 std::hash<T>사용
    int Hashing(const Key &key) const
    {
        return static_cast<int>(std::hash<Key>{}(key)) % Array.size();
    }
};