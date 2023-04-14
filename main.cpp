#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

int main() {

	Tree<int> tree1;
	tree1.insert(50);
	tree1.insert(30);
	tree1.insert(70);
	tree1.insert(20);
	tree1.insert(40);
	tree1.insert(60);
	cout << endl << "tree1 created: " << endl;

	tree1.inOrderWalk();

	cout << endl << "Node with key=20 deleted: " << endl << "result: " << tree1.delete_node(20) << endl;;
	tree1.inOrderWalk();

	cout << endl << "Node with key=10 deleted: " << endl << "result: " << tree1.delete_node(10) << endl;
	tree1.inOrderWalk();

	Tree<int> tree2;
	tree2.insert(50);
	tree2.insert(30);
	tree2.insert(70);
	tree2.insert(20);
	cout<<endl<< "isIdenticalKey in tree2: "<< tree1.isIdenticalKey(tree2)<<endl;
	Tree<int> tree3;
	tree3.insert(5);
	tree3.insert(3);
	tree3.insert(7);
	tree3.insert(2);
	tree3.iterativeWalk();
	cout << "isIdenticalKey in tree3: " << tree1.isIdenticalKey(tree3) << endl;

	cout <<endl<< "tree1 node count: " << tree1.getCount() << endl;
	cout << endl << "tree1 height: " << tree1.getHeight() << endl;

	cout << endl << "tree1 iterative walk: " << endl;
	tree1.iterativeWalk();

	cout<<"tree1 and tree2 similar?: "<<tree1.isSimilar(tree2)<<endl;
	cout << "tree3 and tree2 similar?: " << tree3.isSimilar(tree2) << endl;

	cout <<endl<< "tree1 widthWalk:" << endl;
	tree1.widthWalk();

	system("pause");
	return 0;

}