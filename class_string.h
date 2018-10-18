#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <stdlib.h>
#endif

typedef struct _c_string
{
	char* text;

	void (*read)(struct _c_string*, char);
	void (*print)(struct _c_string*, char);
	void (*tolower)(struct _c_string*);
	void (*toupper)(struct _c_string*);
	char (*at)(struct _c_string*, int pos);
	long (*size)(struct _c_string*);
	unsigned short (*strcmp)(struct _c_string*, struct _c_string*);
	unsigned short (*stricmp)(struct _c_string*, struct _c_string*);
	void (*concat)(struct _c_string*, struct _c_string*);
	void (*shrink_to_fit)(struct _c_string*);
	void (*clear)(struct _c_string*);

	long size_string;
	long alloc_size;
	double charge_factor;
}string;

void _string_desconstructor_func(string*);
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
string newString();

void deleteString(string* _string_)
{
	free(_string_->text);
	_string_->size_string = 0;
	_string_->alloc_size = 0;
	_string_->charge_factor = 0;
	free(_string_);
}

void _string_concat_func(string* _stringconcat_, string* _stringtoconcat_)
{
	long size = _stringtoconcat_->size_string;
	long old_size = _stringconcat_->size_string;
	int k = 0, i;

	_stringconcat_->charge_factor = (double)(size + old_size)/ _stringconcat_->alloc_size;

	while(_stringconcat_->charge_factor >= 0.5)
	{

		_stringconcat_->alloc_size = (_stringconcat_->alloc_size * 2 );
		_stringconcat_->text = (char*)realloc(_stringconcat_->text, _stringconcat_->alloc_size * sizeof(char));
			
		_stringconcat_->charge_factor = (double)(size + old_size)/ _stringconcat_->alloc_size; 
	}

	_stringconcat_->size_string = size + old_size;
	size_t sizs = size + old_size;

	for(i = old_size; i < sizs; i++, k++)
		_stringconcat_->text[i] = _stringtoconcat_->text[k];
}

unsigned short _string_compare_func(string* string_, string* _string)
{
	if(string_->size_string != _string->size_string)
		return 0;
	else
	{
		long i = 0, j = string_->size_string;
		while(j > i)
		{
			if(string_->text[i] != _string->text[i] || string_->text[j] != _string->text[j])
				return 0;
			i++;
			j--;
		}
		return 1;
	}
}

void _string_read_func(string* _string_, char end_parameter)
{
	char buffer;
	unsigned short flag = 1;

	if(end_parameter == 0)
		end_parameter = '\n';

	if(_string_->alloc_size != 0)
		free(_string_->text);

	do
	{
		buffer = getchar();
		if(buffer != end_parameter)
		{
			if(flag)
			{
				_string_->text = (char*)calloc(5, sizeof(char));
				_string_->alloc_size = 5;
				if(_string_->text == NULL)
				{
					printf("BAD ALLOCATION\n");
					exit(0);
				}
				_string_->text[_string_->size_string] = buffer;
				_string_->size_string++;

				flag = 0;
			}
			else
			{
				_string_->charge_factor = (double)_string_->size_string / _string_->alloc_size;
				if(_string_->charge_factor >= 0.5)
				{
					_string_->alloc_size = (_string_->alloc_size * 2 );
					_string_->text = (char*)realloc(_string_->text, _string_->alloc_size * sizeof(char));
				}
				_string_->text[_string_->size_string] = buffer;
				_string_->size_string++;
			}
		}
	}while(buffer != end_parameter);
}

void _string_set_tolower(string* _string_)
{
	int i = 0;
	for(i = 0; i < _string_->size_string; i++)
		if(_string_->text[i] >= 65 && _string_->text[i] <= 90)
			_string_->text[i] += 32;
}

void _string_set_toupper(string* _string_)
{
	int i = 0;
	for(i = 0; i < _string_->size_string; i++)
		if(_string_->text[i] >= 97 && _string_->text[i] <= 122)
			_string_->text[i] -= 32;
}

long _string_return_size(string* _string_)
{

	return _string_->size_string;
}

void _string_print_func(string* _string_, char end_parameter)
{
	int i = 0;
	for(i = 0; i < _string_->size_string; i++)
		printf("%c", _string_->text[i]);
	printf("%c", end_parameter);
}

unsigned short _string_compare_sensitive_case_func(string* _string, string* string_)
{
	string x = newString();
	string y = newString();
	int boolean;

	x.text = _string->text;
	y.text = string_->text;

	x.tolower(&x);
	y.tolower(&x);

	boolean = x.strcmp(&x, &y);

	deleteString(&x);
	deleteString(&y);
	
	return boolean;
}

void _string_shrink_to_fit_func(string* _string_)
{
	if(_string_->text != NULL)
	{
		_string_->text = (char*)realloc(_string_->text, _string_->size_string * sizeof(char));
		_string_->alloc_size = _string_->size_string;
	}
}

char _string_at_func(string* _string_, int pos)
{
	if(pos > _string_->size_string)
		return 0;
	else
		return _string_->text[pos];
}

void _string_clear_func(string* _string_)
{
	long i = 0, j = _string_->size_string;
	while(j > i)
	{
		_string_->text[i] = 0;
		_string_->text[j] = 0;

		i++;
		j--;
	}
	_string_->size_string = 0;
	_string_->alloc_size = 0;
}

string newString()
{
	string* _string_ = (string*)malloc(sizeof(struct _c_string));

	_string_->read = _string_read_func;
	_string_->size = _string_return_size;
	_string_->print = _string_print_func;
	_string_->tolower = _string_set_tolower;
	_string_->toupper = _string_set_toupper;
	_string_->concat = _string_concat_func;
	_string_->strcmp = _string_compare_func;
	_string_->stricmp = _string_compare_sensitive_case_func;
	_string_->shrink_to_fit = _string_shrink_to_fit_func;
	_string_->at = _string_at_func;
	_string_->clear = _string_clear_func;
	_string_->alloc_size = 0;
	_string_->size_string = 0; 
	_string_->charge_factor = 0;

	return *_string_;
}
