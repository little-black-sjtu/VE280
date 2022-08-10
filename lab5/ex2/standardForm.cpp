#include <cmath>
#include "standardForm.h"

QuadraticFunction::QuadraticFunction(float a_in, float b_in, float c_in):a(a_in), b(b_in), c(c_in){}
// TODO: implement this constructor

float QuadraticFunction::getA() const {
    return a;
}

float QuadraticFunction::getB() const {
    return b;
}

float QuadraticFunction::getC() const {
    return c;
}

float QuadraticFunction::evaluate(float x) {
    return getA()*x*x+getB()*x+getC();
    // TODO: implement this function
}

Root QuadraticFunction::getRoot() {
    float delta= getB()*getB()-4*getA()*getC();
    float real = -getB()/(2*getA());
    Root root;
    if(delta>0){
        root.realRootNum = 2;
        root.roots[0].real = real - sqrt(delta)/(2*getA());
        root.roots[1].real = real + sqrt(delta)/(2*getA());;
        root.roots[0].imaginary = 0;
        root.roots[1].imaginary = 0;
    }
    else if(delta == 0){
        root.realRootNum = 1;
        root.roots[0].real = real;
        root.roots[1].real = real;
        root.roots[0].imaginary = 0;
        root.roots[1].imaginary = 0;
    }
    else{
        root.realRootNum = 0;
        root.roots[0].real = real;
        root.roots[1].real = real;
        root.roots[0].imaginary = -sqrt(-delta)/(2*getA());;
        root.roots[1].imaginary = sqrt(-delta)/(2*getA());;
    }
    return root;
    // TODO: implement this function
}

bool QuadraticFunction::intersect(QuadraticFunction q){
    float a1 = getA()-q.getA();
    float b1 = getB()-q.getB();
    float c1 = getC()-q.getC();
    if(b1*b1-4*a1*c1>=0)
        return true;
    else
        return false;
    // TODO: implement this function
}
