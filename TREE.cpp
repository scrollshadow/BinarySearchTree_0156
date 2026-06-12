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

     //this function searches the current node of the specified node
    //as well as the current node of its parrent
    void search(string element, node *&parent, node *&currentNode)
    {
    currentNode = ROOT;
        parent = NULL;

        while((currentNode != NULL) &&
             (currentNode->info != element))
             {
                parent = currentNode;

                if (element < currentNode->info)
                    currentNode = currentNode->leftChild;
                else
                    currentNode = currentNode->rightChild;
         }
    }

    void inorder(node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftChild);
            cout << ptr->info << " ";
            inorder(ptr->rightChild);
        }
    }

    void preorder(node *ptr)
    {
        if (ROOT == NULL)
        {
            cout <<"Tree is empty" <<  endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftChild);
            preorder(ptr->rightChild);
        }
    }

    void postorder(node *ptr)
    {
        // perfoms the postorder traveersal of the tree

        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != NULL)
        {
            postorder(ptr->leftChild);
            postorder(ptr->rightChild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree obj;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;
        cin >> ch;

        cout << endl;

        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;
            cin >> word;
            obj.insert(word);
            break;
        }

        case '2':
        {
            obj.inorder(obj.ROOT);
            break;
        }

        case '3':
        {
            obj.preorder(obj.ROOT);
            break;
        }
        
         case '4':
        {
            obj.postorder(obj.ROOT);
            break;
        }

        case '5':
            return 0;
        
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
    return 0;
}