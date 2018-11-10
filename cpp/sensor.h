#include <iostream>
#include <string>

using namespace std;

class Sensor {
    public:
        Sensor(string name, string time, string status, string level, string obs);

        void setTime(string);
        string getTime();
        void setName(string);
        string getName();
        void setStatus(string);
        string getStatus();
        void setLevel(string);
        string getLevel();
        void setObs(string);
        string getObs();

        void showData();

    private:
        string time;
        string name;
        string status;
        string level;
        string obs;
};