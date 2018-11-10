#include <iostream>
#include <string>

using namespace std;

class Plant {
    public:
        Plant(string, string, string);
        void setPlantName();
        string getPlantName();
        void setPlantType();
        string getPlantType();
        void setPlantProtocol();
        string getPlantProtocol();
        void showPlant();
        
    private:
        string name;
        string type;
        string protocol;
};