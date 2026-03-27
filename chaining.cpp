#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    list<string> table[SIZE];

public:
    int hashFunction(string name) {
        int sum = 0;
        for (char c : name) {
            sum += c;
        }
        return sum % SIZE;
    }

    void insert(string name) {
        int index = hashFunction(name);
        table[index].push_back(name);
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto name : table[i]) {
                cout << name << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable h;

    string data[] = {"Ando","Beni","Citra","Doni","Eka","Eko","Gina","Intan","Joko","Kevin"};

    for (string name : data) {
        h.insert(name);
    }

    h.display();
}