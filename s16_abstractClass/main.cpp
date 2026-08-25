#include <iostream>
#include <vector>


class i_Printable {
    friend std::ostream &operator<<(std::ostream &os, const i_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const i_Printable &obj) {
    obj.print(os);
    return os;
}

// In function add
/*
 virtual void print(std::ostream &os) const override {
    os << "Account display";
  }
  */


class Shape : public i_Printable {       // Abstract
private:
    // Attributes
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {}
};


class OpenShape : public Shape {    //Abstract
public:
    virtual ~OpenShape() {}
};

class ClosedShape : public Shape {  // Abstract
public:
    virtual ~ClosedShape() {}
};


class Line : public OpenShape {     // Concrete
public:
    virtual void draw() override {
        std::cout << "Drawing line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotate Line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle : public ClosedShape {     // Concrete
public:
    virtual void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotate Circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square : public ClosedShape {     // Concrete
public:
    virtual void draw() override {
        std::cout << "Drawing Square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotate Square" << std::endl;
    }
    virtual ~Square() {}
};

void screen_refresh(const std::vector<Shape*>& shapes) {
    std::cout << "=========Screen refresh======" << std::endl << std::endl;
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

int main() {
    //    Shape s;
    //    Shape *p = new Shape();
    //    Circle c;
    //    c.draw();

    Shape *ptr = new Line();
    ptr->draw();
    ptr->rotate();
    delete ptr;

    std::cout << std::endl;

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape*> shapes {s1, s2, s3};
 //   for (const auto shape : shapes) {
 //       shape->draw();
 //   }

    std::cout << std::endl;
    screen_refresh(shapes);


    delete s1;
    delete s2;
    delete s3;


    return 0;
}