
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;


template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for std::string
template<>
class Package<string> {
private:
    string item;
public:
    Package(string i) : item(i) {}
    void label() {
        cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

template<typename T, int Size>
class Box {
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};


template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

int main() {

    // Sample Output
    Package<int> intPackage(10);
    Package<string> bookPackage("C++ Primer");
    double temp = 22.5;
    Package<double*> fragilePackage(&temp);

    intPackage.label();
    bookPackage.label();
    fragilePackage.label();

    cout << endl;
    
    Box<string, 3> bookBox;
    bookBox.addItem("The Pragmatic Programmer");
    bookBox.addItem("Clean Code");
    bookBox.printItems();

    cout << endl;

    shipItem(7);
    shipItem("HDMI Cable");
    shipItem(22.5);

    return 0;
}