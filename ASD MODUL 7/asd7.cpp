#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru)
{
    if (*root == NULL)
    {
        Node *baru;
        baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;           
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
        cout << "Data bertambah";
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
    else if (databaru == (*root)->data)
        cout << "Data sudah ada";
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);      
        cout << root->data << " "; 
        inOrder(root->kanan);     
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);    
        postOrder(root->kanan);   
        cout << root->data << " "; 
    }
}

int main()
{
    int pil, data;
    Node *pohon;
    pohon = NULL;
    do
    {
        system("cls");
        cout << "1. Tambah\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "\nPilihan : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            cout << "\n INPUT : ";
            cout << "\n ----------";
            cout << "\n Data baru : ";
            cin >> data;
            tambah(&pohon, data);
            break;
        case 2:
            cout << "PreOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                preOrder(pohon);
            }
            else
                cout << "Masih Kosong";
            break;
        case 3:
            cout << "InOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                inOrder(pohon);
            }
            else
                cout << "Masih Kosong";
            break;
        case 4:
            cout << "PostOrder";
            cout << "\n------------------------\n";
            if (pohon != NULL)
            {
                postOrder(pohon);
            }
            else
                cout << "Masih Kosong";
            break;
        case 5:
            return 0;
        }
        _getch();
    } while (pil != 5);
    return EXIT_FAILURE;
}