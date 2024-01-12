#ifndef HASH_MAP_IMPL
#define HASH_MAP_IMPL

#include  <stdexcept>

template <typename T1, typename T2>
HashMap<T1, T2>::HashMap()
{
    table.resize(7, {0, nullptr});
}

template <typename T1, typename T2>
HashMap<T1, T2>::~HashMap()
{
    clear();
}

template <typename T1, typename T2>
void HashMap<T1, T2>::put(const T1& key, const T2& value)
{
    int index = hashing(key);
    if (table[index].second == nullptr)
    {
        table[index].second = new std::list<std::pair<T1, T2>>;
    }

    for (auto it = table[index].second->begin(); it != table[index].second->end(); ++it)
    {
        if(it->first == key) 
        {
            it->second = value;
            return;
        }
    }
    table[index].second->emplace_back(key, value);
    table[index].first++;
    if (table[index].first == table.size())
    {
        rehash();
    }
}

template <typename T1, typename T2>
T2 HashMap<T1, T2>::get(const T1& key) const
{
    int index = hashing(key);
    if (table[index].second != nullptr)
    {
        for (const auto& it : *table[index].second)
        {
            if (it.first == key)
            {
                return it.second;
            }
        }
    }
    throw std::runtime_error("Key not found");
}   

template <typename T1, typename T2>
void HashMap<T1, T2>::remove(const T1& key)
{
    int index = hashing(key);
    if (table[index].second != nullptr)
    {
        for (auto it = table[index].second->begin(); it != table[index].second->end(); ++it)
        {
            if (it->first == key)
            {
                table[index].second->erase(it);
                table[index].first--;
                if (table[index].second->empty())
                {
                    delete table[index].second;
                    table[index].second = nullptr;
                }
                return;
            }
        }
    }
}

template <typename T1, typename T2>
bool HashMap<T1, T2>::containsKey(const T1& key)
{
    int index = hashing(key);
    if (table[index].second != nullptr)
    {
        for (const auto& it : *table[index].second)
        {
            if (it.first == key)
            {
                return true;
            }
        }
    }
    return false;
}

template <typename T1, typename T2>
bool HashMap<T1, T2>::containsValue(const T2& value)
{
    for (const auto& elem : table)
    {
        if (elem.second != nullptr)
        {
            for (const auto& it : *elem.second)
            {
                if (it.second == value)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

template <typename T1, typename T2>
int HashMap<T1, T2>::size() const
{
    int sum = 0;
    for (const auto& it : table)
    {
        if (it.second != nullptr)
        {
            sum += it.first;
        }
    }
    return sum;
}   

template <typename T1, typename T2>
bool HashMap<T1, T2>::isEmpty() const
{
    return size() == 0;
}             

template <typename T1, typename T2>
void HashMap<T1, T2>::clear()
{
    for (int i = 0; i < table.size(); ++i)
    {
        if (table[i].second != nullptr)
        {
            delete table[i].second;
            table[i].second = nullptr;
        }
        table[i].first = 0;
    }
}   

template <typename T1, typename T2>
std::vector<T1> HashMap<T1, T2>::keySet()
{
    std::vector<T1> keys;
    for (const auto& elem : table)
    {
        if (elem.second != nullptr)
        {
            for (const auto& it : *elem.second)
            {
                keys.push_back(it.first);
            }
        }
    }
    return keys;
}

template <typename T1, typename T2>
std::vector<T2> HashMap<T1, T2>::valueSet()
{
    std::vector<T2> values;
    for (const auto& elem : table)
    {
        if (elem.second != nullptr)
        {
            for (const auto& it : *elem.second)
            {
                values.push_back(it.second);
            }
        }
    }
    return values;
}

template <typename T1, typename T2>
std::vector<std::pair<int, std::list<std::pair<T1,T2>>*>> HashMap<T1, T2>::entrySet()
{
    return table;
}

template <typename T1, typename T2>
void HashMap<T1, T2>::rehash()
{
    int new_size = next_prime(table.size());
    std::vector<std::pair<int, std::list<std::pair<T1, T2>>*>> new_table(new_size, {0, nullptr});
    for (const auto& elem : table)
    {
        if (elem.second != nullptr)
        {
            for (const auto& it : *elem.second)
            {
                int index = it.first % new_size;       
                if (new_table[index].second == nullptr)
                {
                    new_table[index].second = new std::list<std::pair<T1, T2>>;
                }
                new_table[index].second->emplace_back(it);
                new_table[index].first++;
            }
        }
    }
    table.swap(new_table);
}

template <typename T1, typename T2>
int HashMap<T1, T2>::hashing(const T1& key) const
{
    return key % table.size();
}

template <typename T1, typename T2>
int HashMap<T1, T2>::next_prime(int num)
{
    ++num;
    while (true)
    {
        bool flag = true;
        for (int i = 2; i * i <= num; ++i)
        {
            if (num % i == 0)
            {
                flag = false;
                break;;
            }
        }
        if (flag)
        {
            return num;
        }
        ++num;
    }
}

#endif  // HASH_MAP_IMPL