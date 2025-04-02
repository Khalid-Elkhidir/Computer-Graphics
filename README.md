# How to run
This project utilizes Make build tool for compiling and generation of executables.
To build an executable of each file use `make "filename"` in the terminal and the compilation will take place.
You can then run the output file via `./"filename"` in the terminal.

Make is just a tool to help in the process of compiling and linking of multiple code files to output executables. You can refrain from using it by running the compilation commands directly in the terminal, for that check the contents of the `MakeFile` file in each directroy.

> [!note]
> If you decide to use Make build tool, make sure it is installed in your machine e.g. `make --version` in linux.
> 
> Make sure you have a C/C++ compiler installed in you machine e.g. GCC, CLang, etc. For example for gcc run `gcc --version`  
