#include <iostream>
#include <sstream>
#include <vector>

#pragma region Number Manipulation

/*! \Function This will be used to break the user inputted number into pairs of increasing size, 
*				allowing for the program to figgure the umber of repeating jumbers at a later time. 
*Param One: String - The number inputted at the start of the program.
*/
std::vector<std::string> l_NumberPartitioning(std::string inputNumber)
{
	// Local Variables 

	/*! \var This will be use to hold allof the seperated number segments for passing out this function. */
	std::vector<std::string> l_iListOfNuberPartitions; 

	/*! \var This is the current value which the number will be seperated into, starting with 2, it will form 
	*			pairs of number for example 9999 -> 99, 99 and 99 following that will increase to a separation
	*			value of 3 becoming 999 and 999. 
	*/
	unsigned int l_iCurrentPairing = 1;

	// Processing 

	do
	{
		for (unsigned int i = 0; i < inputNumber.size(); i++)
		{
			// For the current paring add all of the numbers into the vector for later checking. 
			// This will work from parings of 2 to the legnth of the number -1. 

			/*! \var This is the current number being partitioned, once all components have been added 
			*			using the following for loop will be added into the final vector. 
			*/
			std::string l_sNumberToAdd;

			// Add up to th number of paring specified to the number to add 
			for (unsigned int j = 0; j < l_iCurrentPairing; j++)
			{
				if (i + l_iCurrentPairing <= inputNumber.size())
				{
					l_sNumberToAdd.push_back(inputNumber[i + j]);
				}
				else
				{
					break;
				}
			}

			// Cut out all of the number of size 1 or less. 
			if (l_sNumberToAdd.size() > 1)
			{
				std::cout << "Current Number to add : " << l_sNumberToAdd << std::endl;

				l_iListOfNuberPartitions.push_back(l_sNumberToAdd); 
			}
		}
	
		// Before the start of the next loop increase the size of the next group of pairings. 
		l_iCurrentPairing++; 

	} while (l_iCurrentPairing < inputNumber.size()); 

	return l_iListOfNuberPartitions; 
}

#pragma endregion

#pragma region Number Evaluation

/*! \Function This will be used to check which numbers appear more than once in the given list of numbers. 
*Param One: Vector<String> - The list of numbers needing to be checked. 
*/
void l_CheckNumbers(std::vector<std::string> listOfNumbers)
{
	// Local Variables

	/*! \var This is the number of times a single number paring appears in the full number. */
	int l_iNumberOfRepititions = 0;

	/*! \var This is the current number parig which is being checked against all of the other parings in the list. */
	std::string l_sNumberBeingChecked;

	/*! \var This will contain all of the text outputs gathered from the function, for easy display at the end of this function. */
	std::vector<std::string> l_sFinalOutput;

	// Pair of for loops used to check each number for multiple occurences of them. 

	for (unsigned int i = 0; i < listOfNumbers.size(); i++)
	{
		// At the start this will be equal to number in list at point 0. 
		l_sNumberBeingChecked = listOfNumbers[i];

		for (unsigned int j = 0; j < listOfNumbers.size(); j++)
		{
			// If the numbers are the same they are the same number so should be skipped. 

			if (l_sNumberBeingChecked == listOfNumbers[j])
			{
				l_iNumberOfRepititions++;
			}

		}

		// End of checking and final result should be added into vector. 

		if (l_iNumberOfRepititions > 1)
		{
			std::string l_sTextToAdd = l_sNumberBeingChecked + ":" + std::to_string(l_iNumberOfRepititions);

			// Used to check if the vector already contains the text, as to prevent duplicate outputs.
			if (std::find(l_sFinalOutput.begin(), l_sFinalOutput.end(), l_sTextToAdd) == l_sFinalOutput.end())
			{
				l_sFinalOutput.push_back(l_sTextToAdd);
			}
		}

		// Reset number at end of loop. 
		l_iNumberOfRepititions = 0;
	}

	// End of function print all answers in vector. 
		
	std::cout << "Finsihed Exaluation, the results are as followed...\n"; 

	for (int i = 0; i < l_sFinalOutput.size(); i++)
	{
		std::cout << l_sFinalOutput[i] << std::endl;
	}
}

#pragma endregion

#pragma region Main

int main()
{
	// Local Variables. 

	/*! var This is used to hold the number inputted by the user. */
	std::string l_sInput; 

	/*! \var This will hold the list of numbers ready to transfer from the first funtion into the second. */
	std::vector<std::string> l_sListOfNumbers; 

    // Entry Text

	std::cout << "Welcome to the repeating number detector. \nEnter a number of any range and this program will detect any repeting number of legnth 2 or greater. ";

	std::cout << "\nYour Number : "; 

	std::cin >> l_sInput; 

	// Processing

	l_sListOfNumbers = l_NumberPartitioning(l_sInput);

	std::cout << "After processing the number of items to evaluate stand at: " << l_sListOfNumbers.size() << std::endl;

	l_CheckNumbers(l_sListOfNumbers); 
}

#pragma endregion