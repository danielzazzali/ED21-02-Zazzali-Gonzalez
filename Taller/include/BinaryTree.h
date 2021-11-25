#ifndef BinaryTree_HEADER
#define BinaryTree_HEADER
#include "../include/NodeBinaryTree.h"
#include "../include/Identity.h"

class BinaryTree{

private:

	NodeBinaryTree* root = new NodeBinaryTree();

	void copyTree(NodeBinaryTree*& copiedTreeRoot, NodeBinaryTree* otherTreeRoot);
	//Hace una copia del �rbol binario para
	//otherTreeRoot points. El apuntador copiedTreeRoot
	//apunta a la ra�z del �rbol binario copiado.

	void destroy(NodeBinaryTree*& p);
	//Funci�n para destruir el �rbol binario para los puntos p.
	//Poscondici�n: p = NULL

	void inorder(NodeBinaryTree* p) const;
	//Funci�n para hacer un recorrido inorden del �rbol
	//binario para los puntos p.

	int height(NodeBinaryTree* p) const;
	//Funci�n para devolver la altura del �rbol binario
	//para los puntos p.

	int max(int x, int y) const;
	//Devuelve el m�s largo de x y y.

public:

	BinaryTree();
	//constructor predeterminado

	bool search(const Identity& item);
	//Funci�n para determinar si searchItem est� en el �rbol binario
	//Poscondici�n: Devuelve true si Item se encuentra en el
	//�rbol binario; de lo contrario, devuelve false.

	void insert(const Identity& item);
	//Funci�n para insertar insertItem en el �rbol binario.
	//Poscondici�n: Si ning�n nodo en el �rbol binario
	//tiene la misma data que Item, un nodo con la data
	//Item es creado e insertado en el �rbol binario.

	void deleteNode(const Identity& item);
	//Funci�n para eliminar Item del �rbol binario.
	//Poscondici�n: Si se encuentra un nodo con la misma data
	// que Item, es eliminado del �rbol binario.

	bool isEmpty() const;
	// Devuelve true si el �rbol binario est� vac�o;
	//de lo contrario, devuelve false.

	void inorderTraversal() const;
	//Funci�n para hacer un recorrido inorden del �rbol binario.

	int treeHeight() const;
	//Devuelve la altura del �rbol binario.

	void destroyTree();
	//Desasigna el espacio de memoria ocupado por el �rbol binario.
	//Poscondici�n: root = NULL;

};

#endif
