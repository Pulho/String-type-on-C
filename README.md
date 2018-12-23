# Welcome to String " Class" on C !

  First of all, this was my first experiment with void pointers and pointers to functions. I hope that is useful for some purpose of someone. This work is still in progress and development.

  Second, just explaining, **C language don't really have object**. So this code is not really a class, resembling more a simulation of a class object, and if you ask me if it's safe to use it on any system I'd say no haha but i'm still testing and optimizing to be feasible one day, still testing. So, be kind :D

# Special Recognition
  I want to thank my friend [Marcos Heitor](https://github.com/mhco0)  for having helped me understand the operation of void pointers and pointer to function, thus enabling the execution of creating this code.
  
# :books: How it works ?
  Let's see how a basic code works and i'll explain in your due time.
  
```C++
    int main(int argc, char const *argv[]){
        string x = newString();
        
       // (YOUR CODE)   
        
        destroyString(&x);
    }
```  
 If you didn't understand, calm down and breathe, i'll explain right about now.
 So, as you can see, we create a variable called 'x' of the type "string". Then, before we can use it as a object, we have to set all the pointers that this variable contains. That's why we use `string x = newString()`. This way, the `newString();` function will do all the dirty work to set all pointers and variables inside of our struct.
  If you're familiar with constructor and 'new' stuffs, you should know that you will need to use the`deleteString(&x)` to release memory.
  
# :pencil: Functions and their parameters !

Note: Still it is necessary to send the address of the structure (Ex.: x.read(&x,0), as you can see, we must send '&x' as parameter even though we're using the function of the class of that same variable)

### :computer: Non-object functions
Non-object Functions   | Information
------------| -------------
newString(void) | Set pointers
destroyString(string*) | Release memory

### :computer: Object functions
Object functions  | Information
------------| -------------
.read(string*, char)   | Read string until the 'char' is read ( 0 for Enter as Default ). Overwrites the current contents if not empty
.size(string*)  | Return the size of the string
.clear(string*) | Clear the content of the string
.at(string*, int) | Return the char at the pos if pos exist, besides return 0;
.assign(string*, char*) | Assign the string to the input text;
.print(string*, char) | Print string and put the 'char' in the end (0 for no char and '\n' for newline)
.toupper(string*) | Set the string to uppercase
.tolower(string*) | Set string to to lowercase 
.strcmp(string*, string*) | Compare strings ( with sensitive case. Returns a boolean )
.stricmp(string*, string*) | Compare strings ignoring sensitive case ( Returns a boolean )
.concat(string*, string*)  | Concat to the first input string
.shrink_to_fit(string*) | Decreases the capacity of the string and makes it equal to its size
