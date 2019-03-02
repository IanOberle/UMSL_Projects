*Notes for file statistics project*

I noticed that because of the way I have executables set up for my 
shell profile (.bashrc) using an executable called "wc" would cause to 
built-in shell (Linux) command "wc" to be used instead of my executable file.
I have included a alternative named executable, "wc2"  in my makefile, 
just in case this happens when you run my code. I also have the regularly 
named "wc" executable file in my makefile, as your instructions specify. 


*Notes for account management system project*

I am fairly certain I have taken care of the segmentation fault errors
,but there may still be one or two in my code. Every thing for this project
compiles and runs. I have been able to run each function and have checked to
make sure each function does what your instruction specify. 
If a segmentation fault error occurs the best way around it, that I have seen,
is to run the program and have the "balance inquiry" function be the 
first called function. This seems to prevent segmentation fault 
errors from occurring, in regard to if they have previously occurred.

Also, I have filled my "accounts.dat" file with at least 7 accounts. In the
event this file is empty when you view it, I have included an exectuable
file, "default", in my makefile to fill the .dat file with 7 accounts.
