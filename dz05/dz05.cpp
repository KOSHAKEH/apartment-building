#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include "Human.h"
#include "Apartment.h"
#include "House.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    Human human1("Иванов Иван Иванович");
    Human human2("Петров Петр Петрович");
    Human human3("Сидоров Сидор Сидорович");
    Human human4 = human1;

    Apartment apartment1;
    Apartment apartment2;

    apartment1.addResident(human1);
    apartment1.addResident(human2);
    apartment2.addResident(human3);

    House house;

    house.addApartment(apartment1);
    house.addApartment(apartment2);

    house.printAllApartments();
    cout << endl;
    cout << "В доме " << house.getApartmentCount() << " квартир." << endl;
    cout << "В первой квартире " << house.getApartment(0).getResidentCount() << " жильца." << endl;
    cout << "Во второй квартире " << house.getApartment(1).getResidentCount() << " жильцов." << endl;

    cout << "Жильцы первой квартиры: ";
    house.getApartment(0).printResidents();

    cout << "Жильцы второй квартиры: ";
    house.getApartment(1).printResidents();

    House house2 = house;
    cout << "\nИнформация о скопированном доме:" << endl;
    house2.printAllApartments();
    cout << endl;

    cout << "Удаление жильца из первой квартиры:" << endl;
    house.getApartment(0).removeResident(human1);
    house.printAllApartments();

    Human human5;
    human5 = human2;
    cout << "\nИмя human5: ";
    human5.printName();
    cout << endl;

    human5.setName("Алексей");
    cout << "Новое имя human5: ";
    human5.printName();
    cout << endl;

    cout << "Имя human5: " << human5.getName() << endl;

    if (human1 == human4) {
        cout << "\nHuman 1 и Human 4 равны" << endl;
    }
    else
    {
        cout << "\nHuman 1 и Human 4 не равны" << endl;
    }

    Human human6("Алексей");
    if (human5 == human6) {
        cout << "Human 5 и Human 6 равны" << endl;
    }
    else
    {
        cout << "Human 5 и Human 6 не равны" << endl;
    }

    return 0;
}