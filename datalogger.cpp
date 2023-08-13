//
// Created by Jeremiah Barro on 29/6/2023.
//
#include <iostream>
#include "datalogger.h"

//Name:   DataLogger()
//Desc:   Constructor for DataLogger class.
//input:  none.
//output: none
//return: none
DataLogger::DataLogger() {
};

//Name:   addData()
//Desc:   Adds new Sensor Data to the linked list.
//input:  Three integers for the sector number, iron level and the silicon level.
//output: none
//return: none
void DataLogger::addData(int sector, int iron, int silicon) {
    SensorData newSensorData(sector, iron, silicon);
    list.addSensorData(newSensorData);
};

//Name:   containsSector()
//Desc:   Exposes the linked list's containsSector method which will return a true or false if the
//        sector number searched for is found in the linked list.
//input:  An integer for the sector number being searched for.
//output: none
//return: A boolean representing whether the sector was found in the linked list.
bool DataLogger::containsSector(int sector) {
    return list.containsSector(sector);
};

//Name:   removeSector()
//Desc:   Exposes the linked list's removeSector method which remove a sector based on the number passed into the method.
//input:  An integer representing the sector number to be removed.
//output: none
//return: none
void DataLogger::removeSector(int sector) {
    list.removeSector(sector);
};

//Name:   printReport()
//Desc:   Exposes the linked list's print functionality for sector number, iron level and silicon level.
//input:  none
//output: Prints all data by sector number, then iron level, then silicon level.
//return: none
void DataLogger::printReport() const {
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Data values" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << "Data by Sector" << endl;
    list.printListBySector();

    cout << "Data by Iron Level" << endl;
    list.printListByIron();

    cout << "Data by Silicon Level" << endl;
    list.printListBySilicon();

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Averages per sector" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    list.printListByAverages();

};

//Name:   printSectorList()
//Desc:   Exposes the linked list's print functionality for sector number.
//input:  none
//output: Prints all data by sector number.
//return: none
void DataLogger::printSectorList() const {
    list.printBadSectors();
};