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