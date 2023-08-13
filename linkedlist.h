//
// Created by Jeremiah Barro on 29/6/2023.
//

#ifndef SITE_SURVEY_LINKEDLIST_H
#define SITE_SURVEY_LINKEDLIST_H
#include "sensordata.h"

using namespace std;

class LinkedList {
private:
    struct Node {
        SensorData data = SensorData(0, 0, 0);
        Node *nextBySector;
        Node *nextByIron;
        Node *nextBySilicon;

        Node(SensorData sensorData) {
            data = sensorData;
            nextBySector = nullptr;
            nextByIron = nullptr;
            nextBySilicon = nullptr;
        }
    };

    Node *headBySector = nullptr;
    Node *headByIron = nullptr;
    Node *headBySilicon = nullptr;
    int count = 0;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &list);
    const LinkedList & operator= (const LinkedList &list);
    void addSensorData(const SensorData &sensorData);
    void printListBySector() const;
    void printListByIron() const;
    void printListBySilicon() const;
    void printListByAverages() const;
    bool containsSector(int sector) const;
    void removeSector(int sector);
    void printBadSectors() const;
};

#endif //SITE_SURVEY_LINKEDLIST_H
