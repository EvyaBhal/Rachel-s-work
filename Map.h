//
// Created by Evya on 09/06/2020.
//

#ifndef RACHEL_MAP_H
#define RACHEL_MAP_H
#include "Pair.h"
#include<iostream>

using namespace std;
template<class K, class V >
class Map{
public:
    enum{MAX = 6000}; // some default maximum capacity
    //c'tors and d'tors
    Map(int capacity = MAX);
    Map(const Map& rhs); //copy c'tor
    ~Map();

    //operators
    Map& operator=(const Map &rhs);
    void put(K key, V val);
    V* get(const K& key) const;
    void remove(const K& key);
    void clear();
    bool isEmpty();
    bool isFull();
    void print();
    unsigned int getSize();
    void pushBack(int index);
    void pullBack(int index);


private:
     int size;
     int capacity;
     Pair<K,V>* arr;
};
template<class K, class V>
Map<K,V>::Map(int capac):size(0),capacity(capac){
    arr = new Pair<K,V>[capacity];
}

template<class K, class V>
Map<K, V>::Map(const Map &rhs):size(rhs.size),capacity(rhs.capacity) {
    arr = new Pair<K,V>[capacity];
    for(int i = 0 ; i <size; ++i){
        arr[i] = rhs.arr[i];
    }
}

template<class K, class V>
Map<K, V>::~Map() {
    delete [] arr;
}

template<class K, class V>
Map<K,V>& Map<K, V>::operator=(const Map &rhs) {
    this->size = rhs.size;
    this->capacity = rhs.capacity;
    if(arr){
        delete [] arr;
    }
    arr = new Pair<K,V>[size];
    for(int i = 0 ; i < size; ++i){
        arr[i] = rhs.arr[i];

    }
    return *this;
}

template<class K, class V>
void Map<K, V>::put(K key, V val) {
    Pair<K,V> tmp = new Pair<K,V>(key,val);
    if(isEmpty()){
        arr[0] = tmp;
    }
    if(isFull()&& !get(key)){
        cerr << "Map is full"<<endl; // unlikely, max size is 6000..
        return;
    }
    else{
       for (int i = 0 ; i < size ; ++i) {
            if(tmp == arr[i]){
                arr[i].setValue(tmp.getValue());
                return;
            }

           if (tmp < arr[i]) {
               pushBack(i); // pushes from index i onward by 1.
               arr[i] = tmp;
               ++size;
               return;
           }
       }
       arr[size] = tmp;
    }
    ++size;
}

template<class K, class V>
V *Map<K, V>::get(const K &key) const {
    for(int i =0 ; i < size; ++i){
        if (key == arr[i].getKey()){
            return &(arr[i].getValue());
        }
    }
    return NULL;
}

template<class K, class V>
void Map<K, V>::remove(const K &key) {
    for(int i = 0; i < size; ++i){
        if(arr[i].getKey() == key){
            pullBack(i);
            --size;
            return;
        }
    }
}

template<class K, class V>
void Map<K, V>::clear() {
    delete [] arr;
    this->size = 0;
}

template<class K, class V>
bool Map<K, V>::isEmpty() {
    return size==0;
}

template<class K, class V>
void Map<K, V>::print() {
    for(int i = 0 ; i < size; ++i){
        cout<< arr[i].getKey()<< " "<<arr[i].getValue() << endl;
    }

}

template<class K, class V>
unsigned int Map<K, V>::getSize() {
    return size;
}

template <class K, class V>
void Map<K,V>::pushBack(int index) {
    for( int i = size-1 ; i >= index ; --i){
        arr[i+1] = arr[i];
    }
}
template <class K, class V>
bool Map<K,V>::isFull() {
    return size==capacity;
}
template <class K, class V>
void Map<K,V>::pullBack(int index){
    for(int i = index; i<size-1;++i){
        arr[i] = arr[i+1];
    }
}


#endif //RACHEL_MAP_H
