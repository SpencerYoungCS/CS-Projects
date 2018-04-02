#include "animal.cpp"

int main(){
    binary_tree_node<string> *taxonomy_root_ptr;

    binary_tree_node<string> *loadedTree;// I will run the game using this tree, which is created from.

    //reading the file.
    ifstream fromFile;
    fromFile.open("out.txt");

    //-----------------------------------------------------------------------

    loadBinaryTree(loadedTree,fromFile); //CREATE LOADED TREE

    //-------------------------------------------------------------------
    instruct();
    taxonomy_root_ptr = beginning_tree();
    //--------------------PLAY WITH LOADED TREE--------------------------
    do
        play(loadedTree);
    while (inquire("Shall we play again?"));

    //-------------------------------------------------------------------

    cout << "Thank you for teaching me a thing or two." << endl;


    //------------------------WRITE NEW TREE INTO OUT.TXT----------------------

    ofstream myFile("out.txt");
    writeBinaryTree(loadedTree, myFile);

    //------------------------------------------------------------------------



    return EXIT_SUCCESS;
}
