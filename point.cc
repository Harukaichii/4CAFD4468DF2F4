#include <iostream>
#include <string>
#include <iostream>
#include "point.h"
using namespace std;

Point::Point(int x, int y, string type) 
    : x{x}, y{y}, type{type} {}

void Point::draw() {

}

void Point::undraw() {

}

// setter
void Point::setType(string type) {
    this->type = type;
}

// getter
int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

string Point::getType() {
    return this->type;
}

void Point::reset() {
    this->type = " ";
}