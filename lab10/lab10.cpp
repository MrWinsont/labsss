
#include <iostream>
#include <vector>
#include <string>
using namespace std;



class animal
{
private:
    int m_age;
    string m_name;
    
public:
    animal(string name,int age) {
        m_name = name;
        m_age = age;
    }
    string getName() {
        return m_name;
    }
    int getAge() {
        return m_age;
    }
};



class zoo
{
private: 
    vector <animal*> m_animals;
public:
    void addAnimal(animal* animal) {
        m_animals.push_back(animal);
    }

    void printAnimals() {
        for (size_t i = 0; i < m_animals.size(); i++) {
            cout << m_animals[i]->getName() << "\t";
            cout << m_animals[i]->getAge() << "\n";
        }
    }
    
};


int main()
{
    animal animal1("monkey", 2);
    animal animal2("bear",19);
    zoo zoo1;
    zoo1.addAnimal(&animal1);
    zoo1.addAnimal(&animal2);
    zoo1.printAnimals();


}
