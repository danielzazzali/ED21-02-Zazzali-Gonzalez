#ifndef BinaryTree_HEADER
#define BinaryTree_HEADER
#include "../include/NodeBinaryTree.h"
#include "../include/Identity.h"

class BinaryTree{

private:

	NodeBinaryTree* root = new NodeBinaryTree();

	void copyTree(NodeBinaryTree*& copiedTreeRoot, NodeBinaryTree* otherTreeRoot);
	//Hace una copia del árbol binario para
	//otherTreeRoot points. El apuntador copiedTreeRoot
	//apunta a la raíz del árbol binario copiado.

	void destroy(NodeBinaryTree*& p);
	//Función para destruir el árbol binario para los puntos p.
	//Poscondición: p = NULL

	void inorder(NodeBinaryTree* p) const;
	//Función para hacer un recorrido inorden del árbol
	//binario para los puntos p.

	int height(NodeBinaryTree* p) const;
	//Función para devolver la altura del árbol binario
	//para los puntos p.

	int max(int x, int y) const;
	//Devuelve el más largo de x y y.

public:

	BinaryTree();
	//constructor predeterminado

	bool search(const Identity& item);
	//Función para determinar si searchItem está en el árbol binario
	//Poscondición: Devuelve true si Item se encuentra en el
	//árbol binario; de lo contrario, devuelve false.

	void insert(const Identity& item);
	//Función para insertar insertItem en el árbol binario.
	//Poscondición: Si ningún nodo en el árbol binario
	//tiene la misma data que Item, un nodo con la data
	//Item es creado e insertado en el árbol binario.

	void deleteNode(const Identity& item);
	//Función para eliminar Item del árbol binario.
	//Poscondición: Si se encuentra un nodo con la misma data
	// que Item, es eliminado del árbol binario.

	bool isEmpty() const;
	// Devuelve true si el árbol binario está vacío;
	//de lo contrario, devuelve false.

	void inorderTraversal() const;
	//Función para hacer un recorrido inorden del árbol binario.

	int treeHeight() const;
	//Devuelve la altura del árbol binario.

	void destroyTree();
	//Desasigna el espacio de memoria ocupado por el árbol binario.
	//Poscondición: root = NULL;

};

#endif
