SRC = Patient.o patientList.o hospDepartment.o methods.o main.o
TARGET = hospital
all: $(TARGET)

main.o: main.cpp
	g++ -Wall -g -c -o main.o main.cpp

Patient.o: Patient.cpp
	g++ -Wall -g -c -o Patient.o Patient.cpp

patientList.o: patientList.cpp
	g++ -Wall -g -c -o patientList.o patientList.cpp

hospDepartment.o: hospDepartment.cpp
	g++ -Wall -g -c -o hospDepartment.o hospDepartment.cpp

methods.o:
	g++ -Wall -g -c -o methods.o methods.cpp
$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

clean:
	rm -rf $(SRC)
