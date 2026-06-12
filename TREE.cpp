#include <iostream>
using namespace std;

//class node
class node {
    //akses modifikasi dan deklarasi varable dan objeck node
    public :
    string info;
    node* leftChild;
    node* rightChild;

    //construktor class node
    node(string i, node* l, node* r) {
        //niali paramater
        info = i;
        leftChild = l;
        rightChild = r;
    }
};

class BinaryTree {
    //akses modif dan deklasrasi
    public :
    node* ROOT;
    //membuat construktor ddan memberikan nilai paada objek root
    BinaryTree() {
        ROOT = nullptr;
    }

    //membuat prosedur instert
    void insert(string element) {
        //input nilai pada setiap objek
        node* newNode = new node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;
        
        node* parent = nullptr;
        node* currentNode = nullptr;
        search(element, parent, currentNode);

        //membuat conditional statement
        if (parent == nullptr) {
            ROOT = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftChild = newNode;
        }
        else if (element > parent->info)
        {
            parent->rightChild = newNode;
        }
    }
