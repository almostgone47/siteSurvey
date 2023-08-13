CC = g++
CPPFLAGS = -std=c++17 -Wall -g

process: ../site_survey/process.o datalogger.o linkedlist.o sensordata.o

process.o: ../site_survey/process.cpp

datalogger.o: ../site_survey/datalogger.cpp datalogger.h

linkedlist.o: ../site_survey/linkedlist.cpp linkedlist.h

sensordata.o: ../site_survey/sensordata.cpp sensordata.h

clean:
	rm *.o process