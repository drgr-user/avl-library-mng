#include "Book.h"
#include "Member.h"

using namespace std;


class Library {
private:
	
	Book* book_tree_head = nullptr;
	Member* member_tree_head = nullptr;
	string book_file_addr = "book_data_file.txt";
	string member_file_addr = "member_data_file.txt";
	string reservation_file_addr = "reservation_file.txt";

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
  
	int max_finder_for_book(int a, int b);
	int max_finder_for_member(int a, int b);
  
	int height(Book *N){
		if (N == NULL)
			return 0;
		return (N->GetHeight());
	}

	int height(Member *N){
		if (N == NULL)
			return 0;
		return (N->GetHeight());
	}

	int height(Reservation_file *N){
		if (N == NULL)
			return 0;
		return (N->GetHeight());
	}

	Book* NewNode(Book_data temp_book_data){
		Book* node = new Book();
		node->SetBookData(temp_book_data);
		node->SetLeftChild(nullptr);
		node->SetRightChild(nullptr);
		node->SetHeight(1); // new node is added at leaf  
		return (node);
	}

	Member* NewNode(Member_data temp_member_data){
		Member* node = new Member();
		node->SetMemberData(temp_member_data);
		node->SetLeftChild(nullptr);
		node->SetRightChild(nullptr);
		node->SetHeight(1);  
		return (node);
	}

	Reservation_file* NewNode(reservation_data temp_member_data){
		Reservation_file* node = new Reservation_file();
		node->SetReservationData(temp_member_data);
		node->SetLeftChild(nullptr);
		node->SetRightChild(nullptr);
		node->SetHeight(1);  
		return (node);
	}
  
	Book *RightRotate(Book *y){
		Book *x = new Book;
		x = y->GetLeftChild();
		Book *T2 = new Book;
		T2 = x->GetRightChild();
  
		x->SetRightChild(y);
		y->SetLeftChild(T2);
  
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
  
		return x;
	}

	Member *RightRotate(Member *y){
		Member *x = y->GetLeftChild();
		Member *T2 = x->GetRightChild();
  
		x->SetRightChild(y);
		y->SetLeftChild(T2);
  
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
  
		return x;
	}

	Reservation_file *RightRotate(Reservation_file *y){
		Reservation_file *x = y->GetLeftChild();
		Reservation_file *T2 = x->GetRightChild();
  
		x->SetRightChild(y);
		y->SetLeftChild(T2);
  
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
 
		return x;
	}
  
	Book *LeftRotate(Book *x){
		Book *y = new Book;
		y = x->GetRightChild();
		Book *T2 = new Book;
		T2 = y->GetLeftChild();

		y->SetLeftChild(x);
		x->SetRightChild(T2);
  
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
  
		return y;
	}

	Member *LeftRotate(Member *x){
		Member *y = x->GetRightChild();
		Member *T2 = y->GetLeftChild();
  
		y->SetLeftChild(x);
		x->SetRightChild(T2);
  
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
  
		return y;
	}

	Reservation_file *LeftRotate(Reservation_file *x){
		Reservation_file *y = x->GetRightChild();
		Reservation_file *T2 = y->GetLeftChild();
  
		y->SetLeftChild(x);
		x->SetRightChild(T2);
  
		x->SetHeight(max(height(x->GetLeftChild()), height(x->GetRightChild())) + 1);
		y->SetHeight(max(height(y->GetLeftChild()), height(y->GetRightChild())) + 1);
  
		return y;
	}
  
	int GetBalanceFactor(Book *N){
		if (N == nullptr)
			return 0;
		return (height(N->GetLeftChild()) - height(N->GetRightChild()));
	}

	int GetBalanceFactor(Member *N){
		if (N == nullptr)
			return 0;
		return (height(N->GetLeftChild()) - height(N->GetRightChild()));
	}

	int GetBalanceFactor(Reservation_file *N){
		if (N == nullptr)
			return 0;
		return (height(N->GetLeftChild()) - height(N->GetRightChild()));
	}

	Book * MinValueNode(Book* node){
		Book* current = node;

		/* loop down to find the leftmost leaf */
		while (current->GetLeftChild() != nullptr)
			current = current->GetLeftChild();

		return current;
	}

	Member * MinValueNode(Member* node){
		Member* current = node;

		while (current->GetLeftChild() != nullptr)
			current = current->GetLeftChild();

		return current;
	}

	Reservation_file * MinValueNode(Reservation_file* node){
		Reservation_file* current = node;

		while (current->GetLeftChild() != nullptr)
			current = current->GetLeftChild();

		return current;
	}
 
	Book* Insert(Book* head, Book new_book_to_insert) {
		//Perform BST insertion
		if (head == nullptr)
			return(NewNode(new_book_to_insert.GetBookData()));

		if (new_book_to_insert.GetBookData().book_id < head->GetBookData().book_id)
			head->SetLeftChild(Insert(head->GetLeftChild(), new_book_to_insert));
		else if (new_book_to_insert.GetBookData().book_id > head->GetBookData().book_id)
			head->SetRightChild(Insert(head->GetRightChild(), new_book_to_insert));
		else //Keys can not be equal in BST  
			return head;

		//Update height of this ancestor node
		head->SetHeight(1 + max(height(head->GetLeftChild()), height(head->GetRightChild())));

		// Check if this node is unbalanced   
		int balance = GetBalanceFactor(head);
		// Left Left Case  
		if (balance > 1 && new_book_to_insert.GetBookData().book_id < head->GetLeftChild()->GetBookData().book_id)
			head = RightRotate(head);
		// Right Right Case  
		else if (balance < -1 && new_book_to_insert.GetBookData().book_id > head->GetRightChild()->GetBookData().book_id)
			head = LeftRotate(head);
		// Left Right Case  
		else if (balance > 1 && new_book_to_insert.GetBookData().book_id > head->GetLeftChild()->GetBookData().book_id){
			head->SetLeftChild(LeftRotate(head->GetLeftChild()));
			head = RightRotate(head);
		}
		// Right Left Case  
		else if (balance < -1 && new_book_to_insert.GetBookData().book_id < head->GetRightChild()->GetBookData().book_id){
			head->SetRightChild(RightRotate(head->GetRightChild()));
			head = LeftRotate(head);
		}
		/* return the (unchanged) node pointer */
		return head;
	}

	Member* Insert(Member* head, Member new_member_to_insert) {
		if (head == nullptr)
			return(NewNode(new_member_to_insert.GetMemberData()));

		if (new_member_to_insert.GetMemberData().library_id < head->GetMemberData().library_id)
			head->SetLeftChild(Insert(head->GetLeftChild(), new_member_to_insert));
		else if (new_member_to_insert.GetMemberData().library_id > head->GetMemberData().library_id)
			head->SetRightChild(Insert(head->GetRightChild(), new_member_to_insert));
		else
			return head;

		head->SetHeight(1 + max(height(head->GetLeftChild()), height(head->GetRightChild())));

		int balance = GetBalanceFactor(head);
 
		if (balance > 1 && new_member_to_insert.GetMemberData().library_id < head->GetLeftChild()->GetMemberData().library_id)
			head = RightRotate(head); 
		else if (balance < -1 && new_member_to_insert.GetMemberData().library_id > head->GetRightChild()->GetMemberData().library_id)
			head = LeftRotate(head); 
		else if (balance > 1 && new_member_to_insert.GetMemberData().library_id > head->GetLeftChild()->GetMemberData().library_id){
			head->SetLeftChild(LeftRotate(head->GetLeftChild()));
			head = RightRotate(head);
		} 
		else if (balance < -1 && new_member_to_insert.GetMemberData().library_id < head->GetRightChild()->GetMemberData().library_id){
			head->SetRightChild(RightRotate(head->GetRightChild()));
			head = LeftRotate(head);
		}

		return head;
	}

	Reservation_file* Insert(Reservation_file* head, Reservation_file new_member_to_insert) {
		if (head == nullptr)
			return(NewNode(new_member_to_insert.GetReservationData()));

		if (new_member_to_insert.GetReservationData().reserve_id < head->GetReservationData().reserve_id)
			head->SetLeftChild(Insert(head->GetLeftChild(), new_member_to_insert));
		else if (new_member_to_insert.GetReservationData().reserve_id > head->GetReservationData().reserve_id)
			head->SetRightChild(Insert(head->GetRightChild(), new_member_to_insert));
		else 
			return head;

		head->SetHeight(1 + max(height(head->GetLeftChild()), height(head->GetRightChild())));

		int balance = GetBalanceFactor(head);
 
		if (balance > 1 && new_member_to_insert.GetReservationData().reserve_id < head->GetLeftChild()->GetReservationData().reserve_id)
			head = RightRotate(head); 
		else if (balance < -1 && new_member_to_insert.GetReservationData().reserve_id > head->GetRightChild()->GetReservationData().reserve_id)
			head = LeftRotate(head);
		else if (balance > 1 && new_member_to_insert.GetReservationData().reserve_id > head->GetLeftChild()->GetReservationData().reserve_id){
			head->SetLeftChild(LeftRotate(head->GetLeftChild()));
			head = RightRotate(head);
		} 
		else if (balance < -1 && new_member_to_insert.GetReservationData().reserve_id < head->GetRightChild()->GetReservationData().reserve_id){
			head->SetRightChild(RightRotate(head->GetRightChild()));
			head = LeftRotate(head);
		}

		return head;
	}
 
	Book* DeleteNode(Book* root, Book book_for_deletion){

		//Perform BST deletion  
		if (root == nullptr)
			return root;

		if (book_for_deletion.GetBookData().book_id < root->GetBookData().book_id)
			root->SetLeftChild(DeleteNode(root->GetLeftChild(), book_for_deletion));
  
		else if (book_for_deletion.GetBookData().book_id > root->GetBookData().book_id)
			root->SetRightChild(DeleteNode(root->GetRightChild(), book_for_deletion));
  
		else{
			// Node with one child or no child  
			if ((root->GetLeftChild() == nullptr) ||
				(root->GetRightChild() == nullptr)){
				Book *temp = root->GetLeftChild() ?
					root->GetLeftChild() :
					root->GetRightChild();

				// No child case  
				if (temp == nullptr){
					temp = root;
					root = nullptr;
				}
				// One child case
				else   
					*root = *temp; 
				free(temp);
			}
			else{
				// Node with two children  
				Book* temp = MinValueNode(root->GetRightChild());
				root->SetBookData(temp->GetBookData());  
				root->SetRightChild(DeleteNode(root->GetRightChild(), *temp));
			}
		}

		// Return if the tree had only one node   
		if (root == nullptr)
			return root;
  
		root->SetHeight(1 + max(height(root->GetLeftChild()), height(root->GetRightChild())));

		// Check if this node is unbalanced
		int balance = GetBalanceFactor(root);
		// Left Left Case  
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) >= 0)
			return RightRotate(root);
		// Left Right Case  
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) < 0){
			root->SetLeftChild(LeftRotate(root->GetLeftChild()));
			return RightRotate(root);
		}
		// Right Right Case  
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) <= 0)
			return LeftRotate(root);
		// Right Left Case  
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) > 0){
			root->SetRightChild(RightRotate(root->GetRightChild()));
			return LeftRotate(root);
		}

		return root;
	}

	Member* DeleteNode(Member* root, Member book_for_deletion){
  
		if (root == nullptr)
			return root;
 
		if (book_for_deletion.GetMemberData().library_id < root->GetMemberData().library_id)
			root->SetLeftChild(DeleteNode(root->GetLeftChild(), book_for_deletion));
		else if (book_for_deletion.GetMemberData().library_id > root->GetMemberData().library_id)
			root->SetRightChild(DeleteNode(root->GetRightChild(), book_for_deletion));
		else{  
			if ((root->GetLeftChild() == nullptr) ||
				(root->GetRightChild() == nullptr)){
				Member *temp = root->GetLeftChild() ?
					root->GetLeftChild() :
					root->GetRightChild();
  
				if (temp == nullptr){
					temp = root;
					root = nullptr;
				}
				else 
					*root = *temp;
				free(temp);
			}
			else{  
				Member* temp = MinValueNode(root->GetRightChild());
				root->SetMemberData(temp->GetMemberData()); 
				root->SetRightChild(DeleteNode(root->GetRightChild(), *temp));
			}
		}
 
		if (root == nullptr)
			return root;
  
		root->SetHeight(1 + max(height(root->GetLeftChild()), height(root->GetRightChild())));
		int balance = GetBalanceFactor(root);
 
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) >= 0)
			return RightRotate(root);
 
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) < 0){
			root->SetLeftChild(LeftRotate(root->GetLeftChild()));
			return RightRotate(root);
		}
 
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) <= 0)
			return LeftRotate(root);
  
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) > 0){
			root->SetRightChild(RightRotate(root->GetRightChild()));
			return LeftRotate(root);
		}

		return root;
	}

	Reservation_file* DeleteNode(Reservation_file* root, Reservation_file book_for_deletion){
  
		if (root == nullptr)
			return root;
 
		if (book_for_deletion.GetReservationData().reserve_id < root->GetReservationData().reserve_id)
			root->SetLeftChild(DeleteNode(root->GetLeftChild(), book_for_deletion));
 
		else if (book_for_deletion.GetReservationData().reserve_id > root->GetReservationData().reserve_id)
			root->SetRightChild(DeleteNode(root->GetRightChild(), book_for_deletion));
 
		else{
			if ((root->GetLeftChild() == nullptr) ||
				(root->GetRightChild() == nullptr)){
				Reservation_file *temp = root->GetLeftChild() ?
					root->GetLeftChild() :
					root->GetRightChild();
  
				if (temp == nullptr){
					temp = root;
					root = nullptr;
				}
				else  
					*root = *temp;  
				free(temp);
			}
			else{  
				Reservation_file* temp = MinValueNode(root->GetRightChild());
				root->SetReservationData(temp->GetReservationData());
				root->SetRightChild(DeleteNode(root->GetRightChild(), *temp));
			}
		}
 
		if (root == nullptr)
			return root;
 
		root->SetHeight(1 + max(height(root->GetLeftChild()), height(root->GetRightChild())));
		int balance = GetBalanceFactor(root);
 
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) >= 0)
			return RightRotate(root);
 
		if (balance > 1 &&
			GetBalanceFactor(root->GetLeftChild()) < 0){
			root->SetLeftChild(LeftRotate(root->GetLeftChild()));
			return RightRotate(root);
		}
  
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) <= 0)
			return LeftRotate(root);
  
		if (balance < -1 &&
			GetBalanceFactor(root->GetRightChild()) > 0){
			root->SetRightChild(RightRotate(root->GetRightChild()));
			return LeftRotate(root);
		}

		return root;
	}


public:
	int book_counter, member_counter, reservation_counter = 0;
	int last_book_id, last_member_id, last_reserv_id = 0;
	vector<Member*> member_vector;
	vector<Book*> book_vector;
	vector<Reservation_file*> reserv_vector;

	//Constructor
	Library() {
		ReadInputTxt();
	}
	
	//Get Data
	Book* GetBookTreeHead() {
		return book_tree_head;
	}
	Member* GetMemberTreeHead() {
		return member_tree_head;
	}

	//Set Data
	void SetBookTreeHead(Book* entry_book_tree_head_ptr) {
		this->book_tree_head = entry_book_tree_head_ptr;
	}
	void SetMemberTreeHead(Member* entry_member_tree_head_ptr) {
		this->member_tree_head = entry_member_tree_head_ptr;
	}

	Member* SearchById(Member* head ,string id) {
		if (head != nullptr) {
			if (head->GetMemberData().library_id == stoi(id))
				return(head);
			else if (stoi(id) < head->GetMemberData().library_id)
				return(SearchById(head->GetLeftChild(), id));
			else
				return(SearchById(head->GetRightChild(), id));
		}
		else
			return(nullptr);
	}

	Reservation_file* SearchById(Reservation_file* head, string id) {
		if (head != nullptr) {
			if (head->GetReservationData().reserve_id == stoi(id))
				return(head);
			else if (stoi(id) < head->GetReservationData().reserve_id)
				return(SearchById(head->GetLeftChild(), id));
			else
				return(SearchById(head->GetRightChild(), id));
		}
		else
			return(nullptr);
	}

	Book* SearchById(Book* head, string id) {
		if (head != nullptr) {
			if (head->GetBookData().book_id == stoi(id))
				return(head);
			else if (stoi(id) < head->GetBookData().book_id)
				return(SearchById(head->GetLeftChild(), id));
			else
				return(SearchById(head->GetRightChild(), id));
		}
		else
			return(nullptr);
	}

	vector<Book*> SearchByName(Book* head, string name, vector<Book*> results) {
		if (head != nullptr) {
			if (head->GetBookData().name == name)
				results.push_back(head);
			results = SearchByName(head->GetRightChild(), name, results);
			results = SearchByName(head->GetLeftChild(), name, results);
		}
		return results;
	}

	vector<Book*> SearchByIsbn(Book* head, string isbn, vector<Book*> results) {
		if (head != nullptr) {
			if (head->GetBookData().isbn == isbn)
				results.push_back(head);
			results = SearchByIsbn(head->GetRightChild(), isbn, results);
			results = SearchByIsbn(head->GetLeftChild(), isbn, results);
		}
		return results;
	}

	vector<Book*> SearchByAuthor(Book* head, string name, vector<Book*> results) {
		if (head != nullptr) {
			if (head->GetBookData().author == name)
				results.push_back(head);
			results = SearchByAuthor(head->GetRightChild(), name, results);
			results = SearchByAuthor(head->GetLeftChild(), name, results);
		}
		return results;
	}
	
	vector<Member*> SearchByPid(Member* head, string pid, vector<Member*> results) {
		if (head != nullptr) {
			if (head->GetMemberData().personal_id == pid)
				results.push_back(head);
			results = SearchByPid(head->GetRightChild(), pid, results);
			results = SearchByPid(head->GetLeftChild(), pid, results);
		}
		return results;
	}

	vector<Member*> SearchByDateJoined(Member* head, string date1_year_str , string date1_month_str , string date1_day_str,
											string date2_year_str , string date2_month_str , string date2_day_str , 
											vector<Member*> results) {
		if (head != nullptr) {
			
			string datej = head->GetMemberData().date_joined;
			stringstream datej_stream(datej);
			string segment;
			vector<std::string> seglist;
			while (getline(datej_stream, segment, '-'))
			{
				seglist.push_back(segment);
			}
			string datej_year_string = seglist[0];
			string datej_month_string = seglist[1];
			string datej_day_string = seglist[2];
			
			double datej_year = stoi(datej_year_string) * 31536000;
			double datej_month = stoi(datej_month_string) * 2628002.88;
			double datej_day = stoi(datej_day_string) * 86400;

			double date1_year = stoi(date1_year_str) * 31536000;
			double date1_month = stoi(date1_month_str) * 2628002.88;
			double date1_day = stoi(date1_day_str) * 86400;

			double date2_year = stoi(date2_year_str) * 31536000;
			double date2_month = stoi(date2_month_str) * 2628002.88;
			double date2_day = stoi(date2_day_str) * 86400;

			if (date1_year + date1_month + date1_day <= datej_year + datej_month + datej_day
				<= date2_year + date2_month + date2_day) {
				results.push_back(head);
			}

			results = SearchByDateJoined(head->GetRightChild(), date1_year_str, date1_month_str,  date1_day_str,
				 date2_year_str, date2_month_str, date2_day_str ,results);
			results = SearchByDateJoined(head->GetLeftChild(), date1_year_str, date1_month_str, date1_day_str,
				date2_year_str, date2_month_str, date2_day_str, results);
		}
		return results;
	}

	void ReadInputTxt() {

		string temp_line;
		ifstream book_data_file, member_data_file, reservation_data_file;
		member_data_file.open(member_file_addr, ios::in);

		Member_data member_data_temp;

		while (getline(member_data_file, temp_line)) {
			stringstream temp_line_stream(temp_line);
			string segment;
			vector<std::string> seglist;

			while (getline(temp_line_stream, segment, '#'))
			{
				seglist.push_back(segment);
			}

			member_data_temp.library_id = stoi(seglist[0]);
			if (member_data_temp.library_id > last_member_id)
				last_member_id = member_data_temp.library_id;
			member_data_temp.name = seglist[1];
			member_data_temp.personal_id = seglist[2];
			member_data_temp.date_joined = seglist[3];
			member_data_temp.debt = seglist[4];

			Member* new_member = new Member;
			new_member->SetMemberData(member_data_temp);

			member_vector.push_back(new_member);
		}
		
		member_counter = member_vector.size();

		for (int i = 0; i < member_counter; i++) {
			member_tree_head = Insert(member_tree_head, *member_vector[i]);
		}

		book_data_file.open(book_file_addr, ios::in);
		Book_data book_data_temp;

		while (getline(book_data_file, temp_line)) {

			stringstream temp_line_stream(temp_line);
			string segment;
			vector<std::string> seglist;

			while (getline(temp_line_stream, segment, '#'))
			{
				seglist.push_back(segment);
			}

			book_data_temp.book_id = stoi(seglist[0]);
			if (book_data_temp.book_id > last_book_id)
				last_book_id = book_data_temp.book_id;
			book_data_temp.name = seglist[1];
			book_data_temp.author = seglist[2];
			book_data_temp.publication = seglist[3];
			book_data_temp.translator = seglist[4];
			book_data_temp.isbn = seglist[5];
			book_data_temp.publish_year = seglist[6];
			book_data_temp.state = stoi(seglist[7]);
			book_data_temp.person_id = seglist[8];
			book_data_temp.reserve_file_id = stoi(seglist[9]);

			Book* new_book = new Book;
			new_book->SetBookData(book_data_temp);

			book_vector.push_back(new_book);
		}

		book_counter = book_vector.size();

		for (int i = 0; i < book_counter; i++) {
			book_tree_head = Insert(book_tree_head, *book_vector[i]);
		}

		reservation_data_file.open(reservation_file_addr, ios::in);
		reservation_data reservation_data_temp;

		while (getline(reservation_data_file, temp_line)) {

			stringstream temp_line_stream(temp_line);
			string segment;
			vector<std::string> seglist;

			while (getline(temp_line_stream, segment, '#'))
			{
				seglist.push_back(segment);
			}

			reservation_data_temp.person_id = seglist[0];
			reservation_data_temp.reserve_id = stoi(seglist[1]);
			if (reservation_data_temp.reserve_id > last_reserv_id)
				last_reserv_id = reservation_data_temp.reserve_id;
			reservation_data_temp.borrow_date = seglist[2];
			reservation_data_temp.return_date = seglist[3];
			reservation_data_temp.book_id = seglist[4];
			reservation_data_temp.state = seglist[5];

			Reservation_file* new_reservation_file = new Reservation_file;
			new_reservation_file->SetReservationData(reservation_data_temp);

			reserv_vector.push_back(new_reservation_file);
		}

		reservation_counter = reserv_vector.size();
		Member* temp_member_to_assign_reserve_file = new Member;
		
		for (int i = 0; i < reservation_counter; i++) {
			temp_member_to_assign_reserve_file = SearchById(member_tree_head, reserv_vector[i]->GetReservationData().person_id);
			if (temp_member_to_assign_reserve_file != nullptr) {
			temp_member_to_assign_reserve_file->SetMemberReservationFileHead(Insert
			(temp_member_to_assign_reserve_file->GetMemberReservationFile(), *reserv_vector[i]));
			}
		}

	}

	void InOrder(Book* node) {
		if (node != nullptr) {
			InOrder(node->GetLeftChild());

			Book_data temp_book_data = node->GetBookData();
			cout << "\n\t" << temp_book_data.book_id << " " << temp_book_data.name
				 << " " << temp_book_data.author << " " << temp_book_data.state <<endl;
			InOrder(node->GetRightChild());
		}

	}
	
	void InOrder(Member* node) {
		if (node != nullptr) {
			InOrder(node->GetLeftChild());

			Member_data temp_member_data = node->GetMemberData();
			cout << "\n\t" << temp_member_data.library_id << " " << temp_member_data.name
				<< " " << temp_member_data.date_joined << " " << temp_member_data.debt << endl;
			InOrder(node->GetRightChild());
		}

	}

	void ShowAllBooks() {
		Book* book_tree_head = GetBookTreeHead();
		InOrder(book_tree_head);
	}

	void ShowAllMembers() {
		Member* member_tree_head = GetMemberTreeHead();
		InOrder(member_tree_head);
	}

	void AddBook() {
		cout << "\n\t\t Enter information for new book:\n";
		Book_data new_book_data;
		cout << "\t Enter book name: "; cin >> new_book_data.name;
		cout << "\t Enter author name: "; cin >> new_book_data.author;
		cout << "\t Enter isbn: "; cin >> new_book_data.isbn;
		cout << "\t Enter publish year: "; cin >> new_book_data.publish_year;
		cout << "\t Enter publication name: "; cin >> new_book_data.publication;
		cout << "\t Enter translator name: "; cin >> new_book_data.translator;
		
		book_counter++;
		last_book_id++;
		new_book_data.book_id = last_book_id;

		Book new_book;
		new_book.SetBookData(new_book_data);

		Insert(book_tree_head, new_book);

		UpdateData();
	}
	
	void AddMember() {
		cout << "\n\t\t Enter information for new book:\n";
		Member_data new_member_data;
		cout << "\t Enter member name: "; cin >> new_member_data.name;
		cout << "\t Enter member personal id: "; cin >> new_member_data.personal_id;
		cout << "\t Enter join date "; cin >> new_member_data.date_joined;
		
		new_member_data.debt = "0";

		member_counter++;
		last_member_id++;
		new_member_data.library_id = last_member_id;

		Member new_member;
		new_member.SetMemberData(new_member_data);

		Insert(member_tree_head, new_member);

		UpdateData();
	}

	void DeleteBookById() {
		string id;
		cout << "\n\t\tEnter book id for deletion: ";
		cin >> id;
		Book_data temp_book_data;
		temp_book_data.book_id = stoi(id);
		Book temp_book;
		temp_book.SetBookData(temp_book_data);

		DeleteNode(book_tree_head, temp_book);

		UpdateData();
	}

	void DeleteMemberById() {
		string id;
		cout << "\n\t\tEnter member id for deletion: ";
		cin >> id;
		Member_data temp_member_data;
		temp_member_data.library_id = stoi(id);
		Member temp_member;
		temp_member.SetMemberData(temp_member_data);

		DeleteNode(member_tree_head, temp_member);
		
		UpdateData();
	}

	void SearchForBookById() {
		string id;
		cout << "Enter book id: ";
		cin >> id; cout << "\nResult: \n";
		Book* result = SearchById(book_tree_head, id);
		if (result != nullptr) {
			cout << result->GetBookData().book_id << "\t" << result->GetBookData().name << "\t"
				<< result->GetBookData().author << "\t" << result->GetBookData().isbn << "\t"
				<< result->GetBookData().state << "\n";
			cout << "Borrowed to: " << result->GetBookData().person_id << endl;
			cout << "Reservation id:" << result->GetBookData().reserve_file_id << endl;
		}
		else {
			cout << "Not found.\n";
		}
		system("pause");
	}

	void SearchForBookByName() {
		string name;
		cout << "Enter book name: ";
		cin >> name; cout << "\nResult: \n";
		vector<Book*> results;
		results = SearchByName(book_tree_head, name, results);
		if (results.size() != 0) {
			for (int i = 0; i < results.size(); i++) {
				cout << results[i]->GetBookData().book_id << "\t" << results[i]->GetBookData().name << "\t"
					<< results[i]->GetBookData().author << "\t" << results[i]->GetBookData().state << "\n";
			}
		}
		else
			cout << "Not found.\n";
		system("pause");

	}

	void SearchForBookByIsbn() {
		string isbn;
		cout << "Enter book isbn: ";
		cin >> isbn; cout << "\nResult: \n";
		vector<Book*> results;
		results = SearchByIsbn(book_tree_head, isbn, results);
		if (results.size() != 0) {
			for (int i = 0; i < results.size(); i++) {
				cout << results[i]->GetBookData().book_id << "\t" << results[i]->GetBookData().name << "\t"
					<< results[i]->GetBookData().author << "\t" << results[i]->GetBookData().state << "\n";
			}
		}
		else
			cout << "Not found.\n";
		system("pause");

	}

	void SearchForMemberById() {
		string id;
		cout << "Enter member id: ";
		cin >> id; cout << "\nResult: \n";
		Member* result = SearchById(member_tree_head, id);
		if (result != nullptr) {
			cout << result->GetMemberData().library_id << "\t" << result->GetMemberData().name << "\t"
				<< result->GetMemberData().personal_id << "\t" << result->GetMemberData().date_joined << "\t"
				<< result->GetMemberData().debt << "\n";
		}
		else {
			cout << "Not found.\n";
		}
		system("pause");
	}

	void SearchForMemberByPid() {
		string pid;
		cout << "Enter member personal id: ";
		cin >> pid; cout << "\nResult: \n";
		vector<Member*> results;
		results = SearchByPid(member_tree_head, pid, results);
		if (results.size() != 0) {
			for (int i = 0; i < results.size(); i++) {
				cout << results[i]->GetMemberData().library_id << "\t" << results[i]->GetMemberData().name << "\t"
					<< results[i]->GetMemberData().personal_id << "\t" << results[i]->GetMemberData().date_joined << "\t"
					<< results[i]->GetMemberData().debt << "\n";
			}
		}
		else
			cout << "Not found.\n";
		system("pause");

	}

	void SearchBookByAuthor() {
		string name;
		cout << "Enter author name: ";
		cin >> name; cout << "\nResult: \n";
		vector<Book*> results;
		results = SearchByAuthor(book_tree_head, name, results);
		if (results.size() != 0) {
			for (int i = 0; i < results.size(); i++) {
				cout << results[i]->GetBookData().book_id << "\t" << results[i]->GetBookData().name << "\t"
					<< results[i]->GetBookData().author << "\t" << results[i]->GetBookData().state << "\n";
			}
		}
		else
			cout << "Not found.\n";
		system("pause");

	}
	
	void RentBook(){
		string book_id;
		cout << "Enter book id: \n";
		cin >> book_id;
		Book* book_result = SearchById(book_tree_head, book_id);
		if (book_result == nullptr)
			cout << "Not found.\n";
		else if (!book_result->GetBookData().state)
			cout << "Not available.\n";
		else {
			string lib_id;
			cout << "Enter member id: ";
			cin >> lib_id;
			Member* lib_result = SearchById(member_tree_head, lib_id);
			if (lib_result == nullptr)
				cout << "Not found.\n";
			else{
				reservation_data new_reserve_data;
				Reservation_file* new_reserve = new Reservation_file;
				cout << "Enter borrow date: "; cin >> new_reserve_data.borrow_date;
				cout << "Enter return date: "; cin >> new_reserve_data.return_date;
				new_reserve_data.book_id = book_id;
				new_reserve_data.person_id = lib_id;
				last_reserv_id++;
				new_reserve_data.reserve_id = last_reserv_id;
				new_reserve_data.state = "1";
				new_reserve->SetReservationData(new_reserve_data);
				Insert(lib_result->GetMemberReservationFile(), *new_reserve);
				book_result->SetState(false);
				book_result->SetLastReserveId(last_reserv_id);
				book_result->SetPerson(lib_id);

				UpdateData();
			}
			
		}
	}

	void ReturnBook() {
		string book_id;
		cout << "Enter book id: \n";
		cin >> book_id;
		Book* book_result = SearchById(book_tree_head, book_id);
		if (book_result == nullptr)
			cout << "Not found.\n";
		else if (book_result->GetBookData().state)
			cout << "Book is available.\n";
		else {
			string lib_id;
			cout << "Enter member id: ";
			cin >> lib_id;
			Member* lib_result = SearchById(member_tree_head, lib_id);
			if (lib_result == nullptr)
				cout << "Member Not found.\n";
			else {
				Reservation_file* reserve_result = SearchById(lib_result->GetMemberReservationFile(),
					to_string(book_result->GetBookData().reserve_file_id));
				if (reserve_result == nullptr) {
					cout << "Wrong member.";
				}
				else {
					reserve_result->SetState("2");
					book_result->SetState(true);

					UpdateData();
				}
			}
			

		}
	}

	void SearchForReserveById() {
		string lib_id;
		cout << "Enter member id: ";
		cin >> lib_id;
		Member* lib_result = SearchById(member_tree_head, lib_id);
		if (lib_result == nullptr)
			cout << "Not found.\n";
		else {
			string reserve_id;
			cout << "Enter Reservation id: ";
			cin >> reserve_id;
			Reservation_file* reserve_result = SearchById(lib_result->GetMemberReservationFile(),reserve_id);
			if (reserve_result == nullptr) {
				cout << "Wrong member.";
			}
			else {
				cout << reserve_result->GetReservationData().reserve_id << "\t"
					<< reserve_result->GetReservationData().book_id << "\t reserved by "
					<< reserve_result->GetReservationData().person_id <<
					"\t from " << reserve_result->GetReservationData().borrow_date << " to "
					<< reserve_result->GetReservationData().return_date << endl;
				if (reserve_result->GetReservationData().state == "1") {
					cout << "Not returned\n";
				}
				else if (reserve_result->GetReservationData().state == "2")
					cout << "Returned\n";
			}
		}
	}

	void EditReserve() {
		string lib_id;
		cout << "Enter member id: ";
		cin >> lib_id;
		Member* lib_result = SearchById(member_tree_head, lib_id);
		if (lib_result == nullptr)
			cout << "Not found.\n";
		else {
			string reserve_id;
			cout << "Enter Reservation id: ";
			cin >> reserve_id;
			Reservation_file* reserve_result = SearchById(lib_result->GetMemberReservationFile(), reserve_id);
			if (reserve_result == nullptr) {
				cout << "Wrong member.";
			}
			else {
				reservation_data new_reserve_data = reserve_result->GetReservationData();
				cout << "Enter new borrow date: "; cin >> new_reserve_data.borrow_date;
				cout << "Enter new return date: "; cin >> new_reserve_data.return_date;
				reserve_result->SetReservationData(new_reserve_data);
			
				UpdateData();
			}
		}
	}

	void EditBook() {
		string book_id;
		cout << "Enter book id: \n";
		cin >> book_id;
		Book* book_result = SearchById(book_tree_head, book_id);
		if (book_result == nullptr)
			cout << "Not found.\n";
		else {
			cout << book_result->GetBookData().book_id << "\t" << book_result->GetBookData().name << "\t"
				<< book_result->GetBookData().author << "\t" << book_result->GetBookData().isbn << "\t"
				<< book_result->GetBookData().state << "\n";
			cout << "Borrowed to: " << book_result->GetBookData().person_id << endl;
			cout << "Reservation id:" << book_result->GetBookData().reserve_file_id << endl;

			Book_data new_book_data;
			new_book_data = book_result->GetBookData();
			cout << "\nEnter new book name: "; cin >> new_book_data.name;
			cout << "\nEnter new author name: "; cin >> new_book_data.author;
			cout << "\nEnter new publication: "; cin >> new_book_data.publication;
			cout << "\nEnter new translator: "; cin >> new_book_data.translator;
			cout << "\nEnter new publish year: "; cin >> new_book_data.publish_year;
			cout << "\nEnter new isbn: "; cin >> new_book_data.isbn;
			book_result->SetBookData(new_book_data);
			UpdateData();
		}
	}

	void EditMember() {
		string lib_id;
		cout << "Enter member id: ";
		cin >> lib_id;
		Member* lib_result = SearchById(member_tree_head, lib_id);
		if (lib_result == nullptr)
			cout << "Not found.\n";
		else {
			cout << lib_result->GetMemberData().library_id << "\t" << lib_result->GetMemberData().name << "\t"
				<< lib_result->GetMemberData().personal_id << "\t" << lib_result->GetMemberData().date_joined << "\t"
				<< lib_result->GetMemberData().debt << "\n";
			Member_data new_member_data;
			new_member_data = lib_result->GetMemberData();
			cout << "\nEnter new name: "; cin >> new_member_data.name;
			cout << "\nEnter new personal id: "; cin >> new_member_data.personal_id;
			cout << "\nEnter new date joined: "; cin >> new_member_data.date_joined;

			lib_result->SetMemberData(new_member_data);
			UpdateData();
		}
	}
	
	void PrintUnavailableBooks(Book* head) {
		if (head != nullptr) {
			if (head->GetBookData().state == false) {
				cout << "\nBook: " << head->GetBookData().book_id << "\t"
					<< head->GetBookData().name << " " << "rented by member "
					<< head->GetBookData().person_id << ". Reserve id is: "
					<< head->GetBookData().reserve_file_id << endl;
			}
			PrintUnavailableBooks(head->GetLeftChild());
			PrintUnavailableBooks(head->GetRightChild());
		}
	 }

	void ShowUnavailableBooks() {
		PrintUnavailableBooks(book_tree_head);
	}

	void SearchMemberByJoinedDate() {
		string date1_year_str, date1_month_str, date1_day_str,
			date2_year_str, date2_month_str, date2_day_str;
		cout << "Enter first date year: "; cin >> date1_year_str;
		cout << "\nEnter first date month: "; cin >> date1_month_str;
		cout << "\nEnter first date day: "; cin >> date1_day_str;
		cout << "\nEnter second date year: "; cin >> date2_year_str;
		cout << "\nEnter second date month: "; cin >> date2_month_str;
		cout << "\nEnter second date day: "; cin >> date2_day_str;
	
		vector<Member*> results;
		results = SearchByDateJoined(member_tree_head, date1_year_str, date1_month_str, date1_day_str,
			date2_year_str, date2_month_str, date2_day_str, results);
		if (results.size() != 0) {
			for (int i = 0; i < results.size(); i++) {
				cout << results[i]->GetMemberData().library_id << "\t" << results[i]->GetMemberData().name << "\t"
					<< results[i]->GetMemberData().personal_id << "\t" << results[i]->GetMemberData().date_joined << "\t"
					<< results[i]->GetMemberData().debt << "\n";
			}
		}
		else
			cout << "Not found.\n";
		system("pause");
	}

	
	void UpdateBook(Book* head) {
		if (head != nullptr) {
			fstream outfile;
			outfile.open(book_file_addr, ios::app);

			Book_data bdata = head->GetBookData();

			string outstring = to_string(bdata.book_id) + "#" + bdata.name + "#" + bdata.author + "#" + bdata.publication +
				"#" + bdata.translator + "#" + bdata.isbn + "#" + bdata.publish_year + "#" + to_string(int(bdata.state))
				+"#" + bdata.person_id + "#" + to_string(bdata.reserve_file_id) + "\n";
			
			outfile << outstring;
			outfile.close();

			UpdateBook(head->GetLeftChild());
			UpdateBook(head->GetRightChild());
		}
	}


	void UpdateReserve(Reservation_file* head) {
		if (head != nullptr) {
			fstream outfile;
			outfile.open(reservation_file_addr, ios::app);

			reservation_data rdata = head->GetReservationData();

			string outstring = rdata.person_id + "#" + to_string(rdata.reserve_id) + "#" + rdata.borrow_date + "#" + rdata.return_date +
				"#" + rdata.book_id + "#" + rdata.state + "\n";

			outfile << outstring;
			outfile.close();

			UpdateReserve(head->GetLeftChild());
			UpdateReserve(head->GetRightChild());
		}
	}


	void UpdateMember(Member* head) {
		if (head != nullptr) {
			fstream outfile;
			outfile.open(member_file_addr, ios::app);

			Member_data mdata = head->GetMemberData();

			string outstring = to_string(mdata.library_id) + "#" + mdata.name + "#" + mdata.personal_id + "#" + mdata.date_joined +
				"#" + mdata.debt + "\n";

			outfile << outstring;
			outfile.close();

			UpdateReserve(head->GetMemberReservationFile());

			UpdateMember(head->GetLeftChild());
			UpdateMember(head->GetRightChild());
		}
	}

	void UpdateData() {
		fstream rfile, mfile, bfile;
		rfile.open(reservation_file_addr, ios::out);
		rfile.clear();
		rfile.close();

		mfile.open(member_file_addr, ios::out);
		mfile.clear();
		mfile.close();

		bfile.open(book_file_addr, ios::out);
		bfile.clear();
		bfile.close();

		UpdateBook(book_tree_head);
		UpdateMember(member_tree_head);
	
	}

	void PayDebt() {
		string lib_id;
		cout << "Enter member id: ";
		cin >> lib_id;
		Member* lib_result = SearchById(member_tree_head, lib_id);
		if (lib_result == nullptr)
			cout << "Not found.\n";
		else {
			double pay;
			double debt = stoi(lib_result->GetMemberData().debt);
			cout << "member: " << lib_id << " with personal id " << lib_result->GetMemberData().personal_id<<endl;
			cout << "Debt: " << to_string(debt);
			cout << "\nEnter pay: ";
			cin >> pay;
			if (pay > debt)
				cout << "Not acceptable.";
			else {
				Member_data new_data;
				new_data = lib_result->GetMemberData();
				new_data.debt = to_string(debt - pay);
				lib_result->SetMemberData(new_data);
				cout << "New debt is " << debt - pay;

				UpdateData();
			}
		}
	}

	void AddDebt() {
		string lib_id;
		cout << "Enter member id: ";
		cin >> lib_id;
		Member* lib_result = SearchById(member_tree_head, lib_id);
		if (lib_result == nullptr)
			cout << "Not found.\n";
		else {
			double add;
			double debt = stoi(lib_result->GetMemberData().debt);
			cout << "member: " << lib_id << " with personal id " << lib_result->GetMemberData().personal_id << endl;
			cout << "Debt: " << to_string(debt);
			cout << "\nEnter added debt: ";
			cin >> add;
			Member_data new_data;
			new_data = lib_result->GetMemberData();
			new_data.debt = to_string(debt + add);
			lib_result->SetMemberData(new_data);
			cout << "New debt is " << debt + add;

			UpdateData();
		}
	}

};