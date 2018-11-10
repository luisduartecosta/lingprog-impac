#include <iostream>
#include <string>

using namespace std;

class Plant {
    public:
        Plant();
        ~Plant();

        void addPlant(string, string, string);
        void deletePlant(string);
        void showPlants();
        void showPlants(string);

        void setPlantName();
        string getPlantName();
        void setPlantType();
        string getPlantType();
        void setPlantProtocol();
        string getPlantProtocol();
        
    private:
        string name;
        string type;
        string protocol;
};