#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

class Human {
private:
    char* fullName;
public:
    Human() : fullName(nullptr) {}

    Human(const char* name) {
        if (name == nullptr) {
            fullName = nullptr;
        }
        else {
            this->fullName = new char[strlen(name) + 1];
            strcpy(this->fullName, name);
        }
    }

    Human(const Human& other) {
        if (other.fullName == nullptr)
        {
            this->fullName = nullptr;
        }
        else {
            this->fullName = new char[strlen(other.fullName) + 1];
            strcpy(this->fullName, other.fullName);
        }

    }

    Human& operator=(const Human& other) {
        if (this == &other) {
            return *this;
        }
        delete[] this->fullName;
        if (other.fullName == nullptr) {
            this->fullName = nullptr;
        }
        else {
            this->fullName = new char[strlen(other.fullName) + 1];
            strcpy(this->fullName, other.fullName);
        }
        return *this;
    }

    ~Human() {
        delete[] this->fullName;
        this->fullName = nullptr;
    }

    void printName() const {
        if (this->fullName != nullptr) {
            cout << this->fullName;
        }
        else {
            cout << "No name";
        }
    }

    const char* getName() const {
        return this->fullName;
    }

    void setName(const char* name) {
        delete[] this->fullName;
        if (name == nullptr) {
            this->fullName = nullptr;
        }
        else {
            this->fullName = new char[strlen(name) + 1];
            strcpy(this->fullName, name);
        }
    }

    bool operator==(const Human& other) const
    {
        if (this->fullName == nullptr && other.fullName == nullptr) {
            return true;
        }
        if (this->fullName == nullptr || other.fullName == nullptr) {
            return false;
        }
        return strcmp(this->fullName, other.fullName) == 0;
    }
};

