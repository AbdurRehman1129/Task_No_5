#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
	string UniqueID;
	string status;
public:
	string BookType;

	Book(string UiD, string St, string BT) { UniqueID = UiD;status = St;BookType = BT; }
	string getUniqueID() { return UniqueID; }
	string getStatus() { return status; }
	string displayDetails()
	{
		return "LIBRARY MANAGEMENT SYSTEM\n\n" + BookType + "\nBook Unique ID : " + getUniqueID() + "\nBook Status : " + getStatus();
	}

};
class PrintedBook :protected Book
{
private:
	int pages;
	string printDate;
public:
	PrintedBook(string BT, string UiD, string St, int pg, string pd) :Book(UiD, St, BT) { pages = pg;printDate = pd; }
	int getPages() { return pages; }
	string getPrintDate() { return printDate; }
	string displayDetails()
	{
		return Book::displayDetails() + "\nNo of Pages of Printed Book : " + to_string(getPages()) + "\nBook is printed on : " + getPrintDate();
	}


	void modifyDetails()
	{
		char choice;
		cout << "\n\What do you want to Modify? " << endl;
		cout << "1-Unique ID " << endl;
		cout << "2-Status " << endl;
		cout << "3-No of Pages " << endl;
		cout << "4-Print Date " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Enter new Unique ID : ";
			cin >> UniqueID;
			this->UniqueID = UniqueID;
			break;
		case '2':
			cout << "Enter new Status : ";
			cin >> status;
			this->status = status;
			break;
		case '3':
			cout << "Enter new no of Pages : ";
			cin >> pages;
			this->pages = pages;
			break;
		case '4':
			cout << "Enter new Print Date : ";
			cin >> printDate;
			this->printDate = printDate;
			break;

		default:
			cout << "Invalid Input";

		}

		cout << "\n" + PrintedBook::displayDetails() + "\n";
	}
};
class EBook :protected Book
{
private:
	int size;
	string format;
public:
	EBook(string BT, string UiD, string St, int S, string fm) :Book(UiD, St, BT) { size = S;format = fm; }
	int getSize() { return size; }
	string getFormat() { return format; }
	string displayDetails()
	{
		return Book::displayDetails() + "\nSize of EBook : " + to_string(getSize()) + "MB" + "\nFormat of EBook : " + getFormat();
	}
	void modifyEbook()
	{
		char choice;
		cout << "\n\nWhich do you want to Modify? " << endl;
		cout << "1-Unique ID " << endl;
		cout << "2-Status " << endl;
		cout << "3-Size " << endl;
		cout << "4-Format " << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "Enter new Unique ID : ";
			cin >> UniqueID;
			this->UniqueID = UniqueID;
			break;
		case '2':
			cout << "Enter new Status : ";
			cin >> status;
			this->status = status;
			break;
		case '3':
			cout << "Enter new Size : ";
			cin >> size;
			this->size = size;
			break;
		case '4':
			cout << "Enter new Format : ";
			cin >> format;
			this->format = format;
			break;

		default:
			cout << "Invalid Input";

		}
		cout << "\n" + EBook::displayDetails() + "\n";

	}
};

int main()
{
	PrintedBook printedBook("PRINTED BOOK DETAILS", "AZ211", "Available", 340, "24 Jun");
	EBook eBook("EBOOK  DETAILS", "WS332", "Available", 340, "PDF");
	cout << printedBook.displayDetails();
	cout << "\n\n" + eBook.displayDetails();
	char choice;
	cout << "\n\nWhich Class do you want to Modify? " << endl;
	cout << "a-PrintedBook  " << endl;
	cout << "b-EBook  " << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 'a':
		printedBook.modifyDetails();
		break;
	case 'b':
		eBook.modifyEbook();
	default:
		cout << "Invalid Input ";
	}
	return 0;
}

