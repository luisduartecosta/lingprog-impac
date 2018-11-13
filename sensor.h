#include <iostream>
#include <string>

using namespace std;

class Sensor {
    public:
        Sensor();
        Sensor(string name, string time, string status, string level, string obs);

        void setSensorTime(string);
        string getSensorTime();
        void setSensorName(string);
        string getSensorName();
        void setSensorStatus(string);
        string getSensorStatus();
        void setSensorLevel(string);
        string getSensorLevel();
        void setSensorObs(string);
        string getSensorObs();

        void showData();

    private:
        string time;
        string name;
        string status;
        string level;
        string obs;
};