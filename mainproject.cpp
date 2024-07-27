#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<ctime>
#include<fstream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

class Inventory;
class Laptop;
class AVL;
class User;


class Laptop
{

	string ISBN;
	int quantity;
	float Price;
	int year;
	string Color;
	string Brand;
	string StorageCapacity;
	string screenSize;
	string CameraResolution;
	string BatteryLife;
	stack<string> reviews;

	Laptop* left;
	Laptop* right;
	Laptop* ptr;
	int height;

public:
	Laptop()
	{
		this->ISBN = to_string(1 + rand() % 100);
		quantity = 0;
		Price = 0;
		Color = "";
		Brand = "";
		year = 0;
		StorageCapacity = "";
		screenSize = "";
		CameraResolution = "";
		BatteryLife = "";
		left = NULL;
		right = NULL;
		ptr = NULL;
		height = 1;
	}

	Laptop(string isb, int qty, float p, string col, string br, int yr, string storage, string screen, string camera, string battery)
	{
		this->ISBN = isb;
		quantity = qty;
		Price = p;
		Color = col;
		Brand = br;
		year = yr;
		StorageCapacity = storage;
		screenSize = screen;
		CameraResolution = camera;
		BatteryLife = battery;
		left = NULL;
		right = NULL;
		ptr = NULL;
		height = 1;
	}
	Laptop(Laptop* t, string ISBN)
	{
		this->ISBN = ISBN;
		Price = t->getPrice();
		Color = t->getColor();
		Brand = t->getBrand();
		StorageCapacity = t->getStorage() ;
		screenSize = t->getScreen();
		CameraResolution = t->getCamera();
		BatteryLife = t->getBattery();
		left = NULL;
		right = NULL;
		ptr = NULL;
	}
	void setISBN(string ISBN)
	{
		this->ISBN = ISBN;
	}
	string getISBN()
	{
		return ISBN;
	}
	int getQty()
	{
		return quantity;
	}
	float getPrice()
	{
		return Price;
	}
	int getYear()
	{
		return year;
	}
	string getColor()
	{
		return Color;
	}
	string getBrand()
	{
		return Brand;
	}
	string getCamera()
	{
		return CameraResolution;
	}
	string getScreen()
	{
		return screenSize;
	}
	string getBattery()
	{
		return BatteryLife;
	}
	string getStorage()
	{
		return StorageCapacity;
	}
	void increaseQty()
	{
		quantity++;
	}
	void decreaseQty()
	{
		quantity--;
	}

	void operator=(const Laptop* root)
	{
		ISBN = root->ISBN;
		quantity = root->quantity;
		Price = root->Price;
		Color = root->Color;
		Brand = root->Brand;
		year = root->year;
		StorageCapacity = root->StorageCapacity;
		screenSize = root->screenSize;
		CameraResolution = root->CameraResolution;
		BatteryLife = root->BatteryLife;
		left = root->left;
		right = root->right;
		height = root->height;
		reviews = root->reviews;

	}
	void display()
	{
		cout << "ISBN: " << ISBN << "\nPrice: " << Price << "\nColour: " << Color << "\nName: " << Brand;
		cout << "\nStorage: " << StorageCapacity << "\nScreen Size: " << screenSize;
		cout << "\nCamera resolution: " << CameraResolution << "\nBattery life: " << BatteryLife << endl;
	}
	bool operator == (const Laptop* root)
	{
		if ((Price == root->Price) && (Color == root->Color) && (Brand == root->Brand) && (year = root->year) && (StorageCapacity == root->StorageCapacity) && (screenSize == root->screenSize) && (CameraResolution == root->CameraResolution) && (BatteryLife == root->BatteryLife))		//left == root->left;
			return 1;
		return 0;

	}
	friend class AVL;
	friend class Inventory;
	friend ostream& operator <<(ostream& out, const Laptop&);
	friend istream& operator >>(istream& in, Laptop&);
	friend class shoppingcart;
};

ostream& operator <<(ostream& out, const Laptop& laptop)
{
	cout << "\nISBN : ";
	out << laptop.ISBN;
	cout << "\nQuantity : ";
	out << laptop.quantity;
	cout << "\nPrice : ";
	out << laptop.Price;
	cout << "\nColor : ";
	out << laptop.Color;
	cout << "\nBrand : ";
	out << laptop.Brand;
	cout << "\nYear : ";
	out << laptop.year;
	cout << "\nStorageCapacity : ";
	out << laptop.StorageCapacity;
	cout << "\nscreenSize : ";
	out << laptop.screenSize;
	cout << "\nCameraResolution : ";
	out << laptop.CameraResolution;
	cout << "\nBatteryLife : ";
	out << laptop.BatteryLife;
	//while (!laptop.reviews.empty())
	//{
	//	out << laptop.reviews.top();
	//	laptop.reviews.pop();
	//}
	cout << endl;
	return out;
}
istream& operator >>(istream& in, Laptop& laptop)
{
	laptop.quantity = 1;

	int flag = 0;
	cout << "\nEnter Price : ";
	in >> laptop.Price;
	do
	{
		if (laptop.Price > 0)
			flag = 1;
		else
		{
			cout << "Please enter a number greater than 0 " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> laptop.Price;
		}
	} while (flag == 0);

	flag = 0;
	cout << "\nEnter Color : ";
	in >> laptop.Color;
	do
	{
		for (int i = 0; i < laptop.Color.length(); i++)
			laptop.Color[i] = toupper(laptop.Color[i]);
		if (laptop.Color == "BLACK" || laptop.Color == "WHITE" || laptop.Color == "SILVER" || laptop.Color == "BLUE")
			flag = 1;
		else
		{
			cout << "\nLaptops in this color arent allowed.Please enter a correct color (Black,Silver,White,Blue) \n" << endl;
			cin >> laptop.Color;
		}
	} while (flag == 0);

	flag = 0;
	cout << "\nEnter Brand : ";
	in >> laptop.Brand;
	do
	{
		for (int i = 0; i < laptop.Brand.length(); i++)
			laptop.Brand[i] = toupper(laptop.Brand[i]);
		if (laptop.Brand == "HP" || laptop.Brand == "DELL" || laptop.Brand == "LENOVO" || laptop.Brand == "APPLE")
			flag = 1;
		else
		{
			cout << "\nLaptops in this brand arent allowed.Please enter a correct brand (HP,DELL,LENOVO,APPLE) \n" << endl;
			cin >> laptop.Brand;
		}
	} while (flag == 0);

	flag = 0;
	cout << "\nEnter Year : ";
	in >> laptop.year;
	do
	{
		if (laptop.year > 0)
			flag = 1;
		else
		{
			cout << "Please enter a number greater than 0 " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> laptop.year;
		}
	} while (flag == 0);


	cout << "\nEnter StorageCapacity : ";
	in >> laptop.StorageCapacity;
	cout << "\nEnter screenSize : ";
	in >> laptop.screenSize;
	cout << "\nEnter CameraResolution : ";
	in >> laptop.CameraResolution;
	cout << "\nEnter BatteryLife : ";
	in >> laptop.BatteryLife;
	cout << endl;
	return in;
}




class AVL
{
	int height(Laptop* N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	Laptop* rightRotate(Laptop* imbalancedNode)
	{
		Laptop* lchild = imbalancedNode->left;
		Laptop* temp = lchild->right;

		lchild->right = imbalancedNode;
		imbalancedNode->left = temp;

		imbalancedNode->height = max(height(imbalancedNode->left),
			height(imbalancedNode->right)) + 1;
		lchild->height = max(height(lchild->left),
			height(lchild->right)) + 1;

		return lchild;
	}

	Laptop* leftRotate(Laptop* imbalancedNode)
	{
		Laptop* rchild = imbalancedNode->right;
		Laptop* temp = rchild->left;

		rchild->left = imbalancedNode;
		imbalancedNode->right = temp;

		imbalancedNode->height = max(height(imbalancedNode->left),
			height(imbalancedNode->right)) + 1;
		rchild->height = max(height(rchild->left),
			height(rchild->right)) + 1;

		return rchild;
	}

	int getBalance(Laptop* N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	Laptop* minValueNode(Laptop* node)
	{
		Laptop* current = node;

		while (current->left != NULL)
			current = current->left;

		return current;
	}
public:

	Laptop* newNode(string ISBN, int qty, float p, string col, string br, int yr, string storage, string screen, string camera, string battery)
	{
		Laptop* laptop = new Laptop(ISBN, qty, p, col, br, yr, storage, screen, camera, battery);
		laptop->left = NULL;
		laptop->right = NULL;
		laptop->height = 1;
		return(laptop);
	}
	template<typename T>
	Laptop* insert(Laptop* node, Laptop* temp, T basis)
	{

		if (node == NULL)
			return temp;

		//By ISBN
		if (typeid(basis).name() == typeid(temp->ISBN).name())
		{
			string tempVal = temp->ISBN;
			string nodeVal = node->ISBN;

			if (tempVal < nodeVal)
				node->left = insert(node->left, temp, basis);
			else if (tempVal > nodeVal)
				node->right = insert(node->right, temp, basis);
			else return node;

			node->height = 1 + max(height(node->left), height(node->right));

			int balance = getBalance(node);
			if (balance > 1)
			{
				string leftVal = node->left->ISBN;

				if (tempVal < leftVal)
					return rightRotate(node);
				else if (tempVal > leftVal)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}
			else if (balance < -1)
			{
				string rightVal = node->right->ISBN;

				if (tempVal > rightVal)
					return leftRotate(node);
				if (tempVal < rightVal)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
		}

		//By Price
		else if (typeid(basis).name() == typeid(temp->Price).name())
		{
			float tempVal = temp->Price;
			float nodeVal = node->Price;

			if (tempVal < nodeVal)
				node->left = insert(node->left, temp, basis);
			else if (tempVal > nodeVal)
				node->right = insert(node->right, temp, basis);
			else return node;

			node->height = 1 + max(height(node->left), height(node->right));

			int balance = getBalance(node);
			if (balance > 1)
			{
				float leftVal = node->left->Price;

				if (tempVal < leftVal)
					return rightRotate(node);
				else if (tempVal > leftVal)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}
			}
			else if (balance < -1)
			{
				float rightVal = node->right->Price;

				if (tempVal > rightVal)
					return leftRotate(node);
				if (tempVal < rightVal)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
		}


		//By Year
		else if (typeid(basis).name() == typeid(temp->year).name())
		{
			int tempVal = temp->year;
			int nodeVal = node->year;

			if (tempVal < nodeVal)
				node->left = insert(node->left, temp, basis);
			else if (tempVal > nodeVal)
				node->right = insert(node->right, temp, basis);
			else return node;

			node->height = 1 + max(height(node->left),
				height(node->right));

			int balance = getBalance(node);

			if (balance > 1)
			{
				int leftVal = node->left->year;
				if (tempVal < leftVal)
					return rightRotate(node);
				if (tempVal > leftVal)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}

			}
			if (balance < -1)
			{
				int rightVal = node->right->year;
				if (tempVal > rightVal)
					return leftRotate(node);
				if (tempVal < rightVal)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}
			}
		}

		return node;
	}

	Laptop* deleteNode(Laptop* root, string ISBN)
	{

		if (root == NULL)
			return root;

		if (ISBN < root->ISBN)
			root->left = deleteNode(root->left, ISBN);
		else if (ISBN > root->ISBN)
			root->right = deleteNode(root->right, ISBN);
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				Laptop* temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else
			{
				Laptop* temp = minValueNode(root->right);


				root->ISBN = temp->ISBN;
				root->right = deleteNode(root->right, temp->ISBN);
			}
		}

		if (root == NULL)
			return root;
		root->height = 1 + max(height(root->left), height(root->right));
		int balance = getBalance(root);
		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);
		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	void display(Laptop* root)
	{
		if (root == NULL)
			return;
		else if (root != NULL)
		{
			display(root->left);
			cout << *root;
			display(root->right);
		}
	}

	void displayDescending(Laptop* root)
	{
		if (root == NULL)
			return;
		else if (root != NULL)
		{
			display(root->right);
			cout << *root;
			display(root->left);
		}
	}


	void update(Laptop* root, string ISBN)
	{
		if (root != NULL)
		{
			update(root->left, ISBN);
			if (root->ISBN == ISBN)
			{
				cin >> *root;
			}
			update(root->right, ISBN);
		}
	}

	void search(Laptop* root, string ISBN)
	{
		if (root != NULL)
		{
			search(root->left, ISBN);
			if (root->ISBN == ISBN)
			{
				cout << *root;
			}
			search(root->right, ISBN);
		}
	}
	Laptop* retrieveRoot(Laptop* root, string isbn)
	{
		stack<Laptop*> s;
		Laptop* curr = root;

		while (curr != NULL || s.empty() == false)
		{
			while (curr != NULL)
			{
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			if (curr->ISBN == isbn)
			{
				return curr;
			}
			curr = curr->right;

		}
		return 0;
	}

	void filterByColor(Laptop* root, string color)
	{
		if (root != NULL)
		{
			filterByColor(root->left, color);
			if (root->Color == color)
			{
				cout << *root;
			}
			filterByColor(root->right, color);
		}
	}
	void filterByBrand(Laptop* root, string brand)
	{

		if (root != NULL)
		{
			filterByBrand(root->left, brand);
			if (root->Brand == brand)
			{
				cout << *root;
			}
			filterByBrand(root->right, brand);
		}
	}
};


class Inventory
{
public:
	void AVLtoFile(Laptop* root, ofstream& InventoryFile)
	{
		Laptop data = Laptop();
		if (root == NULL)
		{
			return;
		}
		else if (root != NULL)
		{
			data = root;
			InventoryFile.write((char*)&data, sizeof(data));
			AVLtoFile(root->left, InventoryFile);
			AVLtoFile(root->right, InventoryFile);
		}
	}
	template<typename D>
	Laptop* FiletoAVL(string name, Laptop& data, D type)
	{
		Laptop* root = NULL;
		Laptop* temp = NULL;
		AVL tree;
		ifstream file;
		file.open(name, ios::in);
		if (!file)
			cout << "Error while creating the file";
		else
		{
			file.seekg(0);
			file.read((char*)&data, sizeof(data));
			while (!file.eof())
			{
				temp = tree.newNode(data.ISBN, data.quantity, data.Price, data.Color, data.Brand, data.year, data.StorageCapacity, data.screenSize, data.CameraResolution, data.BatteryLife);
				if (typeid(type).name() == typeid(data.ISBN).name())
					root = tree.insert(root, temp, temp->ISBN);
				else if (typeid(type).name() == typeid(data.Price).name())
					root = tree.insert(root, temp, temp->Price);
				else if (typeid(type).name() == typeid(data.year).name())
					root = tree.insert(root, temp, temp->year);
				file.read((char*)&data, sizeof(data));
			}
		}
		file.close();
		return root;
	}
	bool checkSimilar(Laptop* root, Laptop& data, int flag)
	{
		if (root != NULL)
		{
			if (data == root)
			{
				root->increaseQty();
				flag = 1;
				return 1;
			}
			return checkSimilar(root->left, data, flag);
			return checkSimilar(root->right, data, flag);
		}
		return flag;
	}

	bool validate(Laptop* root, string isbn)
	{
		stack<Laptop*> s;
		Laptop* curr = root;

		while (curr != NULL || s.empty() == false)
		{

			while (curr != NULL)
			{
				s.push(curr);
				curr = curr->left;
			}
			curr = s.top();
			s.pop();
			if (curr->ISBN == isbn)
			{
				return 1;
			}
			curr = curr->right;
		}
		return 0;
	}
};


class Profile
{
protected:
	string userName, password;
public:
	Profile() {}
	virtual bool login() = 0;
	Profile(string userName, string password) :userName(userName), password(password) {}
	void setPassWord(string password) { this->password = password; }
	string get_name() { return userName; }
	string get_password() { return password; }
};

class Admin : public Profile
{
public:
	Admin()
	{
		userName = "admin";
		password = "pass";
	}
	bool login()
	{
		int flag = 0;
		string user, pass;
		system("cls");
		cout << "\n\n\t\t\tLOGIN ";
		cout << "\n\t\t\t-----";
		cout << "\n\n\t\t\tUSERNAME :";
		cin >> user;
		cout << "\n\t\t\tPASSWORD :";
		cin >> pass;


		if (user == userName && pass == password)
		{
			cout << "\n\n\t\t\tLogging In...";
			Sleep(1000);
			system("cls");
			return true;
		}
		else return false;
	}
	string get_name()
	{
		return userName;
	}
};
class shoppingcart
{
public:
	Laptop *head;
	int noofprod;
	float totalcost;
	shoppingcart()
	{
		noofprod = 0;
		totalcost = 0.0;
		head = NULL;
	}
	void addtoCart(Laptop* root, string isbn)
	{
		Laptop* temp = head;
		float p;
		Laptop* n = new Laptop(root,isbn);
		p = root->getPrice();

		totalcost += p;
		noofprod++;

		if (temp == NULL)
		{
			head = n;
			return;
		}
		else
		{
			while (temp->ptr != NULL)
			{
				temp = temp->ptr;
			}
			temp->ptr = n;
		}
	}
	void deleteitems(Laptop *root,string x)
	{
		if (head == NULL)
		{
			cout << "Cart is currently empty" << endl;
			return;
		}
		else
		{
			Laptop *curr = head->ptr;
			Laptop *prev = head;
			//delete from beginning
			if (prev->getISBN() == x)
			{
				head = curr;
				totalcost -= prev->getPrice();
				noofprod--;
				cout << "Item: " << prev->getBrand() << " has been deleted successfully!!" << endl;
				delete prev;
				return;
			}
			//delete from middle
			while (curr != NULL)
			{
				if (curr->getISBN() == x)
				{
					prev->ptr = curr->ptr;
					totalcost -= curr->getPrice();
					noofprod--;
					cout << "Item: " << curr->getBrand()<< " has been deleted successfully!!" << endl;
					delete curr;
					curr = prev->ptr;
					return;
				}
				prev = curr;
				curr = curr->ptr;
			}
			cout << "This item does not exists in the cart" << endl;
		}
	}
	void printing()
	{
		if (head == NULL)
		{
			cout << "There are no items in this cart" << endl;
			return;
		}
		else
		{
			cout << "Total Cost: " << totalcost;
			cout << " No of products: " << noofprod << endl;
			Laptop* temp = head;
			while (temp != NULL)
			{
				temp->display();
				temp = temp->ptr;
			}
			cout << endl;
		}
	}
	bool checkempty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void checkout()
	{
		int ch;
		printing();
		if (checkempty() == 1)
		{
			Sleep(2000);
			return;
		}
		cout << "Select payment method: \n 1- Cash 2- Card ";
		cin >> ch;

		if (ch == 1)
		{
			cout << "Please prepare $" << totalcost << " in cash. Thank you!" << endl;
		}
		else if (ch == 2)
		{
			int num;
			int pincode;
		L2:
			cout << "Enter your card details: " << endl;
			cout << "Enter your Card number (Enter last 4 digits): ";
			cin >> num;

			// Check if the card number is valid
			if (isValidCardNumber(num))
			{
			L1:
				cout << "Enter your PIN code (Enter 4 digits): ";
				cin >> pincode;

				// Check if the PIN code is valid
				if (isValidPin(pincode))
				{
					cout << "Congratulations! Your order is now officially confirmed, Thank you for shopping!!!!" << endl;
				}
				else
				{
					cout << "Invalid PIN code. Payment failed. Please try again." << endl;
					goto L1;
				}

			}
			else
			{
				cout << "Invalid card number. Payment failed. Please try again." << endl;
				goto L2;
			}
		}
		else
		{
			cout << "Invalid choice. Payment failed. Please select a valid payment method." << endl;
		}
	}

	bool isValidCardNumber(long long cardNumber)
	{
		// card number last 4 digits should be enter 
		string cardStr = to_string(cardNumber);
		return (cardStr.length() == 4);
	}

	bool isValidPin(int pincode)
	{
		// pin code last 4 digits 
		string pinStr = to_string(pincode);
		return (pinStr.length() == 4);
	}

};
class User : public Profile
{
public:
	shoppingcart c;
	bool login()
	{
		int flag = 0;
		string user, pass;
		system("cls");
		cout << "\n\n\t\t\tLOGIN ";
		cout << "\n\t\t\t-----";
		cout << "\n\n\t\t\tUSERNAME :";
		cin >> userName;
		cout << "\n\t\t\tPASSWORD :";
		cin >> password;

		ifstream input("User.txt");
		while (input >> user >> pass)
		{
			if (user == userName && pass == password)
			{
				flag = 1;
				cout << "\n\n\t\t\tLogging In...";
				Sleep(1000);
				system("cls");
			}
		}
		input.close();

		if (flag == 1) return true;
		else return false;

	}

	void addtoCart(Laptop* root, string isbn)
	{
		c.addtoCart(root, isbn);
	}
	void deleteCart(Laptop* root, string x)
	{
		c.deleteitems(root,x);
	}
	void printing()
	{
		c.printing();
	}
	void checkout(Laptop *root)
	{
		c.checkout();
	}

};

class Menu
{
public:
	static void showMainPage()
	{
		system("cls");
		cout << "\t\t\t                                                                 \n\n\n";
		cout << "\t\t\t______________________        MAIN        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t\t |          1 Admin           |" << endl;
		cout << "\t\t\t\t\t |          2 User            |" << endl;
		cout << "\t\t\t\t\t |          3 Exit            |" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	static void showAdminMenu(string name)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t      WELCOME ";
		cout << "\n\n\t\t\t  _______________________      " << name << "     ______________________\n\n";
		cout << "\n\n\t\t\t______________________         MENU        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t   |              1 Insert Items                |" << endl;
		cout << "\t\t\t\t   |              2 Update Items                |" << endl;
		cout << "\t\t\t\t   |              3 Remove Items                |" << endl;
		cout << "\t\t\t\t   |              4 Search Items                |" << endl;
		cout << "\t\t\t\t   |              5 Display Items               |" << endl;
		cout << "\t\t\t\t   |              6 Log Out			|" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	static void showUserMenu(string name)
	{
		system("cls");
		cout << "\n\n\t\t\t\t\t\t      WELCOME ";
		cout << "\n\n\t\t\t  _______________________      " << name << "     ______________________\n\n";
		cout << "\n\n\t\t\t______________________         MENU        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t   |              1 Explore                 |" << endl;
		cout << "\t\t\t\t   |              2 View Cart               |" << endl;
		cout << "\t\t\t\t   |              3 Leave Review            |" << endl;
		cout << "\t\t\t\t   |              4 Log Out                 |" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	static void Explore()
	{
		system("cls");
		cout << "\n\n\t\t\t______________________         MENU        ______________________\n\n";
		cout << "                                                                                \n\n";
		cout << "                                S H O W                  \n\n";
		cout << "\t\t\t\t   |           1 By ISBN                       |" << endl;
		cout << "\t\t\t\t   |           2 By Price(ascending)           |" << endl;
		cout << "\t\t\t\t   |           3 By Price(descending)          |" << endl;
		cout << "\t\t\t\t   |           4 Oldest to Newest              |" << endl;
		cout << "\t\t\t\t   |           5 Newest to Oldest              |" << endl << endl << endl;
		cout << "                              F I L T E R                                                  \n\n";
		cout << "\t\t\t\t   |           6 By Color                      |" << endl;
		cout << "\t\t\t\t   |           7 By Brand                      |" << endl << endl << endl;
		cout << "\t\t\t\t   |           (Press 0 to exit)	       |" << endl << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";
	}
	static void Choose()
	{
		cout << "                                                                                \n\n";
		cout << "\t\t\t\t   |           1 Add to Cart           |" << endl;
		cout << "\t\t\t\t   |           2 See Reviews           |" << endl;
		cout << "\t\t\t\t   |           3 Back to Explore       |" << endl;
		cout << "\n\t\t\t\t\t   Please Enter your choice : ";

	}


};


int main()
{

	system("cls");
	cout << "\n\n\n\n\t\t\t\t\t\t E - C O M M E R C E\n\n\t\t\t\t\t\t     S Y S T E M";
	printf("\n\n\n\t\t\t\t\t\t     loading....");
	Sleep(2500);

	srand((unsigned)time(NULL));
	ofstream InventoryAdd;
	Inventory records;
	AVL tree;
	Laptop* root = NULL;
	Laptop* rootSort = NULL;
	Laptop* inputDetails = new Laptop();
	Laptop data;
	string id;

	User user;
	Admin admin;
	shoppingcart c;
	char  menuOption = 0, adminOption = 0, userOption = 0, exploreOption = 0, chooseOption = 0;
	int flag = 0, check = 0;
	static int count = 0;
	fstream file;

	while (1)
	{
		menuOption = 0;
		flag = 0;
		Menu::showMainPage();
		cin >> menuOption;
		cout << endl;
		switch (menuOption)
		{
		case '1'://ADMIN
			if (admin.login())
			{
				//Loading Inventory into AVL tree
				cout << "aaaa";
				root = records.FiletoAVL("Inventory.txt", data, id);

				while (1)
				{
					if (flag == 1) break;
					Menu::showAdminMenu(admin.get_name());
					cin >> adminOption;
					switch (adminOption)
					{
					case '1'://insert items
						system("cls");
						cin >> data;
						if (records.checkSimilar(root, data, 0))
						{
							cout << "Item already exists! Stock Updated\n";
						}
						else
						{
							id = to_string(1 + rand() % 100);
							data.setISBN(id);
							inputDetails = tree.newNode(data.getISBN(), data.getQty(), data.getPrice(), data.getColor(), data.getBrand(), data.getYear(), data.getStorage(), data.getScreen(), data.getCamera(), data.getBattery());
							root = tree.insert(root, inputDetails, inputDetails->getISBN());
						}
						cout << endl << endl << endl;
						system("pause");
						break;
					case '2'://update items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (records.validate(root, data.getISBN()) == 0)
							cout << "\nInvalid ISBN\n";
						else
						{
							tree.update(root, data.getISBN());
							cout << "\nItem Deleted Successfully!\n\n";
						}
						system("pause");
						break;
					case '3'://remove items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (records.validate(root, data.getISBN()) == 0)
							cout << "\nInvalid ISBN\n";
						else
						{
							root = tree.deleteNode(root, data.getISBN());
							cout << "\nItem Deleted Successfully!\n\n";
						}
						//tree.display(root);
						system("pause");
						break;
					case '4'://search items
						system("cls");
						cin >> id;
						data.setISBN(id);
						if (records.validate(root, data.getISBN()) == 0)
							cout << "\nInvalid ISBN\n\n";
						else
							tree.search(root, data.getISBN());
						system("pause");
						break;
					case '5'://display items
						system("cls");
						tree.display(root);
						system("pause");
						break;
					case '6'://log out
						//Loading AVL into Inventory
						InventoryAdd.open("Inventory.txt", ios::out);
						records.AVLtoFile(root, InventoryAdd);
						InventoryAdd.close();
						flag = 1;
						cout << "\n\n\t\t\t\t\t         Logging Off...\n\n";
						Sleep(1000);
						break;
					default:
						cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
						Sleep(1500);
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
			}
			else cout << "\n\t\t\t-Please enter the correct username and password";
			Sleep(1500);
			break;
		case '2'://USER
			if (user.login())
			{
				while (1)
				{
				userMenu:
					if (flag == 2) break;
					flag = 0;
					Menu::showUserMenu(user.get_name());
					cin >> userOption;
					switch (userOption)
					{
					case '1'://Search
					exploreMenu:
						Menu::Explore();
						cin >> exploreOption;
						switch (exploreOption)
						{
						case '0':
							goto userMenu;
							break;
						case '1'://Sort By ISBN
							rootSort = records.FiletoAVL("Inventory.txt", data, id);
							tree.display(rootSort);
							system("pause");
							break;
						case '2'://Sort by Price(ascending)
							rootSort = records.FiletoAVL("Inventory.txt", data, float(1.1));
							tree.display(rootSort);
							system("pause");
							break;
						case '3'://Sort by Price(descending)
							rootSort = records.FiletoAVL("Inventory.txt", data, float(1.1));
							tree.displayDescending(rootSort);
							system("pause");
							break;
						case '4'://Sort by Year(ascending)
							rootSort = records.FiletoAVL("Inventory.txt", data, 1);
							tree.display(rootSort);
							system("pause");
							break;
						case '5'://Sort by Year(descending)
							rootSort = records.FiletoAVL("Inventory.txt", data, 1);
							tree.displayDescending(rootSort);
							system("pause");
							break;
						case '6'://Filter by Color
							cout << "\nEnter Color : ";
							cin >> id;
							check = 0;
							do
							{
								for (int i = 0; i < id.length(); i++)
									id[i] = toupper(id[i]);
								if (id == "BLACK" || id == "WHITE" || id == "SILVER" || id == "BLUE")
									check = 1;
								else
								{
									cout << "\nLaptops in this color arent allowed.Please enter a correct color (Black,Silver,White,Blue) \n" << endl;
									cin >> id;
								}
							} while (check == 0);
							rootSort = records.FiletoAVL("Inventory.txt", data, id);
							tree.filterByColor(rootSort, id);
							system("pause");
							break;
						case '7'://Filter by Brand
							cout << "\nEnter Brand : ";
							cin >> id;
							check = 0;
							do
							{
								for (int i = 0; i < id.length(); i++)
									id[i] = toupper(id[i]);
								if (id == "HP" || id == "DELL" || id == "LENOVO" || id == "APPLE")
									check = 1;
								else
								{
									cout << "\nLaptops in this brand arent allowed.Please enter a correct brand (HP,DELL,LENOVO,APPLE) \n" << endl;
									cin >> id;
								}
							} while (check == 0);
							rootSort = records.FiletoAVL("Inventory.txt", data, id);
							tree.filterByBrand(rootSort, id);
							system("pause");
							break;
						default:
							cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
							Sleep(2000);
							cin.clear();
							cin.ignore(10000, '\n');
							goto exploreMenu;
						}
					chooseAgain:
						Menu::Choose();
						cin >> chooseOption;
						switch (chooseOption)
						{
						case'1'://add to cart
							cout << "\nEnter ISBN : ";
							cin >> id;
							if (records.validate(rootSort, id) == 0)
								cout << "\nInvalid ISBN\n";
							else
							{
								user.addtoCart(tree.retrieveRoot(rootSort, id), id);
							}
							system("pause");
							goto chooseAgain;
						case '2': //see reviews
							cout << "review";
							system("pause");
							goto chooseAgain;
							break;
						case '3'://go back to explore menu
							goto exploreMenu;
							break;
						default:
							cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
							Sleep(2000);
							cin.clear();
							cin.ignore(10000, '\n');
							goto chooseAgain;
						}

						break;
					case '2'://check out(shopping cart)
						
						user.checkout(root);
						system("pause");
						break;
					case '3'://leave reviews
						break;
					case '4'://log off
						flag = 2;
						cout << "\n\n\t\t\t\t\t         Logging Off...\n\n";
						Sleep(1000);
						break;
					default:
						cout << "\n\n\t\t\t\t   Please select from the options given above.\n" << endl;
						Sleep(2000);
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
			}
			else cout << "\n\t\t\t-Please enter the correct username and password";
			Sleep(2000);
			break;
		case '3'://EXIT
			cout << "\t\t\t\t\t\t    Thank You!\n\n";
			exit(0);
			break;
		default:
			cout << "\n\n\t\t\t\t    Please select from the options given above.\n" << endl;
			Sleep(1500);
			cin.clear();//clears buffer
			cin.ignore(1000, '\n');//1000 characters ignore and skip to newline
			break;
		}
	}
}
