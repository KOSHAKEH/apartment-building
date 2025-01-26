#pragma once
#include "Human.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

class Apartment {
private:
    vector<Human> residents;
public:
    Apartment() {}

    Apartment(const Apartment& other) : residents(other.residents) {}

    Apartment& operator=(const Apartment& other) {
        if (this == &other) {
            return *this;
        }
        residents = other.residents;
        return *this;
    }

    ~Apartment() {}

    void addResident(const Human& human) {
        residents.push_back(human);
    }

    void removeResident(Human& human) {
        residents.erase(remove(residents.begin(), residents.end(), human), residents.end());
    }

    void printResidents() const {
        if (residents.empty()) {
            cout << " вартира пуста." << endl;
        }
        else {
            cout << "∆ильцы квартиры: ";
            for (const auto& human : residents) {
                human.printName();
                cout << ", ";
            }
            cout << endl;
        }
    }

    int getResidentCount() const {
        return residents.size();
    }

    const Human& getResident(int index) const {
        return residents.at(index);
    }
};


