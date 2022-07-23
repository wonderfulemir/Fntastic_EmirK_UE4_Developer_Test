// Name:                Emir Khanseitov
// Date:                23.07.2022
// Description:         Given any sentence, convert any symbol into '(' if only one, but if duplicated make them ')'

#include <iostream>
#include <map>
#include <string>

int main()
{
    // What we shall be grabbing from the user and transforming 
    std::string given_sentence;

    // Grab the input
    std::cout << "Please enter a sentence to convert to \" )))((())) \" : " << std::endl;
    std::getline(std::cin, given_sentence);

    // Sanity checks
    if (given_sentence.empty())
    {
        return 0;
    }

    // NOTE: Initial implementation was using Double Loop, but we all know how O(N^2) works, right

    // Use the map to store all the values of the letters
    std::map<char, int> letter_occurences;
    const unsigned int A_Before_Letter = 64;
    const unsigned int Z_After_Letter = 91;
    const unsigned int Difference_Capital_Small_Letter = 32;

    // Go through the sentence once
    int size = given_sentence.size();
    for (int i = 0; i < size; ++i)
    {
        char current_letter = given_sentence[i];

        // Remember that Capital letters = Small letters
        if (current_letter > A_Before_Letter && current_letter < Z_After_Letter)
        {
            current_letter += Difference_Capital_Small_Letter;
        }

        // If the letter is found in the map, we shall append the idx
        if (letter_occurences.find(current_letter) != letter_occurences.end())
        {
            ++letter_occurences.at(current_letter);
        }
        // Otherwise add this letter to the map
        else
        {
            letter_occurences.insert(std::pair<char, int>(current_letter, 1));
        }
    }

    // Finally, let's print back the given sentence
    std::string final_answer;
    for (int i = 0; i < size; ++i)
    {
        char current_letter = given_sentence[i];

        // Remember that Capital letters = Small letters
        if (current_letter > A_Before_Letter && current_letter < Z_After_Letter)
        {
            current_letter += Difference_Capital_Small_Letter;
        }

        // Convert to '('
        if (letter_occurences.at(current_letter) == 1)
        {
            final_answer += '(';
        }
        // Convert to ')'
        else
        {
            final_answer += ')';
        }
    }

    // Print final result
    std::cout << final_answer << std::endl;
    return 0;
}