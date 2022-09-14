
#pragma once
#include<iostream>
class DNode {
	int data;
	DNode* next;
	DNode* prev;
public:
	void setData(int val) {
		data = val;
	}
	int getData() {
		return data;
	}
	void setNext(DNode* n) {
		next = n;
	}
	DNode* getNext() {
		return next;
	}
	void setPrev(DNode* p) {
		prev = p;
	}
	DNode* getPrev() {
		return prev;
	}
	DNode() {
		data = 0;
		next = prev = NULL;
	}
	DNode(int val) {
		data = val;
		next = prev = NULL;
	}

};