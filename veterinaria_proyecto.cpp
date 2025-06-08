
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Animal {
    private:

    std::string name;
    std::string ownerName;
    std::string type;

    std::string diagnosis;
    int patientID;

    public:
    static int animalCount;
    
    Animal(std::string name, std::string ownerName, std::string type)
    {
        this->name = name;
        this->ownerName = ownerName;
        this->type = type;
        this->patientID = animalCount++;

        this->diagnosis = "undiagnosed";
    }
    
    std::string getName() { return this->name; }
    std::string getDiagnosis() {return this->diagnosis; }
    std::string getType() { return this->type; }
    std::string getOwnerName() { return this->ownerName; }
    int getPatientID() {return this->patientID; }

   void setName(std::string name) { this->name = name; }
   void setOwnerName(std::string ownerName) { this->ownerName = ownerName; }

    bool ownerIs(std::string ownerName) { return this->ownerName == ownerName; }

    void introduce()
    {
        std::cout<< "My name is " << ownerName << ", and my pet is " << name << ", a " << type << ".\n";
    }

    void diagnosticate(std::string diagnosis, bool show=true)
    {
        this->diagnosis = diagnosis;
        if (!show) return;
        std::cout << "The diagnosis of " << name << " is: " << this->diagnosis << '\n';
    }

    bool diagnosticated(){ return diagnosis != "undiagnosed"; }

    virtual void print()
    {
        std::cout<<" ID:           " << this->patientID << '\n';
        std::cout<<" Name:         " << this->name << '\n';
        std::cout<<" Animal:       " << this->type << '\n';
        std::cout<<" Owner:        " << this->ownerName << '\n';
        std::cout<<" Diagnosis:    " << this->diagnosis << '\n';
    }

    virtual void sound()
    {
        std::cout<<name<<" makes an unknown sound"<<'\n';
    }

    virtual ~Animal()
    {
        std::cout<<name<<" has checked out of the system\n";
    };

}; int Animal::animalCount = 0;

class Dog : public Animal
{
    private:
    std::string size;

    public:
    Dog(std::string name, std::string ownerName, std::string size) : Animal(name, ownerName, "Dog")
    {
        this->size = size;
    }

    std::string getSize(){ return size; }
    void setSize(std::string size) { this->size = size; }

    void print() override 
    {
        Animal::print();
        std::cout<<" Size:         " << size << '\n';
    }

    void sound() override {
        std::cout<<getName()<<" barks !!"<<'\n';
    }

    ~Dog() override
    {
        //std::cout<<"The dog "<<getName()<<" has checked out of the system\n";
        std::cout<<"The dog ";
    }
};

class Cat : public Animal
{
    private:

    bool likesPeople;

    public:
    Cat(std::string name, std::string ownerName, bool likesPeople) : Animal(name, ownerName, "Cat")
    {
        this->likesPeople = likesPeople;
    }

    bool getLikesPeople(){ return likesPeople; }
    void setLikesPeople(bool likesPeople) {this->likesPeople = likesPeople; }

    void print() override 
    {
        Animal::print();
        std::cout<<" Likes people: " << (likesPeople ? "True" : "False") << '\n';
    }

    void sound() override {
        std::cout<<getName()<<" meows ~~"<<'\n';
    }

    ~Cat() override
    {
        //std::cout<<"The cat "<<getName()<<" has checked out of the system\n";
        std::cout<<"The cat ";
    }
};

class Employee {
    private:
    // Atributos
        std::string type;
        std::string name;
        int salary;
    public:
    // Constructor
        Employee(std::string type, std::string name, int salary){
            this->type = type;
            this->name = name;
            this->salary = salary;
        }
        Employee(std::string name, int salary){
            this->type = "NA";
            this->name = name;
            this->salary = salary;
        }
    // Metodos
        std::string getType() {
            return type;
        }
        std::string getName() {
            return name;
        }
        int getSalary() {
            return salary;
        }
        void showInfo(){
            std::cout << "The employees name is: " << name << std::endl;
            std::cout << "Their job is: " << type << std::endl;
            std::cout << "Their salary is: " << salary << " pesos." << std::endl;
        }
        void changeType(std::string newType){
            type = newType;
        }
        void changeSalary(int increment){
            salary = salary + increment;
        }
        void changeName(std::string newName){
            name = newName;
        }
        virtual void performJob() {
            std::cout << "working" << std::endl;
        }
    // Destructor
        virtual ~Employee() {
            std::cout << "employee was destroyed" << std::endl;
        }
};

class Veterinarian : public Employee {
    private:
        std::string shift;
    public:
    // Constructor
        Veterinarian(std::string name, int salary, std::string shift) : Employee("veterinarian", name, salary) {
            this->shift = shift;
        }
    // Metodos
        void performJob() override {
            std::cout << getName() << " is treating an animal" << std::endl;
        }
        std::string getShift(){ return shift; }

    // Destructor
        ~Veterinarian() {
            std::cout << "veterinarian was destroyed" << std::endl;
        }

};

class Administrator : public Employee {
    private:
        std::string shift;
    public:
    // Constructor
        Administrator(std::string name, int salary, std::string shift) : Employee("administrator", name, salary) {
            this->shift = shift;
        }
    // Metodos
        void performJob() override {
            std::cout << getName() << " is supervising everything" << std::endl;
        }
        std::string getShift(){ return shift; }

    // Destructor
        ~Administrator() {
            std::cout << "admin was destroyed" << std::endl;
        }
};

class Room {
private:
    std::string name;
    Employee *inCharge;
    bool open;
    std::string type;

public:
    Room(std::string name, Employee *inCharge, std::string type) {
        this->name = name;
        this->inCharge = inCharge;
        this->open = true;
        this->type = type;
    }

    std::string getName() const { return this->name; }
    Employee *getInCharge() const { return this->inCharge; }
    std::string getType(){ return type; }
    bool getOpen() const { return this->open; }
    void setName(std::string name) { this->name = name; }
    void setInCharge(Employee *inCharge) { this->inCharge = inCharge; }

    virtual void enter() {
        std::cout << "\nWelcome to room: " << name << "!" << std::endl;
        std::cout << inCharge->getName() << " is in charge of this room." << std::endl;
    }

    void setOpen(bool status) {
        this->open = status;
        std::cout << name << " is now " << (this->open ? "open." : "closed.") << std::endl;
    }

    virtual void info()
    {
        std::cout<<"Name:             "<<name<<'\n';
        std::cout<<"Type:             "<<type<<'\n';
        std::cout<<"Person in charge: "<<inCharge->getName()<<'\n';
        //std::cout<<"Open:             "<< (open ? "True" : "False") << '\n';
    }

    virtual void reset()
    {
        open = true;
    };

    virtual ~Room() { std::cout << name << " has been destroyed." << std::endl; }
};

class ExamRoom : public Room {
private:
    Veterinarian *veterinarian;
    bool occupied = false;
    Animal *patient;

public:
    ExamRoom(std::string name, Employee *inCharge, Veterinarian *veterinarian)
        : Room(name, inCharge, "Exam Room"), veterinarian(veterinarian) {
            patient = nullptr;
        }

    Veterinarian *getVeterinarian() const { return veterinarian; }
    bool getOccupied() const { return occupied; }
    void setVeterinarian(Veterinarian *veterinarian) { this->veterinarian = veterinarian; }
    void setOccupied(bool occupied) { occupy(occupied); }

    void occupy(bool occupied) {
        this->occupied = occupied;
        patient = nullptr;
        std::cout << getName() << " is now " << (this->occupied ? "occupied." : "free to use.") << std::endl;
    }

    void enter() override {
        if (occupied) {
            std::cout << "You cannot enter. This room is occupied." << std::endl;
        } else {
            std::cout << "\nWelcome to room: " << getName() << "!" << std::endl;
            std::cout << getInCharge()->getName() << " is in charge of this room." << std::endl;
            occupy(true);
        }
    }

    void examine(Animal *animal)
    {
        examine(animal, veterinarian);
    }

    void examine(Animal *animal, Veterinarian *vet)
    {
        enter();
        std::cout << "The vet " << vet->getName() << " is examining " << animal->getName() <<"\n";
        patient = animal;
        
        std::string diagnosis;
        std::cout<<"Enter diagnosis: ";
        std::getline(std::cin, diagnosis);

        animal->diagnosticate(diagnosis);
    }

    void info() override {
        Room::info();
        std::cout<<"Veterinarian:     "<<veterinarian->getName()<<'\n';
        std::cout<<"Occupied:         "<< (occupied ? "True" : "False") <<'\n';

        if (patient != nullptr)
        {
            std::cout<<"Current Patient:  "<<patient->getName()<<"("<<patient->getType()<<")"<<'\n';
        }
    }

    void reset() override 
    {
        Room::reset();
        occupy(false);
    }

    ~ExamRoom() override { std::cout << getName() << " has been destroyed." << std::endl; }
};

class Reception : public Room {
private:
    std::string buildingName;
    Employee *receptionist;

public:
    Reception(std::string name, Employee *inCharge, Employee *receptionist, std::string buildingName)
        : Room(name, inCharge, "Reception"), buildingName(buildingName), receptionist(receptionist) {}

    void enter() override {
        std::cout << "Welcome to " << buildingName << "!|" << std::endl;
        std::cout << "My name is " << receptionist->getName() << "." << std::endl;
    }

    void info() override 
    {
        Room::info();
        std::cout<<"Building's Name:  "<<buildingName<<'\n';
        std::cout<<"Receptionist:     "<<receptionist->getName()<<'\n';
    }

    ~Reception() override { std::cout << getName() << " has been destroyed." << std::endl; }
};

class VetClinic
{
    private:
    std::string name;
    std::vector<Employee*> employees;
    std::vector<Animal*> animals;
    std::vector<Room*> rooms;
    Room* reception;

    public:
    VetClinic(std::string name)
    {
        this->name = name;
        employees.clear(); rooms.clear(); animals.clear();

        //employees.push_back(new Veterinarian("Melinda Stark", 20000, "8:30-15:00"));
        //employees.push_back(new Veterinarian("Rock Fuentes", 10000, "9:00-12:00"));
        //employees.push_back(new Administrator("Hannah Perez", 25000, "7:00-15:00"));

        loadEmployees();
        loadAnimals();

        rooms.push_back(new ExamRoom("Exam Room A", employees[0], (Veterinarian*)employees[0]));
        rooms.push_back(new ExamRoom("Exam Room B", employees[0], (Veterinarian*)employees[1]));

        reception = new Reception("Lobby", employees[2], employees[2], "Vente Rinaria Clinic");
        rooms.push_back(reception);
    };

    void loadEmployees()
    {
        // Employee builder
        std::string type, name, shift;
        int salary;
        int i = 0;

        // File
        std::string line;
        std::ifstream f("employees.txt");

        while (std::getline(f, line)){
            switch (i)
            {
            case 0:
                type = line;
                break;
            case 1:
                name = line;
                break;
            case 2:
                try{ salary = stoi(line); }
                catch(...) { salary = 1000; }
                break;
            case 3:
                shift = line;
            
            default:
                break;
            }
            i = (i + 1) % 4;

            if (i == 0)
            {
                if (type == "veterinarian")
                {
                    employees.push_back(new Veterinarian(name, salary, shift));
                }
                else if (type == "administrator")
                {
                    employees.push_back(new Administrator(name, salary, shift));
                }
                else{
                    employees.push_back(new Employee(name, salary));
                }
            }
        };
        f.close();
    };

    void loadAnimals()
    {
        // Animal builder
        std::string name, ownerName, diagnosis, type, extra;
        int i = 0;

        // File
        std::string line;
        std::ifstream f("animals.txt");
        
        while(std::getline(f, line))
        {
            switch (i)
            {
            case 0:
                name = line;
                break;
            case 1:
                ownerName = line;
                break;
            case 2:
                diagnosis = line;
                break;
            case 3:
                type = line;
                break;
            case 4:
                extra = line;
                break;
            default:
                break;
            }
            i = (i + 1) % 5;
            if (i == 0)
            {
                if (type == "Dog")
                {
                    animals.push_back(new Dog(name, ownerName, extra));
                    animals.back()->diagnosticate(diagnosis, false);
                }
                else if (type == "Cat")
                {
                    animals.push_back(new Cat(name, ownerName, extra=="1"));
                    animals.back()->diagnosticate(diagnosis, false);
                }
            }
        };

        f.close();
    };

    void saveEmployees()
    {
        std::ofstream f("employees.txt");
        for (Employee *employee: employees)
        {
            f << employee->getType() << std::endl;
            f << employee->getName() << std::endl;
            f << employee->getSalary() << std::endl;

            if (employee->getType() == "veterinarian"){
                f << ((Veterinarian*)employee)->getShift()<<std::endl;
            }else if (employee->getType() == "administrator"){
                f << ((Administrator*)employee)->getShift()<<std::endl;
            }else{
                f << "9:00-12:00"<<std::endl;
            }
        }
        f.close();
    }

    void saveAnimals()
    {
        std::ofstream f("animals.txt");
        for (Animal *animal: animals)
        {
            f << animal->getName() << '\n';
            f << animal->getOwnerName() << '\n';
            f << animal->getDiagnosis()<< '\n';
            f << animal->getType() << '\n';
            
            if (animal->getType() == "Cat"){
                f << ((Cat*)animal)->getLikesPeople()<< '\n';
            }else if (animal->getType() == "Dog")
            {
                f << ((Dog*)animal)->getSize()<< '\n';
            }else{ f << "-"; }
        }
        f.close();
    }

    ~VetClinic()
    {
        saveEmployees();
        saveAnimals();

        for (Employee *ptrEmployee : employees)
            delete ptrEmployee;

        for (Animal *ptrAnimal : animals)
            delete ptrAnimal;

        for (Room *ptrRoom : rooms)
            delete ptrRoom;

        employees.clear();
        animals.clear();
        rooms.clear();
    };

    void info()
    {
        std::cout<<"~~~~~ VET CLINICS: "<<name<<" ~~~~~"<<'\n';
        
        infoEmployees();
        infoRooms();
        infoAnimals();

        std::cout<<"~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~\n";
    };

    void infoEmployees()
    {
        std::cout<<"\n\n~~~ EMPLOYEES: ~~~\n";
        for (Employee* employee : employees){
            employee->showInfo();
            std::cout<<'\n';
        }
    }

    void infoRooms()
    {
        std::cout<<"\n\n~~~ ROOMS: ~~~\n";
        for (Room* room : rooms)
        {
            room->info();
            std::cout<<'\n';
        }
    };

    void infoAnimals()
    {
        std::cout<<"\n\n~~~ ANIMALS: ~~~\n";
        for (Animal* animal : animals)
        {
            animal->print();
            std::cout<<'\n';
        }
    };

    void animalExamAll()
    {
        if (animals.size() < 1) return;
        
        for (Animal* animal : animals)
        {
            if (!animal->diagnosticated())
            {
                bool successfulExam = animalExam(animal);
                if (!successfulExam) return;
            }
        }
    };

    bool animalExam(int animalID)
    {
        Animal *animal = getAnimalByID(animalID);
        if (animal == nullptr) return false;
        return animalExam(animal);
    }

    bool animalExam(Animal *animal)
    {
        ExamRoom *examRoom = getExamRoom();
        if (examRoom == nullptr) return false;
        
        examRoom->examine(animal);
        return true;
    };

    void dischargeAnimalAll()
    {
        if (animals.size() < 1) return;
        
        for (Animal* animal : animals)
        {
            dischargeAnimal(animal);
        }
    }

    void dischargeAnimal(int animalID)
    {
        Animal *animal = getAnimalByID(animalID);
        if (animal == nullptr) return;
        dischargeAnimal(animal);
    }

    void dischargeAnimal(Animal *animal)
    {
        if (!animal->diagnosticated()){
            std::cout<<animal->getName()<<" has not been diagnosticated. It cannot leave yet.\n";
            return;
        }

        std::vector<Animal*>::iterator position = std::find(animals.begin(), animals.end(), animal);
        if (position != animals.end())
        {
            animals.erase(position);
            std::cout<<animal->getName()<<" has been discharged from the clinic.\n"; 
            delete animal; std::cout<<"\n\n";
            return;
        }

        std::cout<<animal->getName()<<" is not in the system";
    }

    ExamRoom *getExamRoom()
    {
        for (Room *room : rooms)
        {
            if (room->getType() != "Exam Room") continue;
            ExamRoom* eRoom = (ExamRoom*)room;
            if (!eRoom->getOccupied()) return eRoom;
        }

        std::cout<<"There isn't a free exam room.\n";
        return nullptr;
    };

    Reception *getReception() { return (Reception*)reception; }

    Animal *getAnimalByID(int id)
    {
        for (Animal* animal : animals)
        {
            if (animal->getPatientID() == id) 
                return animal;
        }
        
        std::cout<<"No animal has the ID "<<id<<"\n";
        return nullptr;
    }

    void admitPet(Animal *animal)
    {
        animals.push_back(animal);
        animal->introduce();
        animal->sound();
    };

    void resetRooms()
    {
        for (Room *room : rooms)
        {
            if (room->getType() == "Reception") continue;
            room->reset();
        }
    };
};

class Menu
{
    private:
    VetClinic *clinic;
    bool menuOn;
    
    public:
    Menu(VetClinic *clinic)
    {
        this->clinic = clinic;
    }

    void welcomeMessage()
    {
        std::cout<<"~~~~ START ~~~~\n\n\n";
        clinic->getReception()->enter();
        std::cout<<"\nType 'help' to get started\n";
    };

    void play()
    {
        welcomeMessage();

        menuOn = true;
        std::string input;
        do{
            
            std::cout<<"\n> ";
            std::getline(std::cin, input);
            this->input(input);

        } while (menuOn);
    };

    void addAnimal()
    {
        Animal *newAnimal = nullptr;
        std::string name, ownerName, type;

        std::cout<<"\nEnter owner's name: ";
        std::getline(std::cin, ownerName);
        std::cout<<"Enter pet's name: ";
        std::getline(std::cin, name);
        std::cout<<"Enter "<<name<<"'s species (dog/cat): ";
        std::getline(std::cin, type);

        if (type[0] == 'd') {
            std::string size;
            std::cout<<"Enter "<<name<<"'s size (small, medium, big): "; 
            std::getline(std::cin, size);

            newAnimal = new Dog(name, ownerName, size);
        }

        if (type[0] == 'c') {
            std::string anwser;
            std::cout<<"Does " << name << " likes being around people? (y/n) ";
            std::getline(std::cin, anwser);
            newAnimal = new Cat(name, ownerName, anwser[0] == 'y');
        }

        if (newAnimal == nullptr) return;
        std::cout<<"\nRegistration Completed\n";
        clinic->admitPet(newAnimal);
    };

    void input(std::string input)
    {
        std::cout<<'\n';
        if (input == "exit" || input == "end" || input == "stop"){
            menuOn = false; return;
        } else if (input == "help" || input == "h"){
            help(); return;
        } else if (input == "info" || input == "i"){
            clinic->info(); return;
        } else if (input == "info employees" || input == "i e"){
            clinic->infoEmployees(); return;
        } else if (input == "info rooms" || input == "i r"){
            clinic->infoRooms(); return;
        } else if (input == "info animals" || input == "i a"){
            clinic->infoAnimals(); return;
        } else if (input == "add animal" || input == "add a"){
            addAnimal(); return;
        } else if (input.rfind("animal info", 0) == 0){
            int id = getIntInput(input, "animal info ");
            if (id == -1) return;
            Animal *animal = clinic->getAnimalByID(id);
            if (animal == nullptr) { return; }
            animal->print(); return;
        } else if (input == "diagnosticate all"){
            clinic->animalExamAll(); return;
        } else if (input.rfind("diagnosticate", 0) == 0){
            int id = getIntInput(input, "diagnosticate ");
            if (id == -1) return;
            clinic->animalExam(id);
            return;
        } else if (input == "discharge all"){
            clinic->dischargeAnimalAll(); return;
        } else if (input.rfind("discharge", 0) == 0){
            int id = getIntInput(input, "discharge ");
            if (id == -1) return;
            clinic->dischargeAnimal(id);
            return;
        } else if (input == "reset rooms")
        {
            clinic->resetRooms(); return;
        };

        std::cout<<"Unknown command: " << input <<'\n';
        std::cout<<"Try typing \"help\"\n";
    }

    void help()
    {
        std::cout<<"COMMANDS:\n";
        std::cout<<"- add animal\n";
        std::cout<<"- diagnosticate <ID>\n";
        std::cout<<"- diagnosticate all\n";
        std::cout<<"- discharge <ID>\n";
        std::cout<<"- discharge all\n";
        std::cout<<"- reset rooms\n";
        std::cout<<"- exit\n";
        std::cout<<"\nINFO: \n";
        std::cout<<"- help\n";
        std::cout<<"- info\n";
        std::cout<<"- info employees\n";
        std::cout<<"- info rooms\n";
        std::cout<<"- info animals\n";
        std::cout<<"- animal info <ID>\n";
    }

    int getIntInput(std::string input, std::string command)
    {
        if (input.compare(0, command.size(), command) == 0)
            input.erase(0, command.size());
        
        try{
            return std::stoi(input);
        }
        catch (...){
            std::cout<<"\""<<input<<"\" is not a number";
            return -1;
        }
    }

    ~Menu()
    {
        std::cout<<"Exiting system...\n\n[Press enter to close]\t";
        
        std::string input;
        std::getline(std::cin, input);
    };
};

int main()
{
    VetClinic clinic("Vente Rinaria");
    Menu menu(&clinic);

    menu.play();
    return 0;
}