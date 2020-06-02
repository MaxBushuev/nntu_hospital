#ifndef PATIENTLIST_H
#define PATIENTLIST_H
#include "patient.h"

using namespace std;

class patientList {
public:
    patientList();
    ~patientList();
    int size();
    void changed(int n);
    void add(string name, string diagnosis, string departement, int days, string date);
    void remove(int n);
    void printWhole();
    void search(string name, string diagnosis, string departement, int days, string date);

private:
    Patient *head;
    int _size;
};

#endif // LIST_Hя
