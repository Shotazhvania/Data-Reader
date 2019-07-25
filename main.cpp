#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Country;
class Town;
class Appartment;
class Building;
class Human;
class Animal;

class Animal{
    string Name;
public:
    Animal(){}
    Animal(const string& name){
        Name = name;
    }
    string getName(){return this->Name;}
    void setName(const string& name){ this->Name = name;}

    friend istream& operator >> (istream&in,Animal& animal){
        in >> animal.Name;
        return in;
    }
    friend ostream& operator << (ostream&out,const Animal& animal){
        out << "\"AnimalName\": \"" << animal.Name << "\"" << endl;
        return out;
    }
};
class Human{
    string Name;
    string BirthDate;
public:
    Human(){}
    Human(const string& name, const string& birthDate){
        Name = name;
        BirthDate = birthDate;
    }
    string getName() {return this->Name;}
    string getBirthDate() {return this->BirthDate;}
    void setName(const string& name) { this->Name = name;}
    void setBirthDate(const string& birthDate) { this->BirthDate = birthDate;}

    friend istream& operator >> (istream&in,Human& human){
        in >> human.Name;
        in >> human.BirthDate;
        return in;
    }
    friend ostream& operator << (ostream&out,const Human& human){        
        out << "\"HumanName\": \"" << human.Name << "\"," << endl;
        out << "\"HumanBirthDate\": \"" << human.BirthDate << "\"" << endl;
        return out;
    }

};

class Appartment{
    long long Index;
    double Area;
    vector<Human> Humans;
    vector<Animal> Animals;
public:
    Appartment(){}
    Appartment(const long long& index,const double& area,const vector<Human>& humans,const vector<Animal>& animals){
        Index = index;
        Area = area;
        Humans = humans;
        Animals = animals;
    }
    long long getIndex() { return this->Index; }
    double getArea() { return this->Area; }
    vector<Human> getHumans() { return this->Humans; }
    vector<Animal> getAnimals() { return this->Animals; }
    void setIndex(const long long& index) { this->Index = index; }
    void setArea(const double& area ) {this->Area = area;}
    void setHumans(const vector<Human>& humans ) {this->Humans = humans;}
    void setAnimals(const vector<Animal>& animals ) {this->Animals = animals;}

    friend istream& operator >> (istream&in,Appartment& appartment){
        int numOfHumans,numOfAnimals;
        in >> appartment.Index;
        in >> appartment.Area;

        in >> numOfHumans;
        appartment.Humans.resize(numOfHumans);
        for(size_t i = 0;i<numOfHumans;i++){
            in >> appartment.Humans[i];
        }

        in >> numOfAnimals;
        appartment.Animals.resize(numOfAnimals);
        for(size_t i = 0;i<numOfAnimals;i++){
            in >> appartment.Animals[i];
        }
        return in;
    }
    friend ostream& operator << (ostream&out,const Appartment& appartment){
        out << "\"AppartmentIndex\": " << appartment.Index << "," << endl;
        out << "\"AppartmentHumans\": [" << endl;
        for(size_t i=0;i<appartment.Humans.size()-1;i++){
            out << "{" << appartment.Humans[i] << "}," << endl;
        }
        if(appartment.Humans.size() != 0){
            out << "{" << appartment.Humans[appartment.Humans.size()-1] << "}" << endl;
        }
        out << "]," << endl;
        out << "\"AppartmentAnimals\": [" << endl;
        for(size_t i=0;i<appartment.Animals.size()-1;i++){
            out << "{" << appartment.Animals[i] << "}," << endl;
        }
        if(appartment.Animals.size()!=0){
            out << "{" << appartment.Animals[appartment.Animals.size() -1 ] << "}" << endl;
        }
        out << ']' << endl;
        return out;
    }
};

class Building{
    string Address;
    string BuildDate;
    vector<Appartment> Appartments;
public:
    Building(){}
    Building(const string& address,const string& buildDate,const vector<Appartment>& appartments){
        Address = address;
        BuildDate = buildDate;
        Appartments = appartments;
    }
    string getAddress() { return this->Address; }
    string getBuildDate() { return this->BuildDate; }
    vector<Appartment> getAppartments() { return this->Appartments; }
    void setAddress(const string& address) { this->Address = address; }
    void setBildDate(const string& buildDate ) {this->BuildDate = buildDate;}
    void setAppartments(const vector<Appartment>& appartments ) {this->Appartments = appartments;}
    
    friend istream& operator >> (istream&in,Building& building){
        int numOfAppartments;
        in >> building.Address;
        in >> building.BuildDate;

        in >> numOfAppartments;
        building.Appartments.resize(numOfAppartments);
        for(size_t i = 0;i<numOfAppartments;i++){
            in >> building.Appartments[i];
        }
        return in;
    }
    friend ostream& operator << (ostream&out,const Building& building){
        out << "\"BuildingAddress\": \"" << building.Address << "\"," << endl;
        out << "\"BuildingBuildDate\": \"" << building.BuildDate << "\"," << endl;
        out << "\"BuildingAppartments\": [" << endl;
        for(size_t i=0;i<building.Appartments.size()-1;i++){
            out << "{" << building.Appartments[i] << "}," << endl;
        }
        if(building.Appartments.size() != 0){
            out << "{" << building.Appartments[building.Appartments.size() -1] << "}" << endl;
        }
        out << ']' << endl;
        return out;
    }
};


class Town{
    string Name;
    long long Area;
    vector<Building> Buildings;
public:
    Town(){}
    Town(const string& name,const long long& area,const vector<Building>& buildings){
        Name = name;
        Area = area;
        Buildings = buildings;
    }
    string getName() { return this->Name; }
    long long getArea() { return this->Area; }
    vector<Building> getBuildings() { return this->Buildings; }
    void setName(const string& name) { this->Name = name; }
    void setArea(const long long& area ) {this->Area = area;}
    void setBuildings(const vector<Building>& buildings ) {this->Buildings = buildings;}

    friend istream& operator >> (istream&in,Town & town){
        int numOfBuildings;
        in >> town.Name;
        in >> town.Area;

        in >> numOfBuildings;
        town.Buildings.resize(numOfBuildings);
        for(size_t i = 0;i<numOfBuildings;i++){
            in >> town.Buildings[i];
        }
        return in;
    }
    friend ostream & operator << (ostream&out,const Town& town){
        out << "\"TownName\": \"" << town.Name << "\"," << endl;
        out << "\"TownArea\": " << town.Area << ',' << endl;
        out << "\"TownBuildings\": [" << endl;
        for(size_t i=0;i<town.Buildings.size()-1;i++){
            out << "{" << town.Buildings[i] << "}," << endl;
        }
        if(town.Buildings.size() !=0 ){
            out << "{" << town.Buildings[town.Buildings.size() -1] << "}" << endl;
        }
        out << ']' << endl;
        return out;
    }
};


class Country{
    string Name;
    long long Area;
    vector<Town> Towns;
    vector<Animal> Animals;
public:
    Country(){
    }
    Country(const string& name,const long long& area, const vector<Town>& town,const vector<Animal>& animal){
        Name = name;
        Area = area;
        Towns = town;
        Animals = animal;
    }
    string getName() { return this->Name; }
    long long getArea() { return this->Area; }
    vector<Town> getTowns() { return this->Towns; }
    vector<Animal> getAnimals() { return this->Animals; }
    void setName(const string& name) { this->Name = name; }
    void setArea(const long long& area ) {this->Area = area;}
    void setTowns(const vector<Town>& towns ) {this->Towns = towns;}
    void setAnimals(const vector<Animal>& animals ) {this->Animals = animals;}
    
    friend istream& operator >> (istream&in,Country & country){
        int numOfTowns,numOfAnimals;
        in >> country.Name;
        in >> country.Area;

        in >> numOfTowns;
        country.Towns.resize(numOfTowns);
        for(size_t i = 0;i<numOfTowns;i++){
            in >> country.Towns[i];
        }
        in >> numOfAnimals;
        country.Animals.resize(numOfAnimals);
        for(size_t i = 0;i<numOfAnimals;i++){
            in >> country.Animals[i];
        }
        return in;
    }
    friend ostream& operator << (ostream&out,const Country& country){
        out << "{\"CountryName\": \"" << country.Name << "\"," << endl;
        out << "\"CountryArea\": " << country.Area << ',' << endl;
        out << "\"CountryTowns\": [" << endl;
        for(size_t i = 0;i<country.Towns.size()-1;i++){
            out << "{" <<country.Towns[i] << "}," << endl;
        }
        if(country.Towns.size() != 0){
            out << "{" <<country.Towns[country.Towns.size() -1] << "}" << endl;
        }
        out << "]," << endl;
        out << "\"CountryAnimals\": [" << endl;
        for(size_t i = 0;i<country.Animals.size()-1;i++){
            out << "{" <<country.Animals[i] << "}," << endl;
        }
        if(country.Animals.size() != 0){
            out << "{" <<country.Animals[country.Animals.size()-1] << "}" << endl;
        }
        out << "]}" << endl;
        
        return out;        
    }
};





int main(){
    Country c1;
    cin >> c1;
    cout << c1 << endl;

}
