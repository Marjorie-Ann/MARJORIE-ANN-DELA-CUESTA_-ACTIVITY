#include <iostream>

using namespace std;
 typedef struct Node{
    string songName;
    Node *link;
 }Node;

 Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
 }

 void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
 }

 Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
 }

 Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" << endl;

    return head;
 }

 string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after" + after + "\n";
 }
 int main(){
    Node *head = createNode("Sanctuary by Joji");

    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverse(head);
     
    head = insertAtEnd("All to Myself by Future, Metro Boomin & The Weekend", head);
    traverse (head);

    head = insertAtEnd("Mama Knows Best by Jessie J", head);
    traverse(head);

    head = insertAtEnd("I Love You by Celine Dion", head);
    traverse(head);

    head = insertAtBeginning("Jump by Tyla", head);
    traverse(head);

    head = insertAtBeginning("Adore You by Miley Cyrus", head);
    traverse(head);

    head = insertAtBeginning("Good Days by Sza", head);
    traverse(head);

    head = insertAtBeginning("Crybaby by Sza", head);
    traverse(head);

    head = insertAfter(after "Crybaby", "Para sa Akin by Arthur Nery", head");
    traverse(head);

    head = insertAfter("Isa Lang by Arthure Nery.compare(Para sa Akin by Arthur Nery)"Node*head);
    traverse(head);

    head = insertAfter("Tagpuan by Moira.compare(Isa Lang by Arthur Nery)"Node*head);
    traverse(head);




    return 0;
 }