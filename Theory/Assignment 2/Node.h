#pragma once
class Node
{
public:
    char data;
    Node* right;
    Node* left;

    Node(char c = '\0') : data(c), right(), left()
    {
    }
    //setter getter
};