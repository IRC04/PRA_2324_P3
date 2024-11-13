#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;

	int h(string key){
		int n = key.length();
		int sum = 0;
		char c;

		for(int i=0; i<n; i++){
			c = key.at(i);
			sum += int(c);
		}

		return sum % max;
	};

    public:
        void insert(string key, V value) override {
		for (int i=0; i<max; i++){
			if (table[i].key == key){
				throw runtime_error();
			}
		}
		TableEntry (key, value);
	}

        V search(string key) override {
		for (int i=0; i<max; i++){
                        if (table[i].key == key){
                        	return table[i].value();
			}
                }
		throw runtime_error();
	}

        V remove(string key) override {
		for (int i=0; i<max; i++){
                        if (table[i].key == key){
                                delete[] table[i];
                        }
                }
                throw runtime_error();
	}

        int entries() override {
		return n;
	}

	HashTable(int size) {
		table = new ListLinked<TableEntry<V>>[size];
		n = 0;
        	max = size;
	}

	~HashTable() {
		delete[] table;
	}

	int capacity() {
		return max;
	}

	friend ostream& operator<<(ostream &out, const HashTable<V> &th) {
		for (int i = 0; i < th.capacity(); ++i) {
                	out << "Cubeta " << i << ": " << th.table[i] << endl;
		}
            	return out;
	}

	V operator[](string key) {
		if(key.length()!=0){
			return key;
		} else {
			throw runtime_error();
		}
	}
};

#endif
