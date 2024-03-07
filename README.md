# Base_statistic_operations
Reads text file with numbers and gives: highest and lowest values, median and avarage value, biggest sequences of growing and decreasing numbers

##### Compilation
To use a program you simply need to compile it via c++ compiler. For example gcc is one of the most common and free compilers.

For Red Head distributives family of Linux we use dnf package mannager to install compiler (gcc) and module to compile c++ files (gcc-c++):
- dnf install gcc gcc-c++

	*You can use any c++ compiler on any system that supports it.

After installation we simply compile it by command g++:
- g++ /path/to/file/main.cpp -o /path/to/executable/findNums

	/path/to/file - is a path where main.cpp file is located you can write a full path or a relative
	/path/to/executable - is a path where our program will be placed, because it`s very simple it will be a one executable file

##### Execution

**After compilation** we can start our program:
- path/to/executable/findNums /path/to/file/fileWithNumbers

	if you don't specify "/path/to/file/fileWithNumbers" then program will search for "10m.txt" file in the same directory where it's located
	(this is because the purpose of making this program was reading data from 70MB "10m.txt" file)

*it is important to remember that program correctly reads data from text files of a SPECIFIC FORMAT.
	- every number is starting from a new line
	- numbers must start of '-' if it's negative and from first number if it's positive
	- you CAN'T use words and other symbols because the output will be UNPREDICTABLE and most likely INCORRECT
