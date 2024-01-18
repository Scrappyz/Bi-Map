#pragma once

#include <iostream>
#include <unordered_map>

template<typename K, typename V>
class BiMap {
    private:
        std::unordered_map<K, V> m1;
        std::unordered_map<V, K> m2;

    public:
        BiMap() : m1(), m2() {}
        BiMap(const std::unordered_map<K, V>& m) : m1(), m2() 
        {
            set(m);
        }
        BiMap(const std::initializer_list<std::pair<K, V>>& l) : m1(), m2() 
        {
            set(l);
        }

        const std::unordered_map<K, V>& getMap()
        {
            return m1;
        }

        const std::unordered_map<V, K>& getInverseMap()
        {
            return m2;
        }

        const V& at(const K& k)
        {
            return m1.at(k);
        }

        const K& atInverse(const V& v)
        {
            return m2.at(v);
        }

        void set(const std::unordered_map<K, V>& m)
        {
            m1.clear();
            m2.clear();
            for(const auto& i : m) {
                if(m2.count(i.second) > 0) {
                    throw std::runtime_error("duplicate value");
                }
                m2[i.second] = i.first;
            }
            m1 = m;
        }

        void set(const std::initializer_list<std::pair<K, V>>& l)
        {
            std::unordered_map<K, V> m;
            for(const auto& i : l) {
                m[i.first] = i.second;
            }
            set(m);
        }

        void setValue(const K& key, const V& value)
        {
            if(valueExist(value)) {
                throw std::runtime_error("duplicate value");
            }
            V m2_key = m1.at(key);
            m1[key] = value;
            std::pair new_val = {value, m2.at(m2_key)};
            m2.erase(m2_key);
            m2.insert(new_val);
        }

        void insert(const K& key, const V& value)
        {
            if(keyExist(key)) {
                throw std::runtime_error("duplicate key");
            } else if(valueExist(value)) {
                throw std::runtime_error("duplicate value");
            }

            m1.insert({key, value});
            m2.insert({value, key});
        }

        void remove(const K& key)
        {
            if(!keyExist(key)) {
                return;
            }
            
            V m2_key = m1.at(key);
            m1.erase(key);
            m2.erase(m2_key);
        }

        bool keyExist(const K& key)
        {
            return m1.count(key) > 0;
        }

        bool valueExist(const V& value)
        {
            return m2.count(value) > 0;
        }

        void operator=(const std::unordered_map<K, V>& m)
        {
            set(m);
        }

        void operator=(const std::initializer_list<std::pair<K, V>>& l)
        {
            set(l);
        }

        void printMap()
        {
            std::cout << "m1: " << std::endl;
            for(const auto& i : m1) {
                std::cout << i.first << " | " << i.second << std::endl;
            }
            std::cout << "m2: " << std::endl;
            for(const auto& i : m2) {
                std::cout << i.first << " | " << i.second << std::endl;
            }
        }
};