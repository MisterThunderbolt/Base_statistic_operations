#include <iostream>
#include <fstream>
#include <vector>

#include <string>
#include <algorithm>


int main(int argc, char* argv[])
{
	//Reading a file path from the first argument, the default will be ./10m.txt
	std::string filePath = { "./10m.txt" };
	if (argv[1] != 0) { filePath = argv[1]; }

	//Openning a file
	std::ifstream readFile(filePath);

	//Creating a vector for every number in the file and a variable for their amount (usefull for conditions of circles)
	std::vector<int64_t> numbersVector;
	unsigned int numberOfNumbers = { 0 };

	//Checking if file is opened (if not - writing an error and exiting program with 1)
	//After inizializing "numbersVector" and "numberOfNumbers" in a circle of reading lines from file
	{
		if (readFile.is_open())
		{
			std::cout << "Reading data from file " << filePath << std::endl;
			std::string line;
			while (getline(readFile, line))
			{
				numbersVector.push_back(strtol(line.c_str(), 0, 0));
				++numberOfNumbers;
			}
		}
		else
		{
			std::cerr << "Cannot open file " << filePath << std::endl;
			return 1;
		}
	}

	// Then we will find growing and decreasing sequences in the vector
	std::string growthSequence;
	std::string decreaseSequence;

	{
		//We will use "i" as an iterator to check every number in the vector
		//"currentSequenceStart" and "currentSequenceLenght" to check every sequence on the way
		//"isInSequense" to rewrite new sequences to "currentSequenceStart" and "currentSequenceLenght"
		//"growthSequenceStart" and "growthSequenceLenght" to store values of the biggest sequence
		
		unsigned int growthSequenceStart = {0};
		unsigned int growthSequenceLenght = {0};
		{
			bool isInSequense = {true};
			unsigned int currentSequenceStart = { 0 };
			unsigned int currentSequenceLenght = { 0 };

			for (unsigned int i = {1}; i < numberOfNumbers; i++)
			{
				if (numbersVector.at(i) > numbersVector.at(i - 1))
				{
					if (isInSequense) { currentSequenceLenght++; }
					else 
					{
						currentSequenceStart = i - 1;
						currentSequenceLenght = 1;
						isInSequense = true;
					}
				}
				else 
				{ 
					isInSequense = false;
					if (currentSequenceLenght > growthSequenceLenght)
					{
						growthSequenceStart = currentSequenceStart;
						growthSequenceLenght = currentSequenceLenght;
					}
				}
			}

			if (currentSequenceLenght > growthSequenceLenght)
			{
				growthSequenceStart = currentSequenceStart;
				growthSequenceLenght = currentSequenceLenght;
			}
		}

		//After finding the sequence we will write numbers from vector to our string

		{
			for (unsigned int i = { 0 }; i <= growthSequenceLenght; i++) 
			{
				growthSequence += std::to_string(numbersVector.at(growthSequenceStart + i));
				if (i != growthSequenceLenght) { growthSequence += ", "; };
			}

		}

		//The same as for "growthSequence", but:
		//Instead of using "growthSequenceStart" and "growthSequenceLenght" we use "decreaseSequenceStart" and "decreaseSequenceLenght"

		unsigned int decreaseSequenceStart = { 0 };
		unsigned int decreaseSequenceLenght = { 0 };
		{
			bool isInSequense = { true };
			unsigned int currentSequenceStart = { 0 };
			unsigned int currentSequenceLenght = { 0 };

			for (unsigned int i = { 1 }; i < numberOfNumbers; i++)
			{
				if (numbersVector.at(i) < numbersVector.at(i - 1))
				{
					if (isInSequense) { currentSequenceLenght++; }
					else 
					{ 
						currentSequenceStart = i - 1; 
						currentSequenceLenght = 1;
						isInSequense = true;
					}
				}
				else
				{
					isInSequense = false;
					if (currentSequenceLenght > growthSequenceLenght)
					{
						decreaseSequenceStart = currentSequenceStart;
						decreaseSequenceLenght = currentSequenceLenght;
					}
				}
			}

			if (currentSequenceLenght > growthSequenceLenght)
			{
				decreaseSequenceStart = currentSequenceStart;
				decreaseSequenceLenght = currentSequenceLenght;
			}
		}

		//The same writing as growth sequence, but decrease variables

		{
			for (unsigned int i = { 0 }; i <= decreaseSequenceLenght; i++)
			{
				decreaseSequence += std::to_string(numbersVector.at(decreaseSequenceStart + i));
				if (i != decreaseSequenceLenght) { decreaseSequence += ", "; };
			}

		}
	}
	//end of finding sequences


	{
		//Sorting the vector to easily find our goal values
		std::sort(numbersVector.begin(), numbersVector.end());
	}

	//Using a circle to find the avarage value. Storing the value in a variable "avarage"
	int64_t avarage = { 0 };
	{
		for (unsigned int i = { 0 }; i < numberOfNumbers; i++)
		{
			avarage += numbersVector.at(i);
		}
		avarage /= numberOfNumbers;
	}

	//Finding median for odd amount of numbers it will be in the middle
	//For even amount it will be the avarage of two middle umbers
	int64_t median = { 0 };
	{
		if (numberOfNumbers % 2)
		{
			median = numbersVector.at(numberOfNumbers / 2);
		}
		else
		{
			median = numbersVector.at(numberOfNumbers / 2 + 1) + numbersVector.at(numberOfNumbers / 2 + 1);
		}
	}


	//Showing all goal values on screen
	{
		std::cout << "\n" << "Maximum value is: " << numbersVector.at(numberOfNumbers - 1) << std::endl;
		std::cout << "Minimum value is: " << numbersVector.at(0) << std::endl;
		std::cout << "Median is: " << median << std::endl;
		std::cout << "Avarage value is: " << avarage << std::endl;


		std::cout << "Largest sequence of growing numbers is: " << growthSequence << std::endl;
		std::cout << "Largest sequence of decreasing numbers is: " << decreaseSequence << std::endl;
	}

	return 0;
}