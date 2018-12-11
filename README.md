# Meetup Nowoczesny C++ - Welcome!
![Coders School](http://coders.school/wp-content/uploads/2018/10/LOGO_bez_tla.png)

[![Build Status](https://travis-ci.org/coders-school/meetup_modern_cpp.svg?branch=solutions)](https://travis-ci.org/coders-school/meetup_modern_cpp)

Poniżej jest kod napisany w starym C++03. Reprezentuje on prostą hierarchię figur geometrycznych. Klasa bazowa `Shape` definiuje interfejs z 3 publicznymi metodami: `getArea()`, `getPerimeter()` i `print()`. Po `Shape` dziedziczy klasa `Rectangle` reprezentująca prostokąt, a po niej dziedziczy klasa `Square` reprezentująca kwadrat. Klasy te odpowienio implementują wspomniane metody. W funkcji `main()` jest użycie figur, które są przechowywane w kolekcji. Twoim zadaniem jest unowocześnienie tego kodu, korzystając z możliwości jakie daje C++11 i C++14.

Jeśli ściągniesz kod lokalnie, to dodatkowo możesz sprawdzać postęp za pomocą dodanych skryptów sprawdzających. [Repozytorium do ściągnięcia na GitHubie](https://github.com/coders-school/meetup_modern_cpp)

Potrzebne programy: make, g++

### Użycie:
> make

## Zadania:
1. `nullptr`:
    Zamień wszystkie NULLe na `nullptr`
1. `using` alias:
    Zamień typedef na alias using
1. automatic type deduction:
    Użyj `auto`, tam gdzie można go użyć
1. range based for loop:
    Użyj pętli for po kolekcji tam, gdzie to możliwe
1. `default`:
    Oznacz konstruktory kopiujące jako `default`.
1. `delete`:
    Usuń metodę `getY()` z klasy `Square`.
    Usuń domyślne konstruktory (te bez parametrów).
1. `final`:
    Oznacz klasę `Square` jako `final` oraz oznacz metodę `getX()` w klasie `Rectangle` jako `final`
1. `override`:
    Oznacz wszystkie wirtualne metody jako `override`. Czy zauważasz jakiś problem?

## Zadania dodatkowe:
1. uniform initialization:
    Użyj jednolitej inicjalizacji do zainicjalizowania kolekcji `shapes`.
1. smart pointers:
    Zamień zwykłe wskażniki na `shared_ptr`
1. lambda functions:
    Zamień funkcję `sortByArea()` na funkcję lambda

```C++ runnable
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const { cout << "Unknown Shape" << endl; }
};

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y) : x_(x), y_(y) {}
    Rectangle(const Rectangle & other) { x_ = other.getX(); y_ = other.getY(); }

    double getArea() const { return x_ * y_; }
    double getPerimeter() const { return 2 * (x_ + y_); }
    double getX() const { return x_; }
    double getY() const { return y_; }
    void print() const {
    	cout << "Rectangle: x: " << getX() << endl
             << "           y: " << getY() << endl
             << "        area: " << getArea() << endl
             << "   perimeter: " << getPerimeter() << endl;
	}

private:
    Rectangle();

    double x_;
    double y_;
};

class Square : public Rectangle
{
public:
    Square(double x) : Rectangle(x, x) {}
    Square(const Square & other) : Rectangle(other.getX(), other.getX()) {}

    double getArea() { return getX() * getX(); }
    double getPerimeter() { return 4 * getX(); }
    void print() {
    	cout << "Square:    x: " << getX() << endl
             << "        area: " << getArea() << endl
             << "   perimeter: " << getPerimeter() << endl;
	}

private:
    double getY(); // should not have Y dimension
    Square();
};

bool sortByArea(Shape* first, Shape* second)
{
    if(first == NULL || second == NULL)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

typedef vector<Shape*> Collection;

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it != NULL)
            (*it)->print();
}

void printAreas(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it != NULL)
            cout << (*it)->getArea() << endl;
}

int main() {
	Collection shapes;
    shapes.push_back(new Rectangle(4.0, 2.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Square(4.0));
    
    printCollectionElements(shapes);
    
    cout << "Areas before sort: " << endl;
    printAreas(shapes);
    sort(shapes.begin(), shapes.end(), sortByArea);
    cout << "Areas after sort: " << endl;
    printAreas(shapes);
    
	return 0;
}
```

## Co dalej?

1. Porównaj swoje rozwiązania z naszymi na [GitHubie](https://github.com/coders-school/meetup_modern_cpp/tree/solutions)
1. Polub [Coders School na Facebooku](https://www.facebook.com/szkola.coders.school)
1. Zapisz się na [newsletter](http://coders.school/?elementor_library=formularz-mailingowy), aby pobrać dzisiejszą prezentację oraz otrzymywać informacje o przyszłych wydarzeniach i kursach (możesz się wypisać w dowolnej chwili)
1. Dołącz do [Meetupa Kurs programowania C++](https://www.meetup.com/pl-PL/Kurs-programowania-C/)
1. Odwiedź stronę [Coders School - http://coders.school](http://coders.school)
1. Sprawdź swój poziom znajomości C++ wykonując [10-minutowy test](http://coders.school/sprawdz-sie/)
1. Zapoznaj się z naszą ofertą [kursu C++](http://coders.school/kurs-cpp/)
1. Zgłoś się na [darmowe konsultacje z C++](http://coders.school/post/darmowe-konsultacje-z-cpp/)
1. W razie jakichkolwiek pytań napisz mi maila - lukasz(at)coders.school

![Hello job!](http://coders.school/wp-content/uploads/2017/06/back.jpg)
