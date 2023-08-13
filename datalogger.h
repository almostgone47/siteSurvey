//
// Created by Jeremiah Barro on 29/6/2023.
//

#ifndef SITE_SURVEY_DATALOGGER_H
#define SITE_SURVEY_DATALOGGER_H
#include "linkedlist.h"

class DataLogger {
public:
    DataLogger();
    void addData(int sector, int iron, int silicon);
    bool containsSector(int sector);
    void removeSector(int sector);
    void printReport() const;
    void printSectorList() const;

private:
    LinkedList list;

};
#endif //SITE_SURVEY_DATALOGGER_H
