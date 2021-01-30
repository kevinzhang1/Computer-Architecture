Name: Kevin Zhang
Email Address: Kevin_Zhang@student.uml.edu

The program works by typing "make" in order to activate the makefile. The program reads from a text file called input.txt and puts the outputs into TA_output.txt. The my_output.txt file is my annotated text file. Use the run executable if you want to input your own test numbers.

Overall, I feel that my degree of success with this project is a 95% completion. This is because I finished the assignment with the code completely working with the required inputs. However, when I tested inputs like 3 and 4, the emulated output show something completely different than the hardware input.

In this assignment, I am required to scan 2 floating point numbers. The program is supposed to out the original bit patterns of both floats along with bit pattern of result from emulation calculation. It is then supposed to print out both the hardware float result and emulation float result and then start over from the beginning until user enters invalid input like letters. 

After I read and fully understood the instructions, it was time to proceed with developing the program. The hardest and most difficult step of doing this project is figuring out how to get started. This was a very hard project. First I had to figure out how exactly this emulated addition works in the first place, then I had develop a c program that calculates it while navigating the float_32 union. However, eventually after many hardships, I got the program to produce the right outputs for the given inputs. The program still produces errors if you type some random inputs in but at least for the assigned inputs the outputs seem to be correct.