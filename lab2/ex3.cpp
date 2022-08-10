#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct {
    // TODO: complete struct
    char name[16];
    int Cscore;
    int Mscore;
    int Escore;
} Student;

int compare(const void* p1, const void* p2) {
    // TODO: complete compare function for qsort()
    return -(((Student *)p1)->Cscore-((Student *)p2)->Cscore\
    +((Student *)p1)->Mscore-((Student *)p2)->Mscore\
    +((Student *)p1)->Escore-((Student *)p2)->Escore);
}

void print_result(Student students[], int size){
    for(int i=0;i<size;i++){
        cout<<students[i].name<<" "<<students[i].Cscore<<" "\
        <<students[i].Mscore<<" "<<students[i].Escore<<endl;
    }
}

int main() {
    // TODO: read input
    int size;
    cin>>size;
    Student students[size];
    for(int i=0;i<size;i++){
        cin>>students[i].name>>students[i].Cscore>>students[i].Mscore\
        >>students[i].Escore;
    }
    // TODO: sort array with qsort()
    qsort(students, size, sizeof(Student),compare);
    // TODO: print result
    print_result(students, size);
    return 0;
}