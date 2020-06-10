//
// Created by evyat on 09/06/2020.
//

#ifndef RACHEL_PAIR_H
#define RACHEL_PAIR_H
#include <iostream>

using namespace std;
/**
 *
 * @tparam K - the key class - needs to have overloaded operators ( ==, <, and 3 greats)
 * @tparam V - Value class - needs to have 3 greats.
 */
template<class K, class V>
class Pair{
public:

    Pair(K k,V v);
    Pair(const Pair& rhs);
    ~Pair();

    Pair &operator=(const Pair &rhs);

    bool operator==(const Pair &rhs) const;
    bool operator<(const Pair &rhs) const;
    K& getKey() const;
    void setKey(const K& key);
    V& getValue() const;
    void setValue(V val);

private:
    K key;
    V value;
};
template<class K, class V>
Pair<K,V>::Pair(K k, V v):key(k), value(v){}

template<class K, class V>
Pair<K,V>::Pair(const Pair& rhs):key(rhs.key), value(rhs.value){}

template<class K, class V>
Pair<K,V>& Pair<K,V>::operator=(const Pair &rhs){
        this->key = rhs.key;
        this->value = rhs.value;

        return *this;
}
template<class K, class V>
bool Pair<K,V>::operator==(const Pair<K, V> &rhs) const {
    return key ==rhs.key;
}
template<class K, class V>
bool Pair<K,V>::operator<(const Pair &rhs) const{
    return key < rhs.key;
}
template<class K, class V>
K& Pair<K,V>::getKey() const {
    return key;
}
template<class K, class V>
V& Pair<K,V>::getValue() const{
    return value;
}
template<class K, class V>
void Pair<K,V>::setKey(const K& k){
    this->key = k;
}
template<class K, class V>
void Pair<K,V>::setValue(V val){
    this->value = val;
}
template<class K, class V>
Pair<K,V>::~Pair(){
    delete key;
    delete value;
}
#endif //RACHEL_PAIR_H
