//
// Created by Jeremiah Barro on 29/6/2023.
//
#include <iostream>
#include "linkedlist.h"

//Name:   LinkedList()
//Desc:   Constructor for LinkedList class.
//input:  none.
//output: none
//return: none
LinkedList::LinkedList() {
};

//Name:   ~LinkedList()
//Desc:   Destructor for LinkedList class. The delete keyword deallocates memory and the pointers are
//        set to null so as not to leave dangling pointers.
//input:  none.
//output: none
//return: none
LinkedList::~LinkedList() {
    Node* curr = headBySector;
    Node* nextSector = nullptr;

    while (curr) {
        nextSector = curr->nextBySector;

        delete curr;

        curr = nextSector;
    }

    headBySector = nullptr;
    headByIron = nullptr;
    headBySilicon = nullptr;
    count = 0;
};

//Name:   LinkedList()
//Desc:   Copy constructor for LinkedList class.
//input:  none.
//output: none
//return: none
LinkedList::LinkedList(const LinkedList &list) {
    Node *curr = list.headBySector;

    while(curr) {
        SensorData newData = curr->data;
        this->addSensorData(newData);
        curr = curr->nextBySector;
    }
};

//Name:   =
//Desc:   Assignment operator makes a deep copy of passed in linked list.
//input:  Linked list to be copied.
//output: none
//return: The copy of the linked list.
const LinkedList & LinkedList::operator= (const LinkedList &list) {
    if (this != &list) {
        Node *curr = list.headBySector;

        while(curr) {
            SensorData newData = curr->data;
            this->addSensorData(newData);
            curr = curr->nextBySector;
        }
    }

    return *this;
};

//Name:   addSensorData()
//Desc:   Creates a new node and points all the new node's pointers so they are in order by each
//        respective pointer property.
//input:  none
//output: none
//return: none
void LinkedList::addSensorData(const SensorData &sensorData) {
    Node *curr = nullptr, *prev = nullptr;
    Node *newNode = new Node(sensorData);

    if (!headBySector) {
        headBySector = newNode;
    }
    else
    {
        curr = headBySector;
        while (curr && curr->data.getSectorNumber() < sensorData.getSectorNumber()) {
            prev = curr;
            curr = curr->nextBySector;
        }

        if (prev) {
            prev->nextBySector = newNode;
        }
        else {
            headBySector = newNode;
        }

        newNode->nextBySector = curr;
    }

    if (!headByIron) {
        headByIron = newNode;
    }
    else
    {
        curr = headByIron;
        prev = nullptr;
        while (curr && curr->data.getIronLevel() < sensorData.getIronLevel()) {
            prev = curr;
            curr = curr->nextByIron;
        }

        if (prev) {
            prev->nextByIron = newNode;
        }
        else {
            headByIron = newNode;
        }

        newNode->nextByIron = curr;
    }

    if (!headBySilicon) {
        headBySilicon = newNode;
    }
    else
    {
        curr = headBySilicon;
        prev = nullptr;
        while (curr && curr->data.getSiliconLevel() < sensorData.getSiliconLevel()) {
            prev = curr;
            curr = curr->nextBySilicon;
        }

        if (prev) {
            prev->nextBySilicon = newNode;
        }
        else {
            headBySilicon = newNode;
        }
        newNode->nextBySilicon = curr;
    }

    count++;
};

//Name:   printListByAverages()
//Desc:   Loops through each of the nodes by the Sector pointer of the node and calls the printData
//        method of the SensorData class.
//input:  none
//output: Prints data by sector number.
//return: none
void LinkedList::printListByAverages() const {
    Node *curr = headBySector;
    int i = 1;

    while(curr)
    {
        int currentSector = curr->data.getSectorNumber();

        while(currentSector != i && i <= 500) {
            cout << "Sector: #" << i << "  -- no data -- " << endl;
            i++;
        }

        int sectorCount = 1;
        int ironCount = curr->data.getIronLevel();
        int siliconCount = curr->data.getSiliconLevel();
        while (curr->nextBySector != nullptr && currentSector == curr->nextBySector->data.getSectorNumber()) {
            sectorCount++;
            curr = curr->nextBySector;
            ironCount += curr->data.getIronLevel();
            siliconCount += curr->data.getSiliconLevel();
        }

        cout << "Sector: #" << i << " " << ironCount/sectorCount <<" grams iron, "<< siliconCount/sectorCount <<" milligrams silicon" << endl;

        curr = curr->nextBySector;
        i++;
    }
};

//Name:   printListBySector()
//Desc:   Loops through each of the nodes by the Sector pointer of the node and calls the printData
//        method of the SensorData class.
//input:  none
//output: Prints data by sector number.
//return: none
void LinkedList::printListBySector() const {
    Node *curr = headBySector;

    while(curr)
    {
        curr->data.printData();
        curr = curr->nextBySector;
    }
};

//Name:   printListByIron()
//Desc:   Loops through each of the nodes by the iron pointer of the node and calls the printData
//        method of the SensorData class.
//input:  none.
//output: Prints data by iron levels.
//return: none
void LinkedList::printListByIron() const {
    Node *curr = headByIron;

    while(curr)
    {
        curr->data.printData();
        curr = curr->nextByIron;
    }
};

//Name:   printListBySilicon()
//Desc:   Loops through each of the nodes by the Silicon pointer of the node and calls the printData
//        method of the SensorData class.
//input:  none
//output: Prints data by silicon levels.
//return: none
void LinkedList::printListBySilicon() const {
    Node *curr = headBySilicon;

    while(curr)
    {
        curr->data.printData();
        curr = curr->nextBySilicon;
    }
};

//Name:   containsSector()
//Desc:   Loops through each of the list's nodes and if the sector number queried for is found returns true or false.
//input:  An integer representing the sector number being searched for.
//output: none
//return: True if sector found and false if not.
bool LinkedList::containsSector(int sector) const {
    Node *curr = headBySector;
    bool found = false;

    while(curr)
    {
        if (curr->data.getSectorNumber() == sector) {
            found = true;
        }
        curr = curr->nextBySector;
    }

    return found;
};

//Name:   removeSector()
//Desc:   Loops through each of the nodes by the Sector pointer of the node and removes sector based on input.
//input:  An integer representing the sector to be removed.
//output: none
//return: none
void LinkedList::removeSector(int sectorNum) {
    Node *curr = headBySector, *prev = nullptr, *next = nullptr;

    if (headBySector) {
        while (curr != nullptr) {
            int currItemSectorNum = curr->data.getSectorNumber();
            if (currItemSectorNum == sectorNum) {
                if (prev) {
                    prev->nextBySector = curr->nextBySector;
                } else {
                    headBySector = curr->nextBySector;
                }

                if (headByIron == curr) {
                    headByIron = curr->nextByIron;
                } else {
                    Node *ironCurr = headByIron;
                    Node *ironPrev = nullptr;
                    while (ironCurr != nullptr && ironCurr != curr) {
                        ironPrev = ironCurr;
                        ironCurr = ironCurr->nextByIron;
                    }
                    if (ironCurr == curr) {
                        ironPrev->nextByIron = curr->nextByIron;
                    }
                }

                if (headBySilicon == curr) {
                    headBySilicon = curr->nextBySilicon;
                } else {
                    Node *siliconCurr = headBySilicon;
                    Node *siliconPrev = nullptr;
                    while (siliconCurr != nullptr && siliconCurr != curr) {
                        siliconPrev = siliconCurr;
                        siliconCurr = siliconCurr->nextBySilicon;
                    }
                    if (siliconCurr == curr) {
                        siliconPrev->nextBySilicon = curr->nextBySilicon;
                    }
                }

                next = curr->nextBySector;
                delete curr;
                curr = next;
                count--;
            } else {
                prev = curr;
                curr = curr->nextBySector;
            }
        }
    }
}

//Name:   printBadSectors()
//Desc:   Loops through each of the nodes by the Sector and prints just the sector number.
//input:  none
//output: The integer representing the sector with bad data.
//return: none
void LinkedList::printBadSectors() const {
    Node *curr = headBySector;

    while(curr->nextBySector)
    {
        cout << curr->data.getSectorNumber() << ", ";
        curr  = curr->nextBySector;
    }
    cout << curr->data.getSectorNumber() << endl;
}