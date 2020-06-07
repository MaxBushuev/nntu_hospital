#define N 10

#include <string>
#include "patientList.hpp"
using namespace std;
class hospDepartment{
	private:
		string _name;
		int _maxDoctors;
		int _availableDoctors;
		int _maxPlaceNumber;
		int _placeNubmer;
		patientList _list;
		patientList _in_hospital;
	public:
		hospDepartment();
		string getName();	
		int getMaxAvailableDoctors();
		int getAvailableDoctors();
		int setMaxAvailableDoctors(int maxAvailableDoctors);
		void setAvaiableDoctors(int availableDoctors);
		int getMaxPlaceNumber();
		void setMaxPlaceNumber(int maxPlaceNumber);
		int getPlaceNumber();
		void setPlaceNumber(int placeNumber);
		void readFromFile(string file_patient, string file_in_hospital);
		void writeToFile();
		void printList();
		void print_in_hospital();
}
