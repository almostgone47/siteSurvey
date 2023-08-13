//
// Created by Jeremiah Barro on 29/6/2023.
//

#ifndef SITE_SURVEY_SENSORDATA_H
#define SITE_SURVEY_SENSORDATA_H

using namespace std;

class SensorData {
    private:
        int sector;
        int iron;
        int silicon;
    public:
        SensorData(int sector, int iron, int silicon);
        int getSectorNumber() const;
        int getIronLevel() const;
        int getSiliconLevel() const;
        void printData();
};
#endif //SITE_SURVEY_SENSORDATA_H
