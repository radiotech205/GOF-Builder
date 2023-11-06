#include <iostream>
#include <string>
using namespace std;

class House
{
private:
    string aboutHouse;
public:
    House() {this->aboutHouse = "";}
    string AboutHouse() const {return this->aboutHouse;}
    void AppendFeature(string str) {this->aboutHouse += str;}
};
/*****************************/
class Builder
{
public:
    virtual void CreateHouse() = 0;
    virtual void CreateGarage() = 0;
    virtual void CreateGarden() = 0;
    virtual House* GetHouse() = 0;
};

class CityHouseBuilder : public Builder
{
private:
    House* house;
public:
    CityHouseBuilder() {this->house = new House();}
    ~CityHouseBuilder() {delete house;}
    void CreateHouse() {this->house->AppendFeature("City house ");}
    void CreateGarage() {this->house->AppendFeature("with underground parking ");}
    void CreateGarden() {this->house->AppendFeature("with park ");}
    House* GetHouse() {return this->house;}
};

class CottegeBuilder : public Builder
{
private:
    House* house;
public:
    CottegeBuilder() {this->house = new House();}
    ~CottegeBuilder() {delete house;}
    void CreateHouse() {this->house->AppendFeature("Cottege ");}
    void CreateGarage() {this->house->AppendFeature("with garage ");}
    void CreateGarden() {this->house->AppendFeature("with farm ");}
    House* GetHouse() {return this->house;}
};
/******************************/
class Director
{
private:
    Builder* builder;
public:
    Director(Builder* b) : builder(b) {}
    void SetBuilder(Builder* b) {this->builder = b;}
    House* BuildeMinimalFeatureHouse()
    {
        builder->CreateHouse();
        return builder->GetHouse();
    }
    House* BuildFullFeatureHouse()
    {
        builder->CreateHouse();
        builder->CreateGarage();
        builder->CreateGarden();
        return builder->GetHouse();
    }
};

/******************************/
int main()
{
    Builder* builder = new CityHouseBuilder();
    Director director(builder);
    House* house1 = director.BuildeMinimalFeatureHouse();
    cout << house1->AboutHouse() << endl;

    director.SetBuilder(new CottegeBuilder());
    House* house2 = director.BuildFullFeatureHouse();
    cout << house2->AboutHouse() << endl;

    cout << "Hello World!" << endl;
    return 0;
}
