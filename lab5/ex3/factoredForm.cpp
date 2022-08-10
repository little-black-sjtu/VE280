#include "factoredForm.h"

QuadraticFunction::QuadraticFunction(float a_in, float b_in, float c_in):a(a_in){
    float delta= b_in*b_in-4*a_in*c_in;
    float real = -b_in/(2*a_in);
    if(delta>0){
        r1.real = real - sqrt(delta)/(2*a_in);
        r2.real = real + sqrt(delta)/(2*a_in);;
        r1.imaginary = 0;
        r2.imaginary = 0;
    }
    else if(delta == 0){
        r1.real = real;
        r2.real = real;
        r1.imaginary = 0;
        r2.imaginary = 0;
    }
    else{
        r1.real = real;
        r2.real = real;
        r1.imaginary = -sqrt(-delta)/(2*a_in);;
        r2.imaginary = sqrt(-delta)/(2*a_in);;
    }
}
// TODO: implement this constructor

float QuadraticFunction::getA() const {
    return a;
}

float QuadraticFunction::getB() const {
    return -a*(r1.real+r2.real);
    // TODO: implement this function
}

float QuadraticFunction::getC() const {
    return a*(r1.real*r2.real - r1.imaginary*r2.imaginary);
    // TODO: implement this function
}

float QuadraticFunction::evaluate(float x) {
    return getA()*x*x+getB()*x+getC();
    // TODO: implement this function
}

Root QuadraticFunction::getRoot() {
    float delta= getB()*getB()-4*getA()*getC();
    Root root;
    if(delta>0){
        root.realRootNum = 2;
    }
    else if(delta == 0){
        root.realRootNum = 1;
    }
    else{
        root.realRootNum = 0;
    }
    root.roots[0] = r1;
    root.roots[1] = r2;
    return root;
    // TODO: implement this function
}

bool QuadraticFunction::intersect(QuadraticFunction q) {
    float a1 = getA()-q.getA();
    float b1 = getB()-q.getB();
    float c1 = getC()-q.getC();
    if(b1*b1-4*a1*c1>=0)
        return true;
    else
        return false;
    // TODO: implement this function
}