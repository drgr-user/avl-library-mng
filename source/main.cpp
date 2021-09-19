#include <cstdlib>
#include "headers/Library.h"

using namespace std;

int main() {
	cout << "\t\t\t *** loading data...";
	Library library;
	string id;
	char menu = 'i';
	while (menu != '0') {
		system("cls");
		cout << "\n\t *** Library System *** \n";
		cout << "\t *** 1- Show all info \n";
		cout << "\t *** 2- Add or delete a book \n";
		cout << "\t *** 3- Add or delete a member \n";
		cout << "\t *** 4- Search for book \n";
		cout << "\t *** 5- Search for member \n";
		cout << "\t *** 6- Edit a book or a member \n";
		cout << "\t *** 7- Rent or return a book\n";
		cout << "\t *** 8- Reserve information\n";
		cout << "\t *** 9- Add or pay Debt\n";
		cout << "\t *** 0- Exit \n";
		cout << "\t *** Your choice: ";
		cin >> menu;
		switch (menu) {
		case '1':
			char sub_menu_1;
			cout << "\t\t *** 1- Show all books \n";
			cout << "\t\t *** 2- Show all members \n";
			cout << "\t\t *** 3- Unavailable books \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_1;
			system("cls");
			if (sub_menu_1 == '1')
				library.ShowAllBooks();
			else if (sub_menu_1 == '2')
				library.ShowAllMembers();
			else if (sub_menu_1 == '3')
				library.ShowUnavailableBooks();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '2':
			char sub_menu_2;
			cout << "\t\t *** 1- Add a book \n";
			cout << "\t\t *** 2- Delete a book \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_2;
			system("cls");
			if (sub_menu_2 == '1')
				library.AddBook();
			else if (sub_menu_2 == '2')
				library.DeleteBookById();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '3':
			char sub_menu_3;
			cout << "\t\t *** 1- Add a member \n";
			cout << "\t\t *** 2- Delete a member \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_3;
			system("cls");
			if (sub_menu_3 == '1')
				library.AddMember();
			else if (sub_menu_3 == '2')
				library.DeleteMemberById();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '4':
			char sub_menu_4;
			cout << "\t\t *** 1- Search by id \n";
			cout << "\t\t *** 2- Search by book name\n";
			cout << "\t\t *** 3- Search by isbn\n";
			cout << "\t\t *** 4- Search for an author\n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_4;
			system("cls");
			if (sub_menu_4 == '1')
				library.SearchForBookById();
			else if (sub_menu_4 == '2')
				library.SearchForBookByName();
			else if (sub_menu_4 == '3')
				library.SearchForBookByIsbn();
			else if (sub_menu_4 == '4')
				library.SearchBookByAuthor();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '5':
			char sub_menu_5;
			cout << "\t\t *** 1- Search by library id \n";
			cout << "\t\t *** 2- Search by personal id \n";
			cout << "\t\t *** 3- Search by date joined \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_5;
			system("cls");
			if (sub_menu_5 == '1')
				library.SearchForMemberById();
			else if (sub_menu_5 == '2')
				library.SearchForMemberByPid();
			else if (sub_menu_5 == '3')
				library.SearchMemberByJoinedDate();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '6':
			char sub_menu_6;
			cout << "\t\t *** 1- Edit a book \n";
			cout << "\t\t *** 2- Edit a member \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_6;
			system("cls");
			if (sub_menu_6 == '1')
				library.EditBook();
			else if (sub_menu_6 == '2')
				library.EditMember();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '7':
			char sub_menu_7;
			cout << "\t\t *** 1- Rent a book \n";
			cout << "\t\t *** 2- Return a book \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_7;
			system("cls");
			if (sub_menu_7 == '1')
				library.RentBook();
			else if (sub_menu_7 == '2')
				library.ReturnBook();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '8':
			char sub_menu_8;
			cout << "\t\t *** 1- Search for a reservation file \n";
			cout << "\t\t *** 2- Edit a reservation file \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_8;
			system("cls");
			if (sub_menu_8 == '1')
				library.SearchForReserveById();
			else if (sub_menu_8 == '2')
				library.EditReserve();
			else
				cout << "invalid input.";
			system("pause");
			break;
		case '9':
			char sub_menu_9;
			cout << "\t\t *** 1- Search for a reservation file \n";
			cout << "\t\t *** 2- Edit a reservation file \n";
			cout << "\t\t *** Your choice: ";
			cin >> sub_menu_9;
			system("cls");
			if (sub_menu_9 == '1')
				library.PayDebt();
			else if (sub_menu_9 == '2')
				library.AddDebt();
			else
				cout << "invalid input.";
			system("pause");
			break;
		}
	}
	system("cls");
	system("pause");
	return 0;


	return 0;
}