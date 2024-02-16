# GCO
## - A simple helper for g++ compilations

This project is still in the works, but the goal is to provide a simplified alternative to CMake. The project is currently in a starting stage, but will eventually grow into a bigger program.



## **Usage:**

You should have a file called 
`NAME.gco`
and you invoke it with
`gco NAME.gco`

This will attempt to parse the file and run compilations done to the users liking.



### ***g++ is a required dependency***

****

### So far, there are three commands currently:

****
## `co`

  Compiles a provided file to an object file. (g++)


 
  **Example (FILE.gco):**
```
 >  co OUTPUTFILE.o INPUTFILE.cpp
```

****

****
## `g++`

  Runs the g++ command with the specified arguments regularly. (g++)


 
  **Example (FILE.gco):**
```
 >  g++ -o OUTPUTFILE.exe INPUTFILE.cpp
```

****

****
## `gcc`

  Runs the gcc command with the specified arguments regularly. (gcc)


 
  **Example (FILE.gco):**
```
 >  gcc -o OUTPUTFILE.exe INPUTFILE.c
```

****
