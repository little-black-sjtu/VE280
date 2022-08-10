#include "image.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef unsigned char (*Agg)(const unsigned char values[2*S+1][2*S+1]);

//Two io functions;
void readImage(istream &is, Image &imI);
void writeImage(ostream &os, const Image &imI);

//Four transformation functions;
void verticalFlip(const Image &imI, Image &imJ);
void rotate90(const Image &imI, Image &imJ);
void intensityInversion(const Image &imI, Image &imJ);
void filter(const Image &imI, Image &imJ, Agg f);

//Three filer functions;
unsigned char maxFilter(const unsigned char values[2*S+1][2*S+1]);
unsigned char meanFilter(const unsigned char values[2*S+1][2*S+1]);;
unsigned char medianFilter(const unsigned char values[2*S+1][2*S+1]);

//Function of check options;
bool checkOptions(const int argc, char *argv[], string &input_file, string &output_file, string &trans_type, bool &cin_flag, bool &cout_flag);
bool checkFileName(const string input_file);

int main(int argc, char *argv[]){
    string input_file, output_file, trans_type;
    bool cin_flag=0, cout_flag=0;
    if(checkOptions(argc, argv, input_file, output_file, trans_type, cin_flag, cout_flag)){
        cout<<HELP_MESSAGE<<endl;
        exit(0);
    }
    else{
        Image imI;
        Image imJ;
        if(cin_flag){
            ifstream ifs(input_file, ios_base::out|ios_base::binary);
            if(!ifs){
                cout<<FILE_NOT_EXIST_ERROR<<endl;
                exit(0);
            }
            if(!checkFileName(input_file)){
                cout<<FILE_TYPE_ERROR<<endl;
                exit(0);
            } 
            readImage(ifs, imI); 
            ifs.close();
        }
        else
            readImage(cin, imI);
        if(trans_type=="verticalFlip")
            verticalFlip(imI,imJ);
        else if(trans_type=="rotate90")
            rotate90(imI,imJ);
        else if(trans_type=="intensityInversion")
            intensityInversion(imI,imJ);
        else if(trans_type=="maxFilter")
            filter(imI,imJ,maxFilter);
        else if(trans_type=="meanFilter")
            filter(imI,imJ,meanFilter);
        else if(trans_type=="medianFilter")
            filter(imI,imJ,medianFilter);
        else{
            cout<<TRANSFORM_ERROR<<endl;
            exit(0);
        }
        if(cout_flag){
            ofstream ofs(output_file, ios_base::out|ios_base::binary);
            writeImage(ofs, imJ);
            ofs.close();
        }
        else
            writeImage(cout, imJ);
    }
    return 0;
}


//Implemention of two io functions
void readImage(istream &is, Image &imI){
    string type;
    string bound;
    is>>type>>imI.w>>imI.h>>bound;
    is.get();
    for (auto j = 0u; j < imI.h; ++j)
        for (auto i = 0u; i < imI.w; ++i){
            char temp;
            is.read(&temp, sizeof(char));   // red
            imI.image[i][j].red = (unsigned char)temp;
		    is.read(&temp, sizeof(char)); // green
            imI.image[i][j].green = (unsigned char)temp;
		    is.read(&temp, sizeof(char));  // blue
            imI.image[i][j].blue = (unsigned char)temp;
        } 
}

void writeImage(ostream &os, const Image &imI){
    os << "P6" << endl << imI.w << ' ' << imI.h << endl << "255" << endl;
    for (auto j = 0u; j < imI.h; ++j)
        for (auto i = 0u; i < imI.w; ++i)
            os << imI.image[i][j].red      // red
		       << imI.image[i][j].green    // green
		       << imI.image[i][j].blue;    // blue
}

//Implemention of four transformation functions
void verticalFlip(const Image &imI, Image &imJ){
    imJ.h = imI.h;
    imJ.w = imI.w;
    for(auto j=0u; j<imJ.h;j++)
        for(auto i=0u; i<imJ.w;i++){
            imJ.image[i][j].red = imI.image[i][imJ.h-j-1].red;
            imJ.image[i][j].green = imI.image[i][imJ.h-j-1].green;
            imJ.image[i][j].blue = imI.image[i][imJ.h-j-1].blue;
    }
}

void rotate90(const Image &imI, Image &imJ){
    imJ.h = imI.w;
    imJ.w = imI.h;
    for(auto j=0u; j<imJ.h;j++)
        for(auto i=0u; i<imJ.w;i++){
            imJ.image[j][i].red = imI.image[i][imI.h-j-1].red;
            imJ.image[j][i].green = imI.image[i][imI.h-j-1].green;
            imJ.image[j][i].blue = imI.image[i][imI.h-j-1].blue;
    }
}

void intensityInversion(const Image &imI, Image &imJ){
    imJ.h = imI.h;
    imJ.w = imI.w;
    for(auto j=0u; j<imJ.h;j++)
        for(auto i=0u; i<imJ.w;i++){
            imJ.image[i][j].red = M-imI.image[i][j].red;
            imJ.image[i][j].green = M-imI.image[i][j].green;
            imJ.image[i][j].blue = M-imI.image[i][j].blue;
    }
}

void filter(const Image &imI, Image &imJ, Agg f){
    imJ.h = imI.h;
    imJ.w = imI.w;
    for(int j=0; j<(int)imJ.h;j++)
        for(int i=0; i<(int)imJ.w;i++){
            unsigned char temp[2*S+1][2*S+1];
            for(auto a=i-S; a<=i+S;a++)
                for(auto b=j-S; b<=j+S; b++){
                    if(a<0||b<0||a>=(int)imI.w||b>=(int)imI.h)
                        temp[a-i+S][b-j+S] = 0;
                    else
                        temp[a-i+S][b-j+S] = imI.image[a][b].red;
                }
            imJ.image[i][j].red = f(temp);
            for(auto a=i-S; a<=i+S;a++)
                for(auto b=j-S; b<=j+S; b++){
                    if(a<0||b<0||a>=(int)imI.w||b>=(int)imI.h)
                        temp[a-i+S][b-j+S] = 0;
                    else
                        temp[a-i+S][b-j+S] = imI.image[a][b].green;
                }
            imJ.image[i][j].green = f(temp);
            for(auto a=i-S; a<=i+S;a++)
                for(auto b=j-S; b<=j+S; b++){
                    if(a<0||b<0||a>=(int)imI.w||b>=(int)imI.h)
                        temp[a-i+S][b-j+S] = 0;
                    else
                        temp[a-i+S][b-j+S] = imI.image[a][b].blue;
                }
            imJ.image[i][j].blue = f(temp);
    }
}


//Implemention of three filter functions.
unsigned char maxFilter(const unsigned char values[2*S+1][2*S+1]){
    unsigned char a = values[0][0];
    for (auto i=0u;i<2*S+1; i++)
        for(auto j=0u;j<2*S+1; j++){
            if (values[i][j]>a)
                a = values[i][j];
        }
    return a;
}

unsigned char meanFilter(const unsigned char values[2*S+1][2*S+1]){
    int sum = 0;
    for (auto i=0u;i<2*S+1; i++)
        for(auto j=0u;j<2*S+1; j++){
            sum = sum+values[i][j];
        }
    return (unsigned char)(sum/((2*S+1)*(2*S+1)));
}

unsigned char medianFilter(const unsigned char values[2*S+1][2*S+1]){
    unsigned char array[(2*S+1)*(2*S+1)];
    for (auto i=0u;i<2*S+1; i++)
        for(auto j=0u;j<2*S+1; j++){
            array[i*(2*S+1)+j] = values[i][j];
        }
    for (auto i=0u;i<(2*S+1)*(2*S+1); i++)
        for(auto j=i+1;j<(2*S+1)*(2*S+1); j++){
            if(array[i]<array[j]){
                unsigned char temp = array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    return array[((2*S+1)*(2*S+1)-1)/2];
}

//Implemention of check function.
bool checkOptions(const int argc, char *argv[], string &input_file, string &output_file, string &trans_type, bool &cin_flag, bool &cout_flag){
    bool ishelp = false;
    for(int i=1;i<argc;i++){
        string test(argv[i]);
        if(test=="-t")
            trans_type = argv[i+1];
        if(test=="-i"){
            input_file = argv[i+1];
            cin_flag = true;
            }
        if(test=="-o"){
            output_file = argv[i+1];
            cout_flag = true;
            }
        if(test=="-h"||test=="--help")
            ishelp = true;
    }
    return ishelp;
}

bool checkFileName(const string input_file){
    if (input_file.length()<4)
        return false;   
    string suffixStr = input_file.substr(input_file.length()-4);
    return (suffixStr==".ppm");
}

