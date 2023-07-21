#include <iostream>
#include <memory> 

using namespace std; 

class A {
    int *data; 

    public: 
    A() {
        cout << "Resource added!" << endl; 
        data = new int[100]; 
    }

    void some() { cout << "Available using as normal pointer" << endl; }

    ~A() {
        cout << "Resource released!" << endl;
        delete[] data;  
    }
};

void do_something() { 
    unique_ptr<A> pa(new A()); 
    pa->some(); 

    unique_ptr<A> pb = pa; 
}

int main() 
{
    do_something();
}