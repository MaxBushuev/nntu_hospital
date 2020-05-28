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
			void setName(string name);
			void setDiagnosis(string diagnosis);
			void setDepartment(string department);
			void setDays(int days);
			void setDate(string date);
			void setNext(Students* next);
			void print();

			string getName();
			string getDiagnosis();
			string getDepartment();
			int getDays();
			string getDate();

            friend ostream& operator<< (ostream &out, Patient &patient);
            friend istream& operator>> (istream &in, Patient &patient);
            friend ofstream& operator<< (ofstream &fout, Patient &patient);
            friend ifstream& operator>> (ifstream &fin, Patient &patient);
};



