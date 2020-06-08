#define N 10
#define M 7
#include <string>
#include "patientList.h"
using namespace std;
class hospDepartment{
	private:
		string _name;
		int _doctors;
		int _maxPlaceNumber;
		int _placeNumber;
		int _canTake;
		patientList _list;
		patientList _in_hospital;
	public:
		hospDepartment();
		hospDepartment(string name, int doctors, int maxPlaceNumbers);
		string getName();
		int getDoctors();
		void setDoctors(int doctors);
		int getMaxPlaceNumber();
		void setMaxPlaceNumber(int maxPlaceNumber);
		int getPlaceNumber();
		void setPlaceNumber(int placeNumber);
		int getCanTake();
		void setCanTake(int canTake);
		void add_list(Patient* temp);
		void add_in_hospital(Patient* temp);
		void readFromFile(string file_patient, string file_in_hospital);
		void writeToFile(string file_patient, string file_in_hospital);
		void search(string name, string diagnosis, string date);
		void printList();
		void print_in_hospital();
		void discharm(int n);
};
