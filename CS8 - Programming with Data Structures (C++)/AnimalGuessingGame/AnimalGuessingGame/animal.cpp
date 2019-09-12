// An animal-guessing program to illustrate the use of the binary tree toolkit.

#include "bintree.h"    // Provides eat_line, inquire (from Appendix I)
using namespace main_savitch_10;

//------------------THIS WILL WRITE/LOAD A TEXT FILE-------------------------------------
void writeBinaryTree(binary_tree_node<string> *p, ofstream &toFile);
void loadBinaryTree(binary_tree_node<string> *&current_ptr, ifstream &fromFile);
//---------------------------------------------------------------------------------------

//PREMADE INITIALIZATIONS
void ask_and_move(binary_tree_node<string>*& current_ptr);
binary_tree_node<string>* beginning_tree( );
void instruct( );
void learn(binary_tree_node<string>*& leaf_ptr);
void play(binary_tree_node<string>* current_ptr);


//---------------------------WRITING TO A TXT FILE--------------------------------

void writeBinaryTree(binary_tree_node<string> *p, ofstream &toFile) {

    if (!p) {
        toFile << "NULL"; //when the node ends, it will write NULL, and kill the recursion
        toFile << endl;
    }
    else {
        toFile << p->data() << endl;
        writeBinaryTree(p->left(),toFile); //recursively go left always
        writeBinaryTree(p->right(),toFile); //then right
    }
}

//----------------------------LOADING FROM A TXT FILE-----------------------------

void loadBinaryTree(binary_tree_node<string>*& current_ptr, ifstream &fromFile){
    char word[100];
    fromFile.getline(word, 100);
    string word2 = word;
    word2[word2.size()] = NULL;
    if(word2 == "NULL"){
        current_ptr = NULL;
        return;
    }
    else{
        binary_tree_node<string> *next;

        current_ptr = new binary_tree_node<string>(word2);

        loadBinaryTree(next, fromFile);
        current_ptr->set_left(next);

        loadBinaryTree(next, fromFile);
        current_ptr->set_right(next);
    }
}

//-------------------------------------------------------------------------------------
void ask_and_move(binary_tree_node<string>*& current_ptr)
// Library facilities used: bintree.h, string, useful.h
{
    cout << current_ptr->data();
    if (inquire(" Please answer:"))
        current_ptr = current_ptr->left( );
    else
        current_ptr = current_ptr->right( );
}

binary_tree_node<string>* beginning_tree( )
// Library facilities used: bintree.h, string
{
    binary_tree_node<string> *root_ptr;
    binary_tree_node<string> *child_ptr;

    const string root_question("Are you a mammal?");
    const string left_question("Are you bigger than a cat?");
    const string right_question("Do you live underwater?");
    const string animal1("Kangaroo");
    const string animal2("Mouse");
    const string animal3("Trout");
    const string animal4("Robin");

    // Create the root node with the question “Are you a mammal?”
    root_ptr = new binary_tree_node<string>(root_question);

    // Create and attach the left subtree.
    child_ptr = new binary_tree_node<string>(left_question);
    child_ptr->set_left( new binary_tree_node<string>(animal1) );
    child_ptr->set_right( new binary_tree_node<string>(animal2) );
    root_ptr->set_left(child_ptr);

    // Create and attach the right subtree.
    child_ptr = new binary_tree_node<string>(right_question);
    child_ptr->set_left( new binary_tree_node<string>(animal3) );
    child_ptr->set_right( new binary_tree_node<string>(animal4) );
    root_ptr->set_right(child_ptr);

    return root_ptr;
}


void instruct( )
// Library facilities used: iostream
{
    cout << "Let's play!" << endl;
    cout << "You pretend to be an animal, and I try to guess what you are.\n";
}

void learn(binary_tree_node<string>*& leaf_ptr)
// Library facilities used: bintree.h, iostream, string, useful.h
{
    string guess_animal;    // The animal that was just guessed
    string correct_animal;  // The animal that the user was thinking of
    string new_question;    // A question to distinguish the two animals

    // Set strings for the guessed animal, correct animal and a new question.
    guess_animal = leaf_ptr->data( );
    cout << "I give up. What are you? " << endl;
    getline(cin, correct_animal);
    cout << "Please type a yes/no question that will distinguish a" << endl;
    cout << correct_animal << " from a " << guess_animal << "." << endl;
    cout << "Your question: " << endl;
    getline(cin, new_question);

    // Put the new question in the current node, and add two new children.
    leaf_ptr->set_data(new_question);
    cout << "As a " << correct_animal << ", " << new_question << endl;
    if (inquire("Please answer"))
    {
        leaf_ptr->set_left( new binary_tree_node<string> (correct_animal) );
        leaf_ptr->set_right( new binary_tree_node<string> (guess_animal) );
    }
    else
    {
        leaf_ptr->set_left( new binary_tree_node<string> (guess_animal) );
        leaf_ptr->set_right( new binary_tree_node<string> (correct_animal) );
    }
}

void play(binary_tree_node<string>* current_ptr)
// Library facilities used: bintree.h, iostream, string, useful.h
{
    cout << "Think of an animal, then press the return key.";

    eat_line( );
    while (!current_ptr->is_leaf( ))
        ask_and_move(current_ptr);


    cout << ("My guess is " + current_ptr->data() + ". ");
    if (!inquire("Am I right?"))
        learn(current_ptr);
    else
        cout << "I knew it all along!" << endl;
}
