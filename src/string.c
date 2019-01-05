#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <stdlib.h>
#endif

#include "string.h"

void _string_concat_func(string* _stringconcat_, string* _stringtoconcat_){
	long size = _stringtoconcat_->size_string;
	long old_size = _stringconcat_->size_string;
	int k = 0, i;

	_stringconcat_->charge_factor = (double)(size + old_size)/ _stringconcat_->alloc_size;

	while(_stringconcat_->charge_factor >= 0.5){

		_stringconcat_->alloc_size = (_stringconcat_->alloc_size * 2 );
		_stringconcat_->text = (char*)realloc(_stringconcat_->text, _stringconcat_->alloc_size * sizeof(char));
			
		_stringconcat_->charge_factor = (double)(size + old_size)/ _stringconcat_->alloc_size; 
	}

	_stringconcat_->size_string = size + old_size;
	size_t sizs = size + old_size;

	for(i = old_size; i < sizs; i++, k++){
		_stringconcat_->text[i] = _stringtoconcat_->text[k];
	}
}

unsigned short _string_compare_func(string* string_, string* _string){
	if(string_->size_string != _string->size_string){
		return 0;
	}else{
		long i = 0, j = string_->size_string;
		while(j > i){
			if(string_->text[i] != _string->text[i] || string_->text[j] != _string->text[j]){
				return 0;
			}

			i++;
			j--;
		}
		return 1;
	}
}

void _string_read_func(string* This, char end_parameter){
	char buffer;
	unsigned short flag = 1;
	fflush(stdin);

	if(end_parameter == 0){
		end_parameter = '\n';
	}

	if(This->alloc_size != 0){
		free(This->text);
	}

	do{
		buffer = getchar();
		if(buffer != end_parameter){
			if(flag){
				This->text = (char*)calloc(5, sizeof(char));
				This->alloc_size = 5;
				if(This->text == NULL){
					printf("BAD ALLOCATION\n");
					exit(0);
				}
				This->text[This->size_string] = buffer;
				This->size_string++;

				flag = 0;
			}else{
				This->charge_factor = (double)This->size_string / This->alloc_size;
				if(This->charge_factor >= 0.5){
					This->alloc_size = (This->alloc_size * 2 );
					This->text = (char*)realloc(This->text, This->alloc_size * sizeof(char));
				}
				This->text[This->size_string] = buffer;
				This->size_string++;
			}
		}
	}while(buffer != end_parameter);
}

void _string_set_tolower(string* This){
	int i = 0;
	for(i = 0; i < This->size_string; i++){
		if(This->text[i] >= 65 && This->text[i] <= 90){
			This->text[i] += 32;
		}
	}
}

void _string_set_toupper(string* This){
	int i = 0;
	for(i = 0; i < This->size_string; i++){
		if(This->text[i] >= 97 && This->text[i] <= 122){
			This->text[i] -= 32;
		}
	}
}

long _string_return_size(string* This){

	return This->size_string;
}

void _string_print_func(string* This, char end_parameter){
	int i = 0;
	for(i = 0; i < This->size_string; i++){
		printf("%c", This->text[i]);
	}
	printf("%c", end_parameter);
}

unsigned short _string_compare_sensitive_case_func(string* _string, string* string_){
	if(string_->size_string != _string->size_string){
		return 0;
	}else{
		long i = 0;

		for(i = 0; i < string_->size_string; i++){
			if(((_string->text[i] >= 65 && _string->text[i] <= 90) ? (_string->text[i] + 32) : (_string->text[i])) != ((string_->text[i] >= 65 && string_->text[i] <= 90) ? (string_->text[i] + 32) : (string_->text[i]))){
				return 0;
			}
		}
		return 1;
	}
}

void _string_shrink_to_fit_func(string* This){
	if(This->text != NULL){
		This->text = (char*)realloc(This->text, This->size_string * sizeof(char));
		This->alloc_size = This->size_string;
	}
}

char _string_at_func(string* This, int pos){
	if(pos > This->size_string){
		return 0;
	}else{
		return This->text[pos];
	}
}

void _string_clear_func(string* This){
	long i = 0, j = This->size_string;
	while(j > i){
		This->text[i] = 0;
		This->text[j] = 0;

		i++;
		j--;
	}
	This->size_string = 0;
	This->alloc_size = 0;
}

void _string_assign_func(string* This, char* text){
	if(!This->text){
		This->alloc_size = 0;
		free(This->text);
	}

	for(This->size_string = 0; text[This->size_string] != '\0'; This->size_string++){
		if(This->size_string == 0){
			This->text = (char*)malloc((This->size_string + 1) * sizeof(char));
			This->text[This->size_string] = text[This->size_string];
		}else{
			This->text = (char*)realloc(This->text, (This->size_string + 1) * sizeof(char));
			This->text[This->size_string] = text[This->size_string];
		}
	}
	This->alloc_size = This->size_string;
}

void destroyString(string* This){
	free(This->text);
	free(This);
}

unsigned short _string_constcmp_func(string* This, char* constInput){
	int length = 0;

	while(constInput[++length] != '\0');

	if(This->size_string != length){
		return 0;
	}else{
		long i = 0, j = This->size_string;
		while(j > i){
			if(This->text[i] != constInput[i] || This->text[j] != constInput[j]){
				return 0;
			}

			i++;
			j--;
		}
		return 1;
	}	
}

string newString(void){
	string* This = (string*)malloc(sizeof(struct _c_string));

	This->read = _string_read_func;
	This->size = _string_return_size;
	This->print = _string_print_func;
	This->tolower = _string_set_tolower;
	This->toupper = _string_set_toupper;
	This->concat = _string_concat_func;
	This->strcmp = _string_compare_func;
	This->stricmp = _string_compare_sensitive_case_func;
	This->shrink_to_fit = _string_shrink_to_fit_func;
	This->at = _string_at_func;
	This->clear = _string_clear_func;
	This->assign = _string_assign_func;
	This->constcmp = _string_constcmp_func;
	This->alloc_size = 0;
	This->size_string = 0; 
	This->charge_factor = 0;

	return *This;
}
