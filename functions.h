//
// Created by BK Allen on 2/21/20.
//

#ifndef _2188HW4_FUNCTIONS_H
#define _2188HW4_FUNCTIONS_H


#include <string>
#include <fstream>
#include "node1.h"
using namespace main_savitch_5;
class ExceptionFirstWordNotFound {};
void eat_white(std::ifstream& ifile);
std::string getWordFromFile(std::ifstream &ifile);
node* getListFromFile(std::ifstream &ifile);
void printList(node *);
void openFile(int argc, char** argv, std::ifstream& ifile);
node* searchForSubList(std::string, std::string);
void sortList(node*&);

#endif //_2188HW4_FUNCTIONS_H
