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
    Rectangle(const Rectangle & other) = default;

    double getArea() const override { return x_ * y_; }
    double getPerimeter() const override { return 2 * (x_ + y_); }
    virtual double getX() const final { return x_; }
    double getY() const { return y_; }
    void print() const override {
    	cout << "Rectangle: x: " << getX() << endl
             << "           y: " << getY() << endl
             << "        area: " << getArea() << endl
             << "   perimeter: " << getPerimeter() << endl;
	}

private:
    Rectangle() = delete;

    double x_;
    double y_;
};

class Square final : public Rectangle
{
public:
    Square(double x) : Rectangle(x, x) {}
    Square(const Square & other) = default;

    double getArea() const override { return getX() * getX(); }
    double getPerimeter() const override { return 4 * getX(); }
    void print() const override {
    	cout << "Square:    x: " << getX() << endl
             << "        area: " << getArea() << endl
             << "   perimeter: " << getPerimeter() << endl;
	}

private:
    double getY() = delete;
    Square() = delete;
};

auto sortByArea(Shape* first, Shape* second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

using Collection = vector<Shape*>;

auto printCollectionElements(const Collection& collection)
{
    for(const auto & it : collection)
        if(it != nullptr)
            it->print();
}

auto printAreas(const Collection& collection)
{
    for(const auto & it : collection)
        if(it != nullptr)
            cout << it->getArea() << endl;
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
