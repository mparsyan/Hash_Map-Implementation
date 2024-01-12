#ifndef HASH_MAP
#define HASH_MAP

#include <list>
#include <vector>
#include <utility>

template <typename T1, typename T2>
class HashMap
{
public:
    HashMap();
    ~HashMap();

public:                                                                        
    void put(const T1& key, const T2& value);                                                
    T2 get(const T1& key) const;                                                              
    void remove(const T1& key);
    bool containsKey(const T1& key);
    bool containsValue(const T2& value);
    int size() const;                                                                         
    bool isEmpty() const;                                                                     
    void clear();                                                                       
    std::vector<T1> keySet();
    std::vector<T2> valueSet();
    std::vector<std::pair<int , std::list<std::pair<T1,T2>>*>> entrySet();

private:
    std::vector<std::pair<int, std::list<std::pair<T1, T2>>*>> table;

private:
    void rehash();
    int hashing(const T1& key) const;
    int next_prime(int num);
};

#include "hash_map_impl.hpp"

#endif  // HASH_MAP