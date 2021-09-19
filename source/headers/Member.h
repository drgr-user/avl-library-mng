#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Reservation.h"

using namespace std;


struct Member_data {
	string name, personal_id, date_joined, debt;
	int library_id;
};

class Member {

private:
	Member_data member_data;
	Reservation_file* member_reservation_file;
	Member* parent;
	Member* right_child;
	Member* left_child;
	int height = 0;

public:
	Member_data GetMemberData() {
		return member_data;
	}
	Member* GetParent() {
		return parent;
	}
	Member* GetRightChild() {
		return right_child;
	}
	Member* GetLeftChild() {
		return left_child;
	}
	Reservation_file* GetMemberReservationFile() {
		return member_reservation_file;
	}
	int GetHeight() {
		return height;
	}

	void SetMemberData(Member_data entry_data) {
		this->member_data = entry_data;
	}
	void SetMemberReservationFileHead(Reservation_file* entry_reservation_file_ptr) {
		this->member_reservation_file = entry_reservation_file_ptr;
	}
	void SetParent(Member* entry_parent_ptr) {
		this->parent = entry_parent_ptr;
	}
	void SetRightChild(Member* entry_right_child_ptr) {
		this->right_child = entry_right_child_ptr;
	}
	void SetLeftChild(Member* entry_left_child_ptr) {
		this->left_child = entry_left_child_ptr;
	}
	void SetHeight(int new_height) {
		this->height = new_height;
	}
};