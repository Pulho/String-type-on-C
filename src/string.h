#ifndef _STRING_H_
#define _STRING_H_

typedef struct _c_string string;

struct _c_string{
	char* text;

	void (*read)(string*, char);
	void (*print)(string*, char);
	void (*tolower)(string*);
	void (*toupper)(string*);
	char (*at)(string*, int pos);
	long (*size)(string*);
	unsigned short (*strcmp)(string*, string*);
	unsigned short (*stricmp)(string*, string*);
	unsigned short (*constcmp)(string*, char*);
	void (*concat)(string*, string*);
	void (*shrink_to_fit)(string*);
	void (*clear)(string*);
	void (*assign)(string*, char*);

	long size_string;
	long alloc_size;
	double charge_factor;
};

void _string_concat_func(string*, string*);

unsigned short _string_compare_func(string*, string*);

void _string_read_func(string*, char);

void _string_set_tolower(string*);

void _string_set_toupper(string*);

long _string_return_size(string*);

void _string_print_func(string*, char end_parameter);

unsigned short _string_compare_sensitive_case_func(string*, string*);

void _string_shrink_to_fit_func(string*);

char _string_at_func(string*, int);

void _string_clear_func(string*);

unsigned short _string_constcmp_func(string*, char*);

void destroyString(string*);

string newString(void);

#endif /* "String.h" */