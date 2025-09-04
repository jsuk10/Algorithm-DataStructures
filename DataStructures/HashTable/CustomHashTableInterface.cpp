
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename Key, typename Value>
class IHashTable
{
public:
    virtual ~IHashTable() = default;

    // 값 추가 또는 업데이트
    virtual void insert(const Key &key, const Value &value) = 0;

    // 키 삭제 (성공하면 true, 없으면 false)
    virtual bool remove(const Key &key) = 0;

    // 키 검색 (있으면 outValue에 대입하고 true 반환)
    virtual Value *find(const Key &key) const = 0;

    // 키 존재 여부
    virtual bool contains(const Key &key) const = 0;

    // 저장된 원소 개수
    virtual int size() const = 0;

    // 비었는지 여부
    virtual bool empty() const = 0;

    // 전체 초기화
    virtual void clear() = 0;

    virtual Value *operator[](Key &target) const = 0;
};