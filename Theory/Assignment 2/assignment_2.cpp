#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class huffmanNode
{
private:
    int frequency;
    char character;
    string code;
    huffmanNode *left;
    huffmanNode *right;

public:
    huffmanNode(char c = '\0')
    {
        character = c;
        code = '0';
        frequency = 0;
        left = right = NULL;
    }
    char getdata()
    {
        return character;
    }
    friend class huffman;
};

class huffman
{
private:
    huffmanNode *root;

public:
    huffman()
    {
        root = NULL;
    }
    // read file and get frequency of every character
    vector<pair<int, char>> CalFreq()
    {
        map<char, int> m1;
        string s;
        fstream in_file;
        char id;
        in_file.open("input.txt", ios::in);
        in_file.get(id);
        // cout << "Id:" << id << endl;-> i
        while (!in_file.eof())
        {
            m1[id]++;
            // cout << m1[id] << endl;
            in_file.get(id);
        }
        in_file.close();
        vector<pair<int, char>> v1;
        for (int i = 0; i < 128; i++)
        {
            if (m1[i] != 0)
            {
                v1.push_back(make_pair(m1[i], i));
                // cout << m1[i] << " " << i << " " << endl;
                m1[i] = 0;
            }
        }
        return v1;
    }
    // string
    string TotalElementAccess()
    {
        string s = "";
        fstream in_file;
        in_file.open("input.txt", ios::in);
        char id;
        in_file.get(id);
        while (!in_file.eof())
        {
            s = s + id;
            in_file.get(id);
        }
        in_file.close();
        // cout << s << "->s\n";
        cout << endl;
        return s;
    }
    // create a huffman tree
    huffmanNode *BuildTree(vector<pair<int, char>> f)
    {
        huffmanNode *temp;
        huffmanNode *temp1;
        huffmanNode *temp2;
        vector<huffmanNode *> v1;
        for (int i = 0; i < f.size(); i++)
        {
            temp = new huffmanNode(f[i].second);
            temp->frequency = f[i].first;
            v1.push_back(temp);
        }
        while (v1.size() > 1)
        {
            sort(v1.begin(), v1.end(), [](huffmanNode *a, huffmanNode *b)
                 { return a->frequency < b->frequency; });
            temp1 = v1[0];
            temp2 = v1[1];
            temp = new huffmanNode();
            temp->frequency = temp1->frequency + temp2->frequency;
            temp->left = temp1;
            temp->right = temp2;
            v1.erase(v1.begin(), v1.begin() + 2);
            v1.push_back(temp);
        }
        root = v1[0];
        return root;
    }
    // assign 0 to the left tree paths and 1 to right tree paths
    void AssignCode(huffmanNode *root, string s)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            root->code = s;
            return;
        }
        AssignCode(root->left, s + "0");
        AssignCode(root->right, s + "1");
    }
    // print the huffman tree
    void PrintTree(huffmanNode *root)
    {
        if (root == NULL)
            return;
        PrintTree(root->left);
        cout << root->character << " " << root->frequency << " " << root->code << endl;
        PrintTree(root->right);
    }
    // print the huffman code
    void genCode(huffmanNode *root, string s, vector<pair<char, string>> &f)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            cout << root->character << " " << root->code << endl;
            f.push_back(make_pair(root->character, root->code));
            return;
        }
        genCode(root->left, s + "0", f);
        genCode(root->right, s + "1", f);
    }
    // encode the string and store in a seprate output.bin file
    void Encode(string str, vector<pair<char, string>> f)
    {
        string encodedCode = "";
        // cout << str.length() << " " << f.size();
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < f.size(); j++)
            {
                if (str[i] == f[j].first)
                {
                    encodedCode += f[j].second;
                }
            }
        }
        cout << "Encoded string:\n";
        cout << encodedCode << endl;
        // writing encoded string in output.bin file
        fstream out_file;
        out_file.open("output.bin", ios::out);
        for (int i = 0; i < encodedCode.length(); i++)
        {
            out_file << encodedCode[i];
        }
        out_file.close();
        // writing encoded string in output.txt file
        out_file.open("output.txt", ios::out);
        for (int i = 0; i < encodedCode.length(); i++)
        {
            out_file << encodedCode[i];
        }
        out_file.close();
    }
    // decode the string and store in a seprate file
    void Decode(huffmanNode *node)
    {
        // reading output.bin file and storing in a variable
        string encodedCode = "";
        string decompressed = "";
        fstream in_file;
        in_file.open("output.bin", ios::in);
        char id;
        in_file.get(id);
        while (!in_file.eof())
        {
            encodedCode = encodedCode + id;
            in_file.get(id);
        }

        in_file.close();
        // cout << encodedCode << endl;
        // decoding
        huffmanNode *temp = node;
        for (int i = 0; i < encodedCode.length(); i++)
        {
            if (encodedCode[i] == '0')
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
            if (temp->left == NULL && temp->right == NULL)
            {
                decompressed += temp->character;
                temp = node;
            }
        }
        cout << "\nDecoded string:\n";
        cout << decompressed << endl;
        fstream out_file;
        out_file.open("decompressed.txt", ios::out);
        out_file << decompressed;
        out_file.close();
    }
    // print huffman tree with frequency and characters
    void printTree(huffmanNode root)
    {
        if (root ==  nullptr) return;
        printTree(root->left);
        cout << root->character << " " << root->frequency << " " << root->code << endl;
        printTree(root->right);
    }
    // menu
    void menu()
    {
        bool treeGenerated = false;
        bool isEncoded = false;
        int choice;
        cout << "Uncle Huffman!\n";
    comeHereIfNotEncoded:
    again:
        cout << "Add text in input.txt file!\n";
        cout << "1. Encode\n";
        cout << "2. Decode\n";
        // cout << "3. print Huffman tree\n";
        cout << "3. Exit\n";
        vector<pair<char, string>> f;

        cout << "your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = BuildTree(CalFreq());
            AssignCode(root, "");
            genCode(root, "", f);
            Encode(TotalElementAccess(), f);
            treeGenerated = true;
            isEncoded = true;
            goto again;
            break;
        case 2:
            if (isEncoded == false)
            {
                cout << "Please encode first\n";
                goto comeHereIfNotEncoded;
            }
            Decode(root);
            break;
            /*case 3:
                if (treeGenerated == false) {
                    root = BuildTree(CalFreq());
                }
                printTree(root);
                break;*/
        case 3:
            exit(0);
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
};