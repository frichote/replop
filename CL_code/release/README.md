Description
-----------
The goal of this directory is to provide scripts to build realeases of the programs given current versions of the documentation, the examples and the source files.

There is a directory by program:
* sNMF: a command-line program.
* LFMM: a command-line program.
* LEA: a R package.

Organization 
------------
Each directory is composed of:
* a script called "create_XXX_release.sh", where XXX is the name of the program. This script gathers the informations and create a new compressed releasable version of the program. The command is "sh create_XXX_release.sh version" where version is the number of the version.
* a directry meta. This directory contains the constant base of the release.

Do not forget to update the README files when a new releasable version is created.
