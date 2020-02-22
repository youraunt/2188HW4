#include <iostream>
/*
 This program does the following:
 1) Makes a linked list of words from a file
 2) Takes two strings from user
 3) Searches for a node in the original list containing the first string
 4) Searches for a node after the first node containing the second string
 5) Makes a sublist containing copies of all nodes from the first up to and including the last
 6) Sorts the sublist by dictionary order
 */

#include <string>
#include "node1.h"
#include "functions.h"

using namespace main_savitch_5;


int main(int argc, char** argv)
{
    std::ifstream infile;
    std::string word1, word2;
    node    *listHead = nullptr,                           // Head of the original list
            *subListHead = new node,                       // Head of the sublist
            *subListTail = new node,                       // Tail of sublist
            *firstSearch = nullptr,                         // Pointer to results of first search
            *secondSearch = nullptr;                       // Pointer to results of seconds search

    // Make and print original list
    openFile(argc, argv, infile);
    listHead = getListFromFile(infile);
    printList(listHead);

    // Get input and search for a sublist
    // If either of the searches return NULL, alert user and exit program
    std::cout << "\nPlease enter the first word to search for: ";
    getline(std::cin, word1);
    firstSearch = list_search(listHead, word1);
    if (firstSearch == nullptr)
    {
        std::cout << "Sublist not found\n";
        return 0;
    }
    std::cout << "\nPlease enter the second word to search for: ";
    getline(std::cin, word2);
    secondSearch = list_search(firstSearch, word2);
    if (secondSearch == nullptr)
    {
        std::cout << "Sublist not found\n";
        return 0;
    }
    std::cout << std::endl;

    // Make and print sublist
    list_piece(firstSearch, secondSearch, subListHead, subListTail);
    printList(subListHead);

    // Sort and print sublist
    sortList(subListHead);
    printList(subListHead);

    return 0;
}