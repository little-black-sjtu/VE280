#include <string>
#include <cstring>
#include <iostream>
const std::string help_message("Hey, I love Integers.");
const std::string add_message("This is add operation.");
const std::string small_message("This is small operation.");
const std::string no_op_message("No work to do!");
bool Op_Flag[4] = {false};

int check_op(char *argv[],int argc)
{
	int small_num = -1;
	for(int i=1;i<argc;i++){
		if(!strcmp(argv[i],"--help"))
			Op_Flag[0]=true;
		if(!strcmp(argv[i],"--add"))
			Op_Flag[1]=true;
		if(!strcmp(argv[i],"--small")){
			Op_Flag[2]=true;
			small_num = std::stoi(argv[i+1]);
		}
		if(!strcmp(argv[i],"--verbose"))
			Op_Flag[3]=true;
	}
	return small_num;
}

int find_smallest(int count,int arr[]){
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i]=arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr[0];
}
int main(int argc, char *argv[]) {
	//TODO write your code here
	int small_num=check_op(argv,argc);
	int count;
	std::cin>>count;
	int arr[count];
	for(int i=0;i<count;i++){
		std::cin>>arr[i];
	}
	if (Op_Flag[0])
		std::cout<<help_message<<std::endl;
	else{
		if(Op_Flag[1]){
			int sum=0;
			for(int i=0;i<count;i++) sum+=arr[i];
			if(Op_Flag[3])
				std::cout<<add_message<<std::endl;
			std::cout<<sum<<std::endl;
		}
		if(Op_Flag[2]){
			if(Op_Flag[3])
				std::cout<<small_message<<std::endl;
			std::cout<<find_smallest(count,arr)+small_num<<std::endl;
		}
	}
	if(!(Op_Flag[0]||Op_Flag[1]||Op_Flag[2]))
		std::cout<<no_op_message<<std::endl;
	return 0;
}