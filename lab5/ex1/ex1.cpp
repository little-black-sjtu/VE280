#include "ex1.h"

using namespace std;

static list_t reverse(list_t list){
	list_t new_list = list_make();
	while(!list_isEmpty(list)){
		int elt = list_first(list);
		new_list = list_make(elt, new_list);
		list = list_rest(list);
	}
	return new_list;
}

static bool is_palindrome_list_help(list_t list, list_t comp_list){
	if(list_isEmpty(list))
		return true;
	if(list_first(comp_list) != list_first(list))
		return false;
	else return is_palindrome_list_help(list_rest(list), list_rest(comp_list));
	// TODO: implement is_palindrome_list function
}

int dot(list_t v1, list_t v2){
	if(!list_isEmpty(v1)&&!list_isEmpty(v2)){
		return list_first(v1)*list_first(v2)+dot(list_rest(v1),list_rest(v2));
	}
	else 
		return 0;
	// TODO: implement dot function
}

list_t filter(list_t list, bool (*fn)(int)){
	list_t new_list = list_make();
	while(!list_isEmpty(list)){
		int elt = list_first(list);
		if(fn(elt))
			new_list = list_make(elt, new_list);
		list = list_rest(list);
	}
	new_list = reverse(new_list);
	return new_list;
	// TODO: implement filter function
}

bool is_palindrome_list(list_t list){
	return is_palindrome_list_help(list, reverse(list));
	// TODO: implement is_palindrome_list function
}

