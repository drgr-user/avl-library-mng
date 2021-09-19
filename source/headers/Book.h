#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


struct Book_data {
	int book_id;
	string name, isbn, author, publication, publish_year, translator;
	string person_id = "0";
	int reserve_file_id = 0;
	bool state = true;
};

class Book {

private:
	Book_data book_data;
	Book* parent;
	Book* right_child;
	Book* left_child;
	int height = 0;

public:
	Book_data GetBookData() {
		return book_data;
	}
	Book* GetParent() {
		return this->parent;
	}
	Book* GetRightChild() {
		return this->right_child;
	}
	Book* GetLeftChild() {
		return this->left_child;
	}
	int GetHeight() {
		return height;
	}

	void SetBookData(Book_data entry_data) {
		this->book_data = entry_data;
	}
	void SetParent(Book* entry_parent_ptr) {
		this->parent = entry_parent_ptr;
	}
	void SetRightChild(Book* entry_right_child_ptr) {
		this->right_child = entry_right_child_ptr;
	}
	void SetLeftChild(Book* entry_right_child_ptr) {
		this->left_child = entry_right_child_ptr;
	}
	void SetHeight(int new_height) {
		this->height = new_height;
	}
	void SetState(bool state) {
		this->book_data.state = state;
	}
	void SetLastReserveId(int id) {
		this->book_data.reserve_file_id = id;
	}
	void SetPerson(string id) {
		this->book_data.person_id = id;
	}
};