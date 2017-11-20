#include "BinaryTree.h"

Leaf * BTree::mostLeft(Leaf * root)
{
	if (root->left)
	{
		return mostLeft(root->left);
	}
	else
	{
		return root;
	}
}

//Constructores
BTree::BTree() {
	root = NULL;
	leaves = 0;
}

BTree::BTree(int d) {
	Leaf *leaf = new Leaf(d);
	root = leaf;
	leaves = 1;
}

//Destructor
BTree::~BTree() {}

//Inserta un elemento en el arbol
void BTree::insert(int d, Leaf *root) {
	if (root) {
		if (d < root->getData()) {
			if (!root->left) {
				root->left = new Leaf(d);
				leaves++;
			}
			else {
				insert(d, root->left);
			}
		}
		else {
			if (!root->right) {
				root->right = new Leaf(d);
				leaves++;
			}
			else {
				insert(d, root->right);
			}
		}
	}
	else {
		this->root = new Leaf(d);
		leaves = 1;
	}
}

//Muestra el contenido del elemento
void BTree::showLeaf(Leaf *root) {
	root->print();
}


//Buscamos un dato dentro del arbol
Leaf *BTree::fetch(int d, Leaf *root) {
	if (root) {
		if (d == root->getData()) {
			return root;
		}
		else if (d < root->getData()) {
			return fetch(d, root->left);
		}
		else {
			return fetch(d, root->right);
		}
	}
	else return NULL;
}

Leaf *BTree::getFather(Leaf *leaf, Leaf *root) {
	//Si hay arbol, y si la hoja es diferente a root
	if (root && leaf != root) {
		if (root->left == leaf || root->right == leaf) {
			return root;
		}
		else if (leaf->getData() < root->getData()) {
			return getFather(leaf, root->left);
		}
		else {
			return getFather(leaf, root->right);
		}
	}
	else return NULL;
}

/*
***Eliminar una hoja, hay 3 casos
1. Borrar elemento sin hijos
2. Borrar elemento con un sub arbol hijo
3. Borrar elemento con dos sub arboles hijos
*/
bool BTree::deleteLeaf(int d, Leaf *root) {
	//hacemos la búsqueda del nodo y de su padre
	Leaf *f, *s;
	s = fetch(d, root); //Validar que s!=NULL
	f = getFather(s, root);

	//Preguntamos si tiene hijos
	bool l = s->left ? true : false;
	bool r = s->right;

	//Si no tiene hijos
	if (!l && !r) {
		//Eliminamos nodo según caso 1
		//Si es el hijo de la izquierda, la apuntamos a NULL, caso contrario apuntamos hijo derecho a NULL.
		f->left == s ? f->left = NULL : f->right = NULL;
		return true;
	}
	else if (!l && r) {
		//Eliminamos nodo según caso 2, solo hijos a la derecha
		if (f->left == s) { //Si es el hijo de la izquierda
			f->left = s->right; //los hijos derechos del nodo eliminado se cuelgan en el brazo izquierdo de su padre
		}
		else { //Si es el hijo de la derecha
			f->right = s->right;//los hijos erechos del nodo eliminado se cuelgan del brazo derecho de su padre
		}
		return true;
	}
	else if (l && !r) {
		//Eliminamos nodo según caso 2, solo hijos a la izquierda
		if (f->left == s) {
			f->left = s->left;
		}
		else {
			f->right = s->left;
		}
		return true;
	}
	else if (l && r) {
		//Eliminamos nodo según caso 3
		Leaf *nl = mostLeft(s->right);
		s->setData(nl->getData());
		return deleteLeaf(nl->getData(),nl);
	}
	else {
		return false;
	}
}


//Ojo con isEmpty, solo funciona para la raiz principal del arbol

bool BTree::isEmpty() {
	return !root;
}

//Devuelve un apuntador a raiz
Leaf *BTree::getRoot() {
	return this->root;
}

//Devuelve la altura del arbol
int BTree::Height(Leaf *root) {
	if (isEmpty()) {
		return 0;
	}
	else {
		int a, b;
		if (!root->left && !root->right) {
			return 1;
		}
		else {
			a = Height(root->left);
			b = Height(root->right);
			if (a>b) return a + 1;
			else return b + 1;
		}
	}
}

//Devuelve la cantidad de hojas del arbol
int BTree::getLeaves() {
	return leaves;
}

void BTree::inOrder(Leaf * root)
{
	if (root)
	{
		inOrder(root->left);
		root->print();
		inOrder(root->right);
	}
}

void BTree::preOrder(Leaf * root)
{
	if (root)
	{
		root->print();
		preOrder(root->left);
		preOrder(root->right);
	}
}

void BTree::postOrder(Leaf * root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		root->print();
	}
}



