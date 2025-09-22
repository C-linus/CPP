#include <iostream>

class Car{
    private:
        float fuel{0.0f};
        float speed{0};
        int passengers{0};
        static int totalCount;
    public:
        Car();
        Car(float amount);
        Car(float amount, int pass);
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void AddPassenger(int count);
        void Dashboard() const;
        ~Car();
};

int Car::totalCount = 0;

Car::Car():Car(0.0f){std::cout<<"Car()"<<std::endl;}

Car::Car(float amount):Car(amount,0){std::cout<<"Car(amount)"<<std::endl;}

Car::Car(float amount, int pass){
    ++totalCount;
    fuel = amount;
    speed = 0;
    passengers = pass;
}

Car::~Car()
{
    --totalCount;
    // Free(Delete) any dynamically allocated inside the  class
}

void Car::FillFuel(float amount )
{
    fuel = amount;
}

void Car::Accelerate()
{
    speed++;
    fuel -= 0.5f;
}

void Car::Brake()
{
    speed = 0;
}

void Car::AddPassenger(int count)
{
    passengers = count;
}

void Car::Dashboard() const
{
    std::cout<<"Fuel:"<<fuel<<std::endl;
    std::cout<<"Speed:"<<speed<<std::endl;
    std::cout<<"Passengers:"<<passengers<<std::endl;
}

int main()
{
    Car car;
    car.Accelerate();
    car.Dashboard();

    return EXIT_SUCCESS;
}