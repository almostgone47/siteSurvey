//
// Created by Jeremiah Barro on 29/6/2023.
//
#include <iostream>
#include "sensordata.h"

//Name:   SensorData()
//Desc:   Constructor for SensorData class.
//input:  none.
//output: none
//return: none
SensorData::SensorData(int sector, int iron, int silicon) {
    this->sector = sector;
    this->iron = iron;
    this->silicon = silicon;
};

//Name:   getSectorNumber()
//Desc:   Getter for sector.
//input:  none.
//output: none
//return: An integer representing the sector number.
int SensorData::getSectorNumber() const {
    return sector;
};

//Name:   getIronLevel()
//Desc:   Getter for iron levels.
//input:  none.
//output: none
//return: An integer representing the iron level.
int SensorData::getIronLevel() const {
    return iron;
};

//Name:   getSiliconLevel()
//Desc:   Getter for silicon levels.
//input:  none.
//output: none
//return: An integer representing the silicon level.
int SensorData::getSiliconLevel() const {
    return silicon;
};

//Name:   printData()
//Desc:   Prints the data for the SensorData.
//input:  none
//output: The formatted sector number, iron level and silicon level.
//return: none
void SensorData::printData() {
    cout << "Sector: #" << sector << " " << iron << " grams iron, "<< silicon << " milligrams silicon" << endl;
}