/*Завдання 1*/
/*#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string brand;
    int cylinders;
    int power;

public:
    // Конструктор за замовчуванням
    Car() : brand("Unknown"), cylinders(0), power(0) {}

    // Конструктор з параметрами
    Car(string brand, int cylinders, int power) : brand(brand), cylinders(cylinders), power(power) {}

    // Деструктор
    ~Car() {}

    // Функція друку
    void print() {
        cout << "Brand: " << brand << ", Cylinders: " << cylinders << ", Power: " << power << "hp" << endl;
    }

    // Функція перепризначення марки
    void setBrand(string newBrand) {
        brand = newBrand;
    }
};

class Truck : public Car {
private:
    double payloadCapacity;

public:
    // Конструктор за замовчуванням
    Truck() : Car(), payloadCapacity(0) {}

    // Конструктор з параметрами
    Truck(string brand, int cylinders, int power, double payload) : Car(brand, cylinders, power), payloadCapacity(payload) {}

    // Деструктор
    ~Truck() {}

    // Функція друку
    void print() {
        Car::print();
        cout << "Payload Capacity: " << payloadCapacity << " tons" << endl;
    }

    // Функція перепризначення вантажопідйомності
    void setPayloadCapacity(double newPayload) {
        payloadCapacity = newPayload;
    }
};

int main() {
    Car car1("Toyota", 4, 150);
    car1.print();

    Truck truck1("Volvo", 6, 300, 5.5);
    truck1.print();

    // Перевірка функцій перепризначення
    car1.setBrand("Honda");
    truck1.setPayloadCapacity(6.5);

    cout << "After modification:" << endl;
    car1.print();
    truck1.print();

    return 0;
}*/
/*Завдання 2*/
/*#include <iostream>
#include <string>

class Engine {
private:
    int power;

public:
    Engine(int p) : power(p) {}

    // Метод доступу до потужності
    int getPower() const {
        return power;
    }
};

class Car {
private:
    Engine engine;
    std::string brand;
    double price;

public:
    Car(int power, const std::string& b, double p) : engine(power), brand(b), price(p) {}

    // Деструктор
    ~Car() {
        std::cout << "Car object destroyed" << std::endl;
    }

    // Функції доступу до полів класу
    const std::string& getBrand() const {
        return brand;
    }

    double getPrice() const {
        return price;
    }
};

class Truck : public Car {
private:
    double cargoCapacity;

public:
    Truck(int power, const std::string& b, double p, double cc) : Car(power, b, p), cargoCapacity(cc) {}

    // Деструктор
    ~Truck() {
        std::cout << "Truck object destroyed" << std::endl;
    }

    // Функція для друку
    void printDetails() const {
        std::cout << "Brand: " << getBrand() << std::endl;
        std::cout << "Price: " << getPrice() << std::endl;
        std::cout << "Cargo Capacity: " << cargoCapacity << std::endl;
        std::cout << "Engine Power: " << getPower() << std::endl;
    }
};

int main() {
    // Створюємо екземпляр вантажівки
    Truck truck(300, "Volvo", 50000, 10000);
    // Друкуємо деталі вантажівки
    truck.printDetails();

    return 0;
}
*/
/*Завдання 3*/
/*#include <iostream>
#include <string>

class Furniture {
protected:
    std::string material;
    double price;
public:
    Furniture(const std::string& mat, double pr) : material(mat), price(pr) {}
    Furniture(const Furniture& other) : material(other.material), price(other.price) {}
    virtual ~Furniture() {}

    virtual void display() const {
        std::cout << "Material: " << material << ", Price: " << price << std::endl;
    }

    virtual void input() {
        std::cout << "Enter material: ";
        std::cin >> material;
        std::cout << "Enter price: ";
        std::cin >> price;
    }

    Furniture& operator=(const Furniture& other) {
        if (this != &other) {
            material = other.material;
            price = other.price;
        }
        return *this;
    }
};

class Table : public Furniture {
private:
    int seats;
public:
    Table(const std::string& mat, double pr, int st) : Furniture(mat, pr), seats(st) {}
    Table(const Table& other) : Furniture(other), seats(other.seats) {}

    void display() const override {
        std::cout << "Table - Material: " << material << ", Price: " << price << ", Seats: " << seats << std::endl;
    }

    void input() override {
        Furniture::input();
        std::cout << "Enter number of seats: ";
        std::cin >> seats;
    }

    Table& operator=(const Table& other) {
        if (this != &other) {
            Furniture::operator=(other);
            seats = other.seats;
        }
        return *this;
    }
};

int main() {
    // Example usage
    Furniture generic("Wood", 100.0);
    generic.display();

    Table dining_table("Oak", 500.0, 6);
    dining_table.display();

    Furniture* ptr_furniture = &dining_table;
    ptr_furniture->display(); // Polymorphic behavior

    // Input example
    Table new_table("Unknown", 0.0, 0);
    new_table.input();
    new_table.display();

    return 0;
}
*/