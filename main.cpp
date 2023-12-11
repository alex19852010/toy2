#include <iostream>
#include <memory>

using namespace std;
 
 class Toy {
private:
    string toyName;

public:
    Toy(const string& name) : toyName(name) {}

    Toy(const Toy& other) : toyName(other.toyName) {}

    Toy& operator=(const Toy& other) {
        if (this != &other) {
            toyName = other.toyName;
        }
        return *this;
    }

    string getToyName() const {
        return toyName;
    }

    ~Toy() {
        cout << "Deleting toy: " << toyName << endl;
    }
};

shared_ptr<Toy> make_shared_toy(const string& name) {
    return make_shared<Toy>(name);
}

int main() {
  
   shared_ptr<Toy> toy_01 = make_shared_toy("ball");
    shared_ptr<Toy> toy_02(toy_01);
    shared_ptr<Toy> toy_03 = make_shared_toy("duck");

    cout << "=================================================" << endl;
    cout << toy_01->getToyName() << " links: " << toy_01.use_count() << "  "
         << toy_02->getToyName() << " links: " << toy_02.use_count() << "  "
         << toy_03->getToyName() << " links: " << toy_03.use_count() << endl;
    cout << "=================================================" << endl;

    toy_02 = toy_03;

    cout << toy_01->getToyName() << " links: " << toy_01.use_count() << "  "
         << toy_02->getToyName() << " links: " << toy_02.use_count() << "  "
         << toy_03->getToyName() << " links: " << toy_03.use_count() << endl;
    cout << "=================================================" << endl;

    toy_01.reset();

    cout << toy_01.get() << " links: " << toy_01.use_count() << "  "
         << toy_02->getToyName() << " links: " << toy_02.use_count() << "  "
         << toy_03->getToyName() << " links: " << toy_03.use_count() << endl;
    cout << "=================================================" << endl;
    
    return 0;
}

