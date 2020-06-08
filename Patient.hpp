#include <string>
using namespace std;
class Patient{
	private:
			string _name;
			string _diagnosis;
			string _department;
			int _days;
			string _date;
			Patient* _next;
        public:
			Patient();
			Patient(string name, string diagnosis, string department, int days, string date);
			void setName(string name);
			void setDiagnosis(string diagnosis);
			void setDepartment(string department);
			void setDays(int days);
			void setDate(string date);
			void setNext(Patient* next);
			void print();

			string getName();
			string getDiagnosis();
			string getDepartment();
			int getDays();
			string getDate();
			Patient* next();
};
