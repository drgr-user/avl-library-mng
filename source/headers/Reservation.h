#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct reservation_data {
	string person_id, borrow_date, return_date, book_id, state;
	int reserve_id;
};

class Reservation_file {

private:
	reservation_data file_data;
	Reservation_file* parent;
	Reservation_file* right_child;
	Reservation_file* left_child;
	int height = 0;

public:
	reservation_data GetReservationData() {
		return file_data;
	}
	Reservation_file* GetParent() {
		return parent;
	}
	Reservation_file* GetRightChild() {
		return right_child;
	}
	Reservation_file* GetLeftChild() {
		return left_child;
	}
	int GetHeight() {
		return height;
	}

	void SetReservationData(reservation_data entry_data) {
		this->file_data = entry_data;
	}
	void SetParent(Reservation_file* entry_parent_ptr) {
		this->parent = entry_parent_ptr;
	}
	void SetRightChild(Reservation_file* entry_right_child_ptr) {
		this->right_child = entry_right_child_ptr;
	}
	void SetLeftChild(Reservation_file* entry_left_child_ptr) {
		this->left_child = entry_left_child_ptr;
	}
	void SetHeight(int new_height) {
		this->height = new_height;
	}
	void SetState(string state) {
		this->file_data.state = state;
	}
};