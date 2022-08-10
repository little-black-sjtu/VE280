/*
 * VE280 Lab 7, SU2022
 * Created by cyx on 20-5-22.
 * Modified by tongjin on June 26th, 2022.
 */

#include <iostream>
#include "course.h"

void TechnicalCourse::updateTask(const std::string &type, int index, int dueMonth, int dueDay) 
// REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: if Task index of type already exists in tasks, updates its dueMonth & dueDay ;
//          otherwise, adds Task i of type at the end of tasks if tasks is not full,
//          throw an exception if tasks is full
{
    int i;
    for(i=0; i<numTasks; i++){
        if(tasks[i].type==type&&tasks[i].index == index){
            tasks[i].dueDay = dueDay;
            tasks[i].dueMonth = dueMonth;
            break;
        }
    }
    if(i==numTasks){
        if(numTasks==sizeTasks) throw TooManyTasks();
        numTasks++;
        tasks[i].index = index;
        tasks[i].type = type;
        tasks[i].dueDay = dueDay;
        tasks[i].dueMonth = dueMonth;
        if(type=="Lab"||type=="Project") std::cout<<courseCode<<" "<<type<<" "<<index<<" is released! Submit it via oj!"<<std::endl;
        else std::cout<<courseCode<<" "<<type<<" "<<index<<" is released! Submit it via canvas!"<<std::endl;
    }
    // TODO: implement this function
}

void TechnicalCourse::finishTask(const std::string &type, int index, int finishMonth, int finishDay)
// REQUIRES: Task index of type is in tasks. finishMonth and finishDay are in normal range.
// MODIFIES: this
// EFFECTS: removes Task index of type
{
    int i;
    bool flag=false;
    for(i=0; i<numTasks; i++){
        if(tasks[i].type==type&&tasks[i].index == index){
            if(finishMonth<tasks[i].dueMonth||(finishMonth==tasks[i].dueMonth&&finishDay<=tasks[i].dueDay))
                std::cout<<courseCode<<" "<<type<<" "<<index<<" is finished!"<<std::endl;
            else 
                std::cout<<courseCode<<" "<<type<<" "<<index<<" is overdue!"<<std::endl;
            flag = true;
            numTasks--;
        }
        if(flag) tasks[i] = tasks[i+1];
    }
    // TODO: implement this function
}

void TechnicalCourse::print() const {
    std::cout << courseCode << std::endl;
    for (int i = 0; i < numTasks; ++i) {
        std::cout << tasks[i].type << " " << tasks[i].index << ": "
                  << tasks[i].dueMonth << "/" << tasks[i].dueDay << std::endl;
    }
}

void UpperLevelTechnicalCourse::updateTask(const std::string &type, int index, int dueMonth, int dueDay) 
// REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: If Task index of type does not exist in tasks,
//          adds Task i of type according to its due date if tasks is not full, throw an exception if tasks is full.
//          If Task index of type already exists in tasks,
//          updates its position in tasks & dueMonth & dueDay if its dueMonth/dueDay is changed,
//          do nothing if its dueMonth/dueDay is unchanged.
{
    int i;
    bool insert=true;
    for(i=0; i<numTasks; i++){
        if(tasks[i].type==type&&tasks[i].index == index){
            insert = false;
            break;
        }
    }
    if(!insert){
        if(tasks[i].dueMonth>dueMonth||(tasks[i].dueMonth==dueMonth&&tasks[i].dueDay>dueDay)){
            while(i!=0&&(tasks[i-1].dueMonth>dueMonth||(tasks[i-1].dueMonth==dueMonth&&tasks[i-1].dueDay>dueDay))){
                Task temp = tasks[i];
                tasks[i] = tasks[i-1];
                tasks[i-1] = temp;
                i--;
            }
        }
        else{
            while((i!=numTasks-1)&&(tasks[i+1].dueMonth<dueMonth||(tasks[i+1].dueMonth==dueMonth&&tasks[i+1].dueDay<=dueDay))){
                Task temp = tasks[i];
                tasks[i] = tasks[i+1];
                tasks[i+1] = temp;
                i++;
            }
        }
        tasks[i].dueDay=dueDay;
        tasks[i].dueMonth=dueMonth;
    }
    else{
        if(numTasks==sizeTasks) throw TooManyTasks();
        numTasks++;
        i=0;
        while(i!=numTasks-1&&(tasks[i].dueMonth<dueMonth||(tasks[i].dueMonth==dueMonth&&tasks[i].dueDay<=dueDay))) i++;
        for(int j=numTasks-1;j>i;j--){
            tasks[j] = tasks[j-1];
        }
        tasks[i].type = type;
        tasks[i].index = index;
        tasks[i].dueDay = dueDay;
        tasks[i].dueMonth = dueMonth;
        if(type=="Lab"||type=="Project") std::cout<<courseCode<<" "<<type<<" "<<index<<" is released! Submit it via oj!"<<std::endl;
        else if(type=="Team Project") std::cout<<courseCode<<" "<<type<<" "<<index<<" is released! Submit it via github!"<<std::endl;
        else std::cout<<courseCode<<" "<<type<<" "<<index<<" is released! Submit it via canvas!"<<std::endl;
    }
    // TODO: implement this function
}

Course *create(const std::string &classType, const std::string &courseCode) {
    if (classType == "Technical") {
        return new TechnicalCourse(courseCode);
    } else if (classType == "Upper Level Technical") {
        return new UpperLevelTechnicalCourse(courseCode);
    } else {
        return nullptr;
    }
}

Course *create(const std::string &classType, const std::string &courseCode, const int &size) {
    if (classType == "Technical") {
        return new TechnicalCourse(courseCode, size);
    } else if (classType == "Upper Level Technical") {
        return new UpperLevelTechnicalCourse(courseCode, size);
    } else {
        return nullptr;
    }
}
