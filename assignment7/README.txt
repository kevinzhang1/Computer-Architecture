Name: Kevin Zhang
Email Address: Kevin_Zhang@student.uml.edu

The output.txt file shows the resulting output from the project.

Overall I was able to finish the whole project pretty much. It was easier than most of the other assignments and the professor has already given the source code for a lot of the assignment.

This assignment requires me to write a program that reports a collection of process and thread information about itself, create an unnamed pipe, and create a child process that will inherit access to the unnamed pipe. The child process is supposed to read the parent's string from the pipe and write it to the standard output. It will then get the parent process ID and write it to the standard output and then do a normal exit.

Overall, the main idea of the program should be working where it prints out the required output. However, that doesn't mean that I can say with 100% certainty that this program is working completely according to standards. When I was running the program, sometimes even after it prints the goodbye message the program still wouldn't stop running. I have to manually terminate the program with ctrl-c to fully stop the program. In addition, for some reason, when I do ./a7>output.txt, it always shows the parent process report twice for some reason. Because of these errors, I can say it is only working with 96% completeness, though there could be other errors that I left out accidentally or other glitches that I haven't discovered yet.