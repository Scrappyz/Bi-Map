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

        V get(const K& key)
        {
            return m1.at(key);
        }

        K getInverse(const V& key)
        {
            return m2.at(key);
        }

        void set(const std::unordered_map<K, V>& m)
        {
            m1.clear();
            m2.clear();
            for(const auto& i : m) {
                if(m2.count(i.second) > 0) {
                    throw "Duplicate";
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