# GCO
## - A simple helper for g++ compilations -

This project is still in the works, but the goal is to provide a simplified alternative to CMake. The project is currently in a starting stage, but will eventually grow into a bigger program.



## **Usage:**

You should have a file called 
`NAME.gco`
and you invoke it with
`gco NAME.gco`

This will attempt to parse the file and run compilations done to the users liking.


## SEMICOLONS (;) at the end of lines are required.



### ***g++/gcc is a required dependency***

****

### Commands:

****
## `co`

  Compiles a provided file to an object file. (g++)


 
  **Example (FILE.gco):**
```
 >  co INPUTFILE OUTPUTFILE;
```

****

****
## `g++`

  Runs the g++ command with the specified arguments regularly. (g++)


 
  **Example (FILE.gco):**
```
 >  g++ -o OUTPUTFILE.exe INPUTFILE.cpp;
```

****

****
## `gcc`

  Runs the gcc command with the specified arguments regularly. (gcc)


 
  **Example (FILE.gco):**
```
 >  gcc -o OUTPUTFILE.exe INPUTFILE.c;
```

****

****
## `IF`

  So far, the IF statement cannot be nested inside of other IF statements.
  IF statements can check for directories or files.

  This example will query for a directory from the active directory.
  You can use `IF DIR` or `IF FILE` whether you want to query for a file or directory.
  **Example (FILE.gco):**
```
 >  IF DIR src;
 >  co INPUTFILE OUTPUTFILE;
 >  ENDIF;
```

****
