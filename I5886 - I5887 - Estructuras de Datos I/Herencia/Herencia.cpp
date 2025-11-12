#include <iostream>
using namespace std;

class Vehicle
{
    private:
        int Year;
        int MaxSpeed;
        string Brand;
        string Model;
        string Color;
        string Plates;
    public:
        Vehicle();
        Vehicle(int year, int maxspeed, string &brand, string &model, string &color, string &plates);
        int getYear();
        int getMaxSpeed();
        string getBrand();
        string getModel();
        string getColor();
        string getPlates();
};

Vehicle::Vehicle(){}
Vehicle::Vehicle(int year, int maxspeed, string &brand, string &model, string &color, string &plates)
{
    this->Year=year;
    this->MaxSpeed=maxspeed;
    this->Brand=brand;
    this->Model=model;
    this->Color=color;
    this->Plates=plates;
}

int Vehicle::getYear()
{
    return Year;
}

int Vehicle::getMaxSpeed()
{
    return MaxSpeed;
}

string Vehicle::getBrand()
{
    return Brand;
}

string Vehicle::getModel()
{
    return Model;
}

string Vehicle::getColor()
{
    return Color;
}

string Vehicle::getPlates()
{
    return Plates;
}

class Car : public Vehicle
{
    private:
        int Doors;
    public:
        Car();
        Car(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors);
        int getDoors();
};

Car::Car(){}
Car::Car(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors):Vehicle(year, maxspeed, brand, model, color, plates)
{
    this->Doors=doors;
}

int Car::getDoors()
{
    return Doors;
}

class Sedan : public Car
{
    private:
        int FuelConsumption;
    public:
        Sedan();
        Sedan(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, int fuelconsumption);
        int getFuelConsumption();
};

Sedan::Sedan(){}
Sedan::Sedan(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, int fuelconsumption):Car(year, maxspeed, brand, model, color, plates, doors)

{
    this->FuelConsumption=fuelconsumption;
}

int Sedan::getFuelConsumption()
{
    return FuelConsumption;
}

class Coupe : public Car
{
    private:
        int Height;
    public:
        Coupe();
        Coupe(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, int height);
        int getHeight();
};

Coupe::Coupe(){}
Coupe::Coupe(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, int height):Car(year, maxspeed, brand, model, color, plates, doors)
{
    this->Height=height;
}

int Coupe::getHeight()
{
    return Height;
}

class SuperCar : public Car
{
    private:
        string DoorsForm;
    public:
        SuperCar();
        SuperCar(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, string &doorsform);
        string getDoorsForm();
};

SuperCar::SuperCar(){}
SuperCar::SuperCar(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int doors, string &doorsform):Car(year, maxspeed, brand, model, color, plates, doors)
{
    this->DoorsForm=doorsform;
}

string SuperCar::getDoorsForm()
{
    return DoorsForm;
}

class Truck : public Vehicle
{
    private:
        int Lenght;
    public:
        Truck();
        Truck(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght);
        int getLenght();
};

Truck::Truck(){}
Truck::Truck(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght):Vehicle(year, maxspeed, brand, model, color, plates)                                                      
{
    this->Lenght=lenght;
}

int Truck::getLenght()
{
    return Lenght;
}

class SUV : public Truck
{
    private:
        int Sits;
    public:
        SUV();
        SUV(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int sits);
        int getSits();
};

SUV::SUV(){}
SUV::SUV(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int sits):Truck(year, maxspeed, brand, model, color, plates, lenght)
{
    this->Sits=sits;
}

int SUV::getSits()
{
    return Sits;
}

class Pickup : public Truck
{
    private:
        int LoadCapacity;
    public:
        Pickup();
        Pickup(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int loadcapacity);
        int getLoadCapacity();
};

Pickup::Pickup(){}
Pickup::Pickup(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int loadcapacity):Truck(year, maxspeed, brand, model, color, plates, lenght)
{
    this->LoadCapacity=loadcapacity;
}

int Pickup::getLoadCapacity()
{
    return LoadCapacity;
}

class MonsterTruck : public Truck
{
    private:
        int EnginePower;
    public:
        MonsterTruck();
        MonsterTruck(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int enginepower);
        int getEnginePower();
};

MonsterTruck::MonsterTruck(){}
MonsterTruck::MonsterTruck(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int lenght, int enginepower):Truck(year, maxspeed, brand, model, color, plates, lenght)
{
    this->EnginePower=enginepower;
}

int MonsterTruck::getEnginePower()
{
    return EnginePower;
}

class Motorcycle : public Vehicle
{
    private: 
        int Displacement;
        int Stroke;
    public:
        Motorcycle();
        Motorcycle(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke);
        int getDisplacement();
        int getStroke();
}; 

Motorcycle::Motorcycle(){}
Motorcycle::Motorcycle(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke):Vehicle(year, maxspeed, brand, model, color, plates)
{
    this->Displacement=displacement;
    this->Stroke=stroke;
}

int Motorcycle::getDisplacement()
{
    return Displacement;
}

int Motorcycle::getStroke()
{
    return Stroke;
}

class Sportbike : public Motorcycle
{
    private:
        int Weight;
    public:
        Sportbike();
        Sportbike(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int weight);
        int getWeight();
};

Sportbike::Sportbike(){}
Sportbike::Sportbike(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int weight):Motorcycle(year, maxspeed, brand, model, color, plates, displacement, stroke)
{
    this->Weight=weight;
}

int Sportbike::getWeight()
{
    return Weight;
}

class Cruiser : public Motorcycle
{
    private:
        int FuelCapacity;
    public:
        Cruiser();
        Cruiser(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int fuelcapacity);
        int getFuelCapacity();
};

Cruiser::Cruiser(){}
Cruiser::Cruiser(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int fuelcapacity):Motorcycle(year, maxspeed, brand, model, color, plates, displacement, stroke)
{
    this->FuelCapacity=fuelcapacity;
}

int Cruiser::getFuelCapacity()
{
    return FuelCapacity;
}

class Cross : public Motorcycle
{
    private:
        int RinSize;
    public:
        Cross();
        Cross(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int rinsize);
        int getRinSize();
};

Cross::Cross(){}
Cross::Cross(int year, int maxspeed, string &brand, string &model, string &color, string &plates, int displacement, int stroke, int rinsize):Motorcycle(year, maxspeed, brand, model, color, plates, displacement, stroke)
{
    this->RinSize=rinsize;
}

int Cross::getRinSize()
{
    return RinSize;
}

int main (void)
{
    int i, menu, ctd, tipo, subtipo, anio, velmax, dato0, dato1, dato2, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0, flag6=0, flag7=0, flag8=0, flag9=0;
    string marca, modelo, color, placas, datos;
    cout<<"Ingrese la cantidad MAXIMA de vehiculos DE CADA TIPO que desea agregar: ";
    cin>>ctd;
    Sedan *sedan = new Sedan[ctd];
    Coupe *coupe = new Coupe[ctd];
    SuperCar *supercar = new SuperCar[ctd];
    SUV *suv = new SUV[ctd];
    Pickup *pickup = new Pickup[ctd];
    MonsterTruck *monstertruck = new MonsterTruck[ctd];
    Sportbike *sportbike = new Sportbike[ctd];
    Cruiser *cruiser = new Cruiser[ctd];
    Cross *cross = new Cross[ctd];
    do{
        system("CLS");
        cout<<"BASE DE DATOS VEHICULAR"<<endl<<endl;
        cout<<"1. Agregar vehiculos"<<endl<<"2. Ver lista de vehiculos"<<endl<<"3. Salir"<<endl<<endl<<"Seleccion: ";
        cin>>menu;
        switch(menu)
        {   
            case 1:
                system("CLS");
                cout<<"SELECCIONE EL TIPO DE VEHICULO"<<endl<<endl;
                cout<<"1. Carro"<<endl<<"2. Camioneta"<<endl<<"3. Motocicleta"<<endl<<endl<<"Seleccion: ";
                cin>>tipo;
                system("CLS");
                switch(tipo)
                {
                    case 1:
                        cout<<"SELECCIONE EL TIPO DE CARRO"<<endl<<endl;
                        cout<<"1. Sedan"<<endl<<"2. Coupe"<<endl<<"3. Super Car"<<endl<<endl<<"Seleccion: ";
                        cin>>subtipo;
                        switch(subtipo)
                        {
                            case 1:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca del Sedan: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo del Sedan: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co del Sedan: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas del Sedan: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color del Sedan: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima del Sedan (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese el numero de puertas del Sedan: ";
                                    cin>>dato0;
                                    cout<<"Ingrese el consumo de combustible del Sedan (km/l): ";
                                    cin>>dato1;
                                    sedan[i]=Sedan(anio,velmax,marca,modelo,color,placas,dato0,dato1);
                                }
                                flag1=1;
                            break;
                            case 2:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca del Coupe: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo del Coupe: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co del Coupe: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas del Coupe: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color del Coupe: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima del Coupe (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese el numero de puertas del Coupe: ";
                                    cin>>dato0;
                                    cout<<"Ingrese la capacidad del altura del Coupe (cm): ";
                                    cin>>dato1;
                                    coupe[i]=Coupe(anio,velmax,marca,modelo,color,placas,dato0,dato1);
                                }
                                flag2=1;
                            break;
                            case 3:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca del Super Car: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo del Super Car: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co del Super Car: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas del Super Car: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color del Super Car: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima del Super Car (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese el numero de puertas del Super Car: ";
                                    cin>>dato0;
                                    cout<<"Ingrese la forma de las puertas del Super Car (normal, gaviota, tijera, mariposa, cupula, etc.): ";
                                    cin>>datos;
                                    supercar[i]=SuperCar(anio,velmax,marca,modelo,color,placas,dato0,datos);
                                }
                                flag3=1;
                            break;
                        }
                    break;
                    case 2:
                        cout<<"SELECCIONE EL TIPO DE CAMIONETA"<<endl<<endl;
                        cout<<"1. SUV"<<endl<<"2. Pickup"<<endl<<"3. Monster Truck"<<endl<<endl<<"Seleccion: ";
                        cin>>subtipo;
                        switch(subtipo)
                        {
                            case 1:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca del SUV: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo del SUV: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co del SUV: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas del SUV: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color del SUV: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima del SUV (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la longitd del SUV (cm): ";
                                    cin>>dato0;
                                    cout<<"Ingrese la cantidad de asientos del SUV: ";
                                    cin>>dato1;
                                    suv[i]=SUV(anio,velmax,marca,modelo,color,placas,dato0,dato1);
                                }
                                flag4=1;
                            break;
                            case 2:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca de la Pickup: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo de la Pickup: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co de la Pickup: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas de la Pickup: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color de la Pickup: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima de la Pickup (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la longitud de la Pickup (cm): ";
                                    cin>>dato0;
                                    cout<<"Ingrese la capacidad de carga de la Pickup (kg): ";
                                    cin>>dato1;
                                    pickup[i]=Pickup(anio,velmax,marca,modelo,color,placas,dato0,dato1);
                                }
                                flag5=1;
                            break;
                            case 3:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca del Monster Truck: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo del Monster Truck: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co del Monster Truck: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas del Monster Truck: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color del Monster Truck: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima del Monster Truck (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la longitud del Monster Truck (cm): ";
                                    cin>>dato0;
                                    cout<<"Ingrese la potencia del Monster Truck (HP): ";
                                    cin>>dato1;
                                    monstertruck[i]=MonsterTruck(anio,velmax,marca,modelo,color,placas,dato0,dato1);
                                }
                                flag6=1;
                            break;
                        }
                    break;
                    case 3:
                        cout<<"SELECCIONE EL TIPO DE MOTOCICLETA"<<endl<<endl;
                        cout<<"1. Sportbike"<<endl<<"2. Cruiser"<<endl<<"3. Cross"<<endl<<endl<<"Seleccion: ";
                        cin>>subtipo;
                        switch(subtipo)
                        {
                            case 1:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca de la Sportbike: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo de la Sportbike: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co de la Sportbike: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas de la Sportbike: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color de la Sportbike: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima de la Sportbike (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la cilindrada de la Sportbike (cc): ";
                                    cin>>dato0;
                                    cout<<"Ingrese el numero de tiempos de la Sportbike: ";
                                    cin>>dato1;
                                    cout<<"Ingrese el peso de la Sportbike (kg): ";
                                    cin>>dato2;
                                    sportbike[i]=Sportbike(anio,velmax,marca,modelo,color,placas,dato0,dato1,dato2);
                                }
                                flag7=1;
                            break;

                            case 2:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca de la Cruiser: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo de la Cruiser: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co de la Cruiser: ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas de la Cruiser: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color de la Cruiser: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima de la Cruiser (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la cilindrada de la Cruiser (cc): ";
                                    cin>>dato0;
                                    cout<<"Ingrese el numero de tiempos de la Cruiser: ";
                                    cin>>dato1;
                                    cout<<"Ingrese la capacidad de combustible de la Cruiser (lts): ";
                                    cin>>dato2;
                                    cruiser[i]=Cruiser(anio,velmax,marca,modelo,color,placas,dato0,dato1,dato2);
                                }
                                flag8=1;
                            break;

                            case 3:
                                for(i=0;i<ctd;i++)
                                {
                                    system("CLS");
                                    cout<<"Ingrese la marca de la Cross: ";
                                    cin>>marca;
                                    cout<<"Ingrese el modelo de la Cross: ";
                                    cin>>modelo;
                                    printf("Ingrese el A%co de la Cross. ",164);
                                    cin>>anio;
                                    cout<<"Ingrese las placas de la Cross: ";
                                    cin>>placas;
                                    cout<<"Ingrese el color de la Cross: ";
                                    cin>>color;
                                    cout<<"Ingrese la velocidad maxima de la Cross (km/h): ";
                                    cin>>velmax;
                                    cout<<"Ingrese la cilindrada de la Cross (cc): ";
                                    cin>>dato0;
                                    cout<<"Ingrese el numero de tiempos de la Cross: ";
                                    cin>>dato1;
                                    cout<<"Ingrese el tamaño del rin de la Cross (pulgadas): ";
                                    cin>>dato2;
                                    cross[i]=Cross(anio,velmax,marca,modelo,color,placas,dato0,dato1,dato2);
                                }
                                flag9=1;
                            break;
                        }
                    break;
                }
            break;

            case 2:
                system("CLS");
                cout<<"VER LISTA DE VEHICULOS"<<endl<<endl;
                if(flag1==1||flag2==1||flag3==1)
                    cout<<"Carros"<<endl<<endl;
                if(flag1==1)
                {
                    cout<<"Sedan"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<sedan[i].getBrand()<<endl;
                        cout<<"Modelo:"<<sedan[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<sedan[i].getYear()<<endl;
                        cout<<"Placas: "<<sedan[i].getPlates()<<endl;
                        cout<<"Color: "<<sedan[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<sedan[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Numero de puertas: "<<sedan[i].getDoors()<<endl;
                        cout<<"Consumo de Combustible: "<<sedan[i].getFuelConsumption()<<"Km/l"<<endl<<endl;
                    }
                }
                if(flag2==1)
                {
                    cout<<endl<<"Coupe"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<coupe[i].getBrand()<<endl;
                        cout<<"Modelo:"<<coupe[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<coupe[i].getYear()<<endl;
                        cout<<"Placas: "<<coupe[i].getPlates()<<endl;
                        cout<<"Color: "<<coupe[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<coupe[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Numero de puertas: "<<coupe[i].getDoors()<<endl;
                        cout<<"Altura: "<<coupe[i].getHeight()<<"cm"<<endl<<endl;
                    }
                }
                if(flag3==1)
                {
                    cout<<endl<<"Super Car"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<supercar[i].getBrand()<<endl;
                        cout<<"Modelo:"<<supercar[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<supercar[i].getYear()<<endl;
                        cout<<"Placas: "<<supercar[i].getPlates()<<endl;
                        cout<<"Color: "<<supercar[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<supercar[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Numero de puertas: "<<supercar[i].getDoors()<<endl;
                        cout<<"Forma de las Puertas: "<<supercar[i].getDoorsForm()<<endl;
                    }
                }
                if(flag4==1||flag5==1||flag6==1)
                    cout<<endl<<"Camionetas"<<endl<<endl;
                if(flag4==1)
                {
                    cout<<"SUV"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<suv[i].getBrand()<<endl;
                        cout<<"Modelo:"<<suv[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<suv[i].getYear()<<endl;
                        cout<<"Placas: "<<suv[i].getPlates()<<endl;
                        cout<<"Color: "<<suv[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<suv[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Longitud: "<<suv[i].getLenght()<<"cm"<<endl;
                        cout<<"Numero de asientos: "<<suv[i].getSits()<<endl;
                    }
                }
                if(flag5==1)
                {
                    cout<<endl<<"Pickup"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<pickup[i].getBrand()<<endl;
                        cout<<"Modelo:"<<pickup[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<pickup[i].getYear()<<endl;
                        cout<<"Placas: "<<pickup[i].getPlates()<<endl;
                        cout<<"Color: "<<pickup[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<pickup[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Longitud: "<<pickup[i].getLenght()<<"cm"<<endl;
                        cout<<"Capacidad de carga: "<<pickup[i].getLoadCapacity()<<endl;
                    }
                }
                if(flag6==1)
                {
                    cout<<endl<<"Monster Truck"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<monstertruck[i].getBrand()<<endl;
                        cout<<"Modelo:"<<monstertruck[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<monstertruck[i].getYear()<<endl;
                        cout<<"Placas: "<<monstertruck[i].getPlates()<<endl;
                        cout<<"Color: "<<monstertruck[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<monstertruck[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Longitud: "<<monstertruck[i].getLenght()<<"cm"<<endl;
                        cout<<"Potencia: "<<monstertruck[i].getEnginePower()<<"HP"<<endl;
                    }
                }
                if(flag7==1||flag8==1||flag9==1)
                    cout<<endl<<"Motocicletas"<<endl<<endl;
                if(flag7==1)
                {
                    cout<<"Sportbike"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<sportbike[i].getBrand()<<endl;
                        cout<<"Modelo:"<<sportbike[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<sportbike[i].getYear()<<endl;
                        cout<<"Placas: "<<sportbike[i].getPlates()<<endl;
                        cout<<"Color: "<<sportbike[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<sportbike[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Cilindrada: "<<sportbike[i].getDisplacement()<<"cc"<<endl;
                        cout<<"Tiempos: "<<sportbike[i].getStroke()<<endl;
                        cout<<"Peso:"<<sportbike[i].getWeight()<<"kg"<<endl;
                    }
                }
                if(flag8==1)
                {
                    cout<<endl<<"Cruiser"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<cruiser[i].getBrand()<<endl;
                        cout<<"Modelo:"<<cruiser[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<cruiser[i].getYear()<<endl;
                        cout<<"Placas: "<<cruiser[i].getPlates()<<endl;
                        cout<<"Color: "<<cruiser[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<cruiser[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Cilindrada: "<<cruiser[i].getDisplacement()<<"cc"<<endl;
                        cout<<"Tiempos: "<<cruiser[i].getStroke()<<endl;
                        cout<<"Capacidad de combustible: "<<cruiser[i].getFuelCapacity()<<"lts"<<endl;
                    }
                }
                if(flag9==1)
                {
                    cout<<endl<<"Cross"<<endl<<endl;
                    for(i=0;i<ctd;i++)
                    {
                        cout<<"Marca: "<<cross[i].getBrand()<<endl;
                        cout<<"Modelo:"<<cross[i].getModel()<<endl;
                        printf("A%co: ",164);
                        cout<<cross[i].getYear()<<endl;
                        cout<<"Placas: "<<cross[i].getPlates()<<endl;
                        cout<<"Color: "<<cross[i].getColor()<<endl;
                        cout<<"Velocidad Maxima: "<<cross[i].getMaxSpeed()<<"Km/h"<<endl;
                        cout<<"Cilindrada: "<<cross[i].getDisplacement()<<"cc"<<endl;
                        cout<<"Tiempos: "<<cross[i].getStroke()<<endl;
                        printf("Tama%co del Rin",164);
                        cout<<cross[i].getRinSize()<<"''"<<endl;
                    }
                }
                system("PAUSE");
            break;

            case 3:
                cout<<"Gracias por usar el programa"<<endl;
            break;
        }
    }while(menu!=3);
    system("PAUSE");
}