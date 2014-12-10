Description
-----------
This directory contains all the C files, and docs.

Organization
------------
The directory is organized as follows:

* bin: binary executable files.
* docs: doxygen configuration files. To compute to documentation, type "make doc", open it with you browser "firefox docs/html/index.html".
* lib: binary lapack library directory.
* obj: object files directory. The obj files are divided in subdirectories to order the code.
* src: source files directory. The src files are divided in subdirectories to order the code.
* test: test files directory.
* Makefile: to compile the package, we provide a makefile. To compile all the package, type "make". 

There is a debug mode for LFMM (see the makefile). It writes the current value 
of each matrice in a file called with the name of the variable and it prints the current value 
of each alpha*.

