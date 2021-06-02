# Interpreter
##### Interpreter for the nonya programming language

We’ll use 2 language tools: Lex and Yacc (or flex and bison) to accomplish this.

## The LEX file

The lex file has 3 main parts, separated by “double percentage signs”. The first part is a list of harder files and function definitions encapsulated in “percentage-curly braces”. The second part has the list of acceptable tokens and the final is for some C user defined functions.

`y.tab.h` is generated by Yacc and it defines the list of tokens that we mention here.

In the next section, we start by defining datatype tokens. Although struct can be considered a datatype token, we considered it as a `STRUCT` token separately because of its unique syntax. Then we define the single character tokens. We also define character, integer & floating point values. From here, we start getting more generic to Array_identifiers, identifiers and strings. When a linefeed character (`\n` in this case) is encountered, `yylineno` is incremented. `yylineno` keeps track of the line number in the input C file. We just ignore any other token.

How this works is that. The token encountered is stored in a variable called `yytext`. It is compared with these list of acceptable token formats from top to bottom. The first time it finds a match, the corresponding code on the right hand side is executed. If,say we encounter the token “int”, this is stored in `yytext` and matched up against the token list. Since it is present in the beginning itself, the corresponding C code in curly braces is executed. Here, “int” is stored in `yylval`. `yylval` is required to pass tokens recognized from the Lexer to the parser. So, this variable `yylval` is considered the bridge between the two. You only need to pass values through `yylval` if you plan to use the value in the parser. For other tokens, you don't need to worry about it.  And this “dataType” could have been anything else, like “string_value” or “blah_blah”. I used dataType because it just makes sense to me.  

In the 3rd and final section, we have a implemented a few functions. `yywrap` is called when the End of input file is reached. It returns 1 to signal the end of input, which is true for our case as we input 1 file at a time. `yyerror` is invoked when an invalid token or sequence is encountered. It takes in the error string as input and we display the line number and error message just like you would see in a compiler. I also defined an `InvalidToken` function to catch stray tokens in case they don't invoke `yyerror`.  This may not be the most efficient way to define to tokens or write function, but its not half bad.


## The YACC file

Like the lex file, this also consists of 3 sections. The first part is a list of harder files and function definitions encapsulated in “percentage-curly braces”. After that, we declare a number of datatypes and functions. If “extern” precedes their declaration, then those variables or those functions are actually defined externally. that is, not in this file. In between the first and second sections, we define the nature of the error message generated by YACC. 

- `%union` allows us to define the members of yylval.  yylval is actually of type “union”. 

- `%token` is used to define the tokens passed from the lex file. If the value of the token is passed, be sure to indicate the type in angular brackets  . 

- `%type` is used to define the symbols used below that are not tokens passed from the lex file. They are a combination of those tokens.

Everything mentioned here was between the 1st and 2nd section. Now lets take a look at the 2nd section, which is the meat of this file, if not the entire application. It is here that we define the Grammar for our language, which is C in our case.

Since we are dealing with declaration statements, it makes sense to make this “Declaration” the root of the tree. Every statement in our input C files must be a declaration statement of one of the following forms mentioned. If the statement does not conform to any of these froms, then `yyerror` is invoked and this angular bracket stops execution. 

Since it stops checking for errors after the first is encountered, I guess its more like an interpreter than a compiler. 

In the third section, we have a main function which is the starting point of exectution. Here, we call `yyparse()` which initiates all the tokenismg and parsing discussed until now. Its an amazing function. Since the program stops on encountering an error, yyparse will only return if no errors are found. So its safe to say that if a program reaches this point, there are no errors in the input C file. 

## Header Files

### langFunctions.h

Data_Type : character array that holds the data_type for the current declaration statement.
noOfIdentifiers : number of identifiers in the input file.

clearBuffers() : to clear the value of the datatype stored.
storeDataType() : to store the datatype of the current declaration statement.
retrieveDataType(): Created to make things look uniform.
isDuplicate() : checks if the newly encountered identifier has already been declared before.
extractIdentifier() : extracts the name of the array.
storeIdentifier() : add the encountered identifier to the list of identifiers.
AssignmentError() is called in case an invalid assignment is made 
DuplicateIdentifierError() is called if the isDuplicate() function returns True in the yacc file.

### validators.h

isValidAssignment() :  checks if the datatype which we pass in from the later part of the yacc file is the same as the current datatype of the identifier. 

itoa, ftoa and ctoa are used to convert integers, floating point numbers and characters into ascii type. 


## Generate output without GUI

To execute this code, Go to your terminal, enter your working directory and type 4 commands.
```
$ yacc -d syntax2.y
$ lex semantics.l
$ cc lex.yy.c y.tab.c -o output
$ ./output < sample
```

## The Java GUI

This project will have 3 classes:
- `SSMain` — that contains the main function
- `MyFrame` — creates the window frame, the file chooser and the rest of the UI
- `Listener`-  which listens to mouse events and perform the execution of the “output” file

Take the output file generated from the compilation of `lex.yy.c` and `y.tab.c` and put it in our project directory, on the sample level as the source folder. Before I move any further, I’ll just gloss over the 2 main classes here : `MyFrame` and `Listener`.

Myframe extends the JFrame class and inherits its properties and methods.

- JPanel to give a nice background to the app.
- JScrollPane will be used to display the error message.
- JLabel is used to display text. We will use it to display the full path of the sample file chosen, on the botton and other places where text is required.
- JButton is used to create the file chooser button. 

In our constructor, we set the initial size of the window to be 500 by 500 pixels. We then instantiate all the elements I just discussed. In the `createGUI()` method , the components are added and positioned on the screen. At the end of the method, we add a mouse listener for the `JButton` we created. The “listener” is actually the `Listener` Class, which I’ll explain now.

Listener handles 3 major mouse events.
1. a Mouse Click event
2. a Mouse Enter event 
3. a mouse exit event

When the “Choose File” button is clicked, a file chooser opens up where the user selects their sample file. Once the file is chosen, we execute the typical output command that we use in the terminal in the last video . The response is stored in the message variable and displayed on the screen for the user. 

`setBorderColor()` method creates a red border and text if an error is displayed. Otherwise, the text and border color are both green. The other 2 mouse events are just used to give a hover effect on the “choose” button for a nice UI. And that all code for the GUI. Now, lets run thing with 4 sample files. 


### Run Program

If you want to execute this program on command line, go to your terminal and enter your project directory. and enter the `src` folder. Since our main class SSMain is in the package p, we compile it with the command
```
$ javac p/SSMain.java
```

This will generate the corresponding class files. Now, execute it with the command
```
$ java p.SSMain 
```

And clearly, everything works the same even without eclipse. So, this will certainly come in useful for people who think eclipse, netbeans or any other java specific IDE is too slow.
