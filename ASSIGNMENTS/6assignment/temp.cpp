#include "IntList.h"

//remove_duplicates
void remove_duplicates_0(IntNode *head)
{
    IntNode *subHead;   //PROC - shift the head, reduce num of iterations
    IntNode **current;  //PROC - pointer to the next pointer
    IntNode *temp;      //PROC - delete past address.
    int search;         //PROC - value searching to delete

    subHead = head;
    while (subHead != nullptr)
    {
        search = subHead->data;
        //make current point to the subHead's next pointer.
        //a pointer to a pointer!
        current = &(subHead->next);
        while (*current != nullptr)
        {
            /* *current gets you the address of the next node
             * *current->data allows you to access that next node's
             * data.
             * We are looking for a node that points to the
             * node we are trying to remove
            */
            if ((*current)->data == search)
            {
                temp = *current;
                /* (*current)->next is equivalent to 
                 * (*(*current)).next
                 * the outer most derefence gets the address
                 * stored in the previous node's next pointer:
                 * the second dereference gives access to the next
                 * node itself and then .next access the pointer of the
                 * relative next node. The result is that the previous
                 * node's next attribute is set to the next->next
                 * address. current at the end of this is still
                 * pointing to the previous node's next pointer,
                 * and since we skip the deleted "temp", it has the
                 * effect of allowing us to not need to increment
                 * or change current, the double pointer.
                 * 
                 * Why go through this? It allows us to reduce the
                 * number of copies due to having a "previous" node
                 * variable, that we use to modify the next address.
                 * The double pointer manages to do the job of a
                 * "previous" node pointer and the "current" node
                 * pointer all in one package.
                 * 
                 * Where did I get the inspiration from?
                 * A while ago, just watching some youtube, I
                 * bumped into a ted talk interview  with Linus Torvalds.
                 * They quickly go over "taste" in coding, and a simple
                 * linked list example shows up.
                 * https://youtu.be/o8NPllzkFhE?t=858
                 * For more in depth analysis of the example:
                 * https://tinyurl.com/nw577bmv
                 */
                *current = (*current)->next;
                delete temp;
            }
            else
                current = &((*current)->next);
        }
        subHead = subHead->next;
    }
}

void remove_duplicates_1(IntNode *head, IntNode *tail)
{
    IntNode *subHead;   //PROC - shift the head, reduce num of iterations
    IntNode **current;  //PROC - pointer to the next pointer
    IntNode *temp;      //PROC - delete past address.
    
    //A new list with no nodes, or a list with only one node
    if (head == tail)
        return;

    //condition guards against (*current)->next, which would null
    //if only two nodes in sublist, and since while loop looks for
    //tail node for exit condition, would not be able change 
    //what tail is pointing if need be.
    subHead = head;
    while (subHead->next != tail)
    {
        current = &(subHead->next);
        while ((*current)->next != tail)
        {
            if ((*current)->data == subHead->data)
            {
                temp = *current;
                *current = (*current)->next;
                delete temp;
            }
            else
                current = &((*current)->next);
        }

        if (tail->data == subHead->data)
        {
            delete tail;
            tail = *current;
            tail->next = nullptr;

            //if it is a two node list currently, exit. Ensure
            //that subHead is not set to subHead->next before
            //exiting the loop, which would make subHead = tail
            //and therefore the main while loop condition wouldn't
            //be triggered 
            if (subHead->next == tail)
                break;
            
            //note that the new tail is never checked/touched
            //before. current points to a next pointer inside
            //the a node that is two nodes away from the past
            //tail, which is checked. The new tail is never 
            //checked. We have to change that.
            
            //wait, I don't have the address of the previous 
            //node....
        }
        subHead = subHead->next;
    }

    //assured that subHead to tail is two nodes due to
    //the above while loop condition, and returning
    //early with the first for loop
    if (subHead->data == tail->data)
    {
        delete tail;
        tail = subHead;
        tail->next = nullptr;
    }
}

void winner_indirect(IntNode *head, IntNode *tail)
{
    //Why was I using an indirect pointer? Honestly because
    //I wanted to have "taste" ahaha. But it made the code
    //harder to follow, and increase the number of copies of
    //"last" node. All is not in vain, as I now have a better
    //understanding of why indirect pointers can be so useful,
    //especially when the head is part of the structure to consider.
    IntNode *subHead;           //PROC - shift the head, change the number t
    IntNode **current_indirect; //PROC - pointer to the next pointer in a node
    IntNode *temp;              //PROC - delete past address.
    IntNode *current;           //PROC - track the node itself that the next
                                //pointer is in that current_indirect is
                                // pointing to.

    /* The main while loop condition will protect against brand
     * new lists where the head and tail are pointing to NULL
     * and also to single node list, where head and tail are
     * pointing to the exact same node.
    */
    subHead = head;
    while (subHead != tail)
    {
        current_indirect = &(subHead->next);
        current = subHead;
        while (*current_indirect != tail)
        {
            if ((*current_indirect)->data == subHead->data)
            {
                temp = *current_indirect;
                *current_indirect = (*current_indirect)->next;
                delete temp;
            }
            else
            {
                /* set current to the node that current_indirect
                 * will be modifying its next pointer, by having
                 * a pointer to it.*/
                current = *current_indirect;
                current_indirect = &((*current_indirect)->next);
            }
        }
        if (tail->data == subHead->data)
        {
            delete tail;
            tail = current;
            tail->next = nullptr;

            //protect agains subHead being NULL next iteration
            if (subHead == tail)
                break;
        }
        subHead = subHead->next;
    }
}