#ifndef PATIENTLIST_H
#define PATIENTLIST_H
#include "Patient.hpp"

using namespace std;

class patientList {
public:
    Patient* head;

    patientList();
    ~patientList();
    int size();
    void changed(int n);
    void add(Patient* t);
    void add(string name, string diagnosis, string departement, int days, string date);\
    void popHead();
    void remove(int n);
    void printWhole();
    void search(string name, string diagnosis, string departement, int days, string date);

private:
    int _size;
};

#endif // LIST_Hя
