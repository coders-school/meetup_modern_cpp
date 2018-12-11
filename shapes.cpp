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
