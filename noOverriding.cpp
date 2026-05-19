#include <iostream>
using namespace std;

class baseClass {
public:
    virtual void perkenalan() final {
        cout << "hallo saya function dari base class";
    }
};

class derivedClass : public baseClass {
public :
    void perkenalan1() {
        cout << "hallo saya function dari derived class";
    }
};