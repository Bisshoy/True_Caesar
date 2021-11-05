/*
This is a program that allows the user to input a string of any length. 
The user will also choose a shift value. The program will shift the 
letters of the user's original sentence by a number equal to the shift 
value. For example, if the entered message is abcde and the shift value
is 2, then the cyphered text is cdefg. 

This program also includes a decypher option; for this, input the same 
shift value as the original; no extra work needs to be done. If the 
original text was cyphered with a shift value of 5, then to decypher it,
the user should input 5 at the prompt as well. 

[NOTE: The formula for the decode shift is: 26 - (shift % 26)]

@version 11-5-2021 (Happy Guy Fawkes Day!)
@author Bisshoy Anwar 
*/


#include <iostream>

// List of prototypes 
std::string CaesarCypher(std::string original, int shift);
void Cypher();
void Decypher();

// Driver function 
int main() {
    std::string answer;

    std::cout << "Do you want to cypher or decypher? [cypher/decypher]: ";
    std::getline(std::cin, answer);

    if (answer[0] == 'C' || answer[0] == 'c') {
        Cypher();
    } else if (answer[0] == 'D' || answer[0] == 'd') {
        Decypher();
    } else {
        std::cout << "ERROR: decision not recognized." << std::endl;
    }

    return 0;

}

// Caesar Cypher Function 
std::string CaesarCypher(std::string original, int shift) {
    // Iterate through all elements of original 
    for (int i = 0; i < original.size(); i++) {

        // For lowercase letters 
        if (islower(original[i])) {
            
            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <=126) {
                original[i] = original[i];
            }

            else {
                original[i] = char(int(original[i] - 97 + shift) % 26 + 97);
            }

        }

        // For uppercase letters 
        else {

            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <=126) {
                original[i] = original[i];
            } 

            else {
                original[i] = char(int(original[i] - 65 + shift) % 26 + 65);
            }

        }
    }
    return original;
}

// If user chooses to cypher 
void Cypher() {
    std::string original; 
    int shift;

    std::cout << "\nEnter your original string here: " << std::endl;
    std::getline(std::cin, original);
        
    std::cout << "\nEnter your shift value here: "; std::cin >> shift;
    std::cin.ignore();         

    std::cout << "\nYour cyphered text is: " << std::endl; 
    std::cout << CaesarCypher(original, shift) << std::endl;
}

// If user chooses to decypher 
void Decypher() {
    std::string original; 
    int shift;

    std::cout << "\nEnter the cyphered string here: " << std::endl;
    std::getline(std::cin, original);

    std::cout << "\nEnter the original shift value here: "; std::cin >> shift;
    std::cin.ignore();

    int decodeShift = 26 - (shift % 26);

    std::cout << "\nYour decyphered text is: " << std::endl; 
    std::cout << CaesarCypher(original, decodeShift) << std::endl;
}