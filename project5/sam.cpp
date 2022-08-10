#include <algorithm>
#include <iostream>
#include <string>
#include "Dlist.h"
#include "Instr.h"

const int memory_size = 16;

class Stack {
    Dlist<int> stack;
public:
    void push(int num){
        stack.insertBack(new int(num));
    }

    int pop(){
        int *p = stack.removeBack();
        int value = *p;
        delete p;
        return value;
    }

    friend std::ostream& operator<< (std::ostream& os, const Stack& dl) {
        os<<dl.stack;
        return os;
    }
};

class Queue {
    Dlist<Instr> queue;
public:
    void push_front(Instr num){
        queue.insertFront(new Instr(num));
    }

    Instr pop(){
        Instr *p = queue.removeFront();
        Instr value = *p;
        delete p;
        return value;
    }

    void push_back(Instr num){
        queue.insertBack(new Instr(num));
    }

    bool isEmpty(){
        return queue.isEmpty();
    }

    friend std::ostream& operator<< (std::ostream& os, const Queue& dl) {
        os<<dl.queue;
        return os;
    }
};


void read_input(Stack &stack, Queue &queue, int *array){
    int m, n;
    std::cin>>m>>n;
    while(m!=0){
        int temp;
        std::cin>>temp;
        stack.push(temp);
        m--;
    }
    while(n!=0){
        Instr temp;
        std::cin>>temp;
        queue.push_back(temp);
        n--;
    }
    for(int i=0;i<memory_size;i++){
        int temp;
        std::cin>>temp;
        array[i] = temp;
    }
}
//EFFECT: Read the information from input file and 
//form the stack and queue.
//MODIFIES: stack, queue, array.


void execute(Stack &stack, Queue &queue, int *array, bool s){
    while(!queue.isEmpty()){
        Instr temp = queue.pop();
        switch (temp.name){
        case InstrName::ADD:{
            stack.push(stack.pop()+stack.pop());
            //pop and add the first two int of stack
            //and push back
            break;
        }
        case InstrName::NOR:{
            stack.push(~(stack.pop()|stack.pop()));
            //pop and calculate the nor of the first
            //two int of stack and push back
            break;
        }
        case InstrName::IFZ:{
            if(stack.pop()==0){
                for(int i=0;i<temp.parameter;i++) queue.pop();
            }
            //pop n elements from stack
            break;
        }
        case InstrName::HALT:{
            if(s){
                std::cout<<stack<<"\n";
                for(int i=0;i<memory_size;i++){
                    std::cout<<array[i]<<" ";
                }
                std::cout<<std::endl;
            }
            //close the executing environment
            break;
        }
        case InstrName::LOAD:{
            stack.push(array[stack.pop()]);
            //pop an int as the address of memory
            //and push the int in that address back to stack
            break;
        }
        case InstrName::STORE:{
            int fisrt = stack.pop();
            array[fisrt]=stack.pop();
            //pop first int as the address and pop
            //the second int as the value to be 
            //saved to that address
            break;
        }
        case InstrName::POP:{
            stack.pop();
            //pop an int
            break;
        }
        case InstrName::PUSHI:{
            stack.push(temp.parameter);
            //push the parameter to the stack
            break;
        }
        case InstrName::NOOP:{
            break;
        }
        default:
            break;
        }
        //print the information for each instruction
        if(!s){
            std::cout<<temp<<"\n"<<stack<<"\n"<<queue<<"\n";
            for(int i=0;i<memory_size;i++){
                std::cout<<array[i]<<" ";
            }
            std::cout<<std::endl;
        }
    }
}
//REQUIRE: The queue is not empty.
//EFFECT: Execute all the commands from queue and 
//output the information. If s, the output should 
//be the silent version. Otherwise, it should be
//complete.
//MODIFIES: stack, queue, array

int main(int argc, char *argv[]){
    Stack stack;
    Queue queue;
    int *array = new int[memory_size];

    read_input(stack, queue, array);
    //read the input

    bool s = false;
    if(argc>1){
        std::string str(argv[1]);
        if(str=="-s") s=true;
    }
    execute(stack, queue, array, s);
    delete[] array;
    return 0;
}
