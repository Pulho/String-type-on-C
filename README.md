# Welcome to String " Class" on C !

  First of all, this was my first experiment with void pointers and pointers to functions. I hope that is useful for some purpose of someone. This work is still in progress and development.

  Second, just explaining, **C language don't really have object**. So this code is not really a class, resembling more a simulation of a class object. So, be kind :D

# Special Recognition
  I want to thank my friend Marcos Heitor (https://github.com/mhco0)  for having helped me understand the operation of void pointers and pointer to function, thus enabling the execution of creating this code.
  
# How it works ?
  Let's see how a basic code works and i'll explain in your due time.
  
```C++
     int main()
      {
        string x;

        x.constructor = string_pointers;
        x.constructor(&x);
        x.desconstructor(&x);
      }
```  
 If you didn't understand, calm down and breathe, i'll explain right about now.
 So, as you can see, we create a variable of the type "string". Then, before we can use it as a object, we have to set all the pointers that this variable contains. That's why we use `.constructor = string_pointers`. This way, `.constructor(&*);` will point for a function ( string_pointers ) that will do all the dirt work to set all pointers and variables inside of our struct.
  If you're familiar with constructor, you should know that you will need to use the`.desconstructor(&*)` to release memory.
  
# Functions and their parameters !

*		.constructor(string*); // Set pointers
*		.read(string*, char); // Read string until the 'char' is read ( 0 for Enter as Default ). Works as a clear too
*		.size(string*); // Return the size of the string
*		.print(string*, char); // Print string and put the 'char' in the end (0 for no char and '\n' for newline)
*		.toupper(string*); // Set the string to uppercase
*		.tolower(string*); // Set string to to lowercase 
*		.strcmp(string*, string*); // Compare strings ( with sensitive case. Returns a boolean )
*		.stricmp(string*, string*); // Compare strings ignoring sensitive case ( Returns a boolean )
*		.concat(string*, string*);  // Concat to the first input string
*   	.shrink_to_fit(string*); // Decreases the capacity of the string and makes it equal to its size
*		.desconstructor(string*); // Release memory


