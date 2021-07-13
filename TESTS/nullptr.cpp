#include <iostream>

struct NodeType
{
    int info;
    NodeType* link;
};

NodeType* Add(NodeType* prev, int value)
{
    prev->link = new NodeType;
    prev->link->info = value;
    prev->link->link = nullptr;

    return prev->link;
}

int main(void)
{
    NodeType* head;
    NodeType *current, *temp, *trail, *last, *list;
/*
    head = new NodeType;
    head->info = 75;
    head->link = nullptr;

    current = head;
    current = Add(current, 35);
    temp = current = Add(current, 86);
    current = Add(current, 10);
    current = Add(current, 50);
    current = Add(current, 28);
    trail = current = Add(current, 65);
    last = current = Add(current, 39);

    list = current = head;

    current = temp->link;   //current 10
    trail = list;           //trail = 75
    temp = list->link;      //temp = 35
    trail = temp;           //trail = 35
    temp->link = current->link; //35 -> 50, skip 86 and 10
    current = trail->link;  //current 50
    std::cout << trail->info << " " << current->info << "\n";
    //trail = 35 and current = 50
    //Clean up
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        delete temp;
    }
*/

/*
    list = new NodeType;
    list->info = 28;
    trail = new NodeType;
    trail->info = 33;
    trail->link = list;
    list->link = nullptr;
    current = new NodeType;
    current->info = 62;
    trail->link = current;
    current->link = list;
    list = trail;
    current = list->link;
    trail = current->link;
    std::cout << list->info << " " << current->info << " "
              << trail->info << "\n";
*/

    current = new NodeType;
    current->info = 72;
    current->link = nullptr;
    trail = current;
    current = new NodeType;
    current->info = 46;
    current->link = trail;
    list = current;
    current = new NodeType;
    current->info = 52;
    list->link = current;
    current->link = trail;
    trail = current;
    current = new NodeType;
    current->info = 91;
    current->link = trail->link;
    trail->link = current;
    current = list;
    while (current != NULL)
    {
        std::cout << current->info << " ";
        current = current->link;
    }
    return 0;
}