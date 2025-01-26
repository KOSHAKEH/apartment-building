#pragma once
#include "Apartment.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

class House {
private:
    vector<Apartment> apartments;
public:
    House() {}
    House(const House& other) : apartments(other.apartments) {}

    House& operator=(const House& other) {
        if (this == &other) {
            return *this;
        }
        apartments = other.apartments;
        return *this;
    }

    ~House() {}

    void addApartment(const Apartment& apartment) {
        apartments.push_back(apartment);
    }

    void printAllApartments() const {
        if (apartments.empty()) {
            cout << "��� ����." << endl;
        }
        else {
            cout << "�������� � ����:" << endl;
            for (size_t i = 0; i < apartments.size(); ++i) {
                cout << "�������� " << i + 1 << ": ";
                apartments[i].printResidents();
            }
        }
    }

    const Apartment& getApartment(int index) const {
        return apartments.at(index);
    }

    int getApartmentCount() const {
        return apartments.size();
    }

};

