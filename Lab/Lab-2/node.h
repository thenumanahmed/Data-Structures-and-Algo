#pragma once
#include<iostream>
class Node {
	int data;
	Node* next;
public:
	void setData(int val) {
		data = val;
	}
	int getData() {
		return data;
	}
	void setNext(Node* n) {
		next = n;
	}
	Node* getNext() {
		return next;
	}
	Node(int val) {
		next = NULL;
		data = val;
	}
	Node() {
		next = NULL;
		data = 0;
	}
};