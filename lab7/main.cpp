#include <iostream>
#include "course.h"

int main(){
    Course *ve482=create("Technical", "VE370");
    ve482->updateTask("Assignment", 1, 9, 20);
    ve482->updateTask("Project", 1, 9, 26);
    ve482->updateTask("Assignment", 2, 9, 27);
    ve482->print();
    ve482->finishTask("Assignment", 1, 9, 14);
    ve482->updateTask("Project", 1, 10, 1);
    ve482->print();
    ve482->finishTask("Homework", 1,9,10);
    ve482->updateTask("Homework", 2, 9, 15); // do nothing
    ve482->print();
    delete ve482;

    return 0;
}