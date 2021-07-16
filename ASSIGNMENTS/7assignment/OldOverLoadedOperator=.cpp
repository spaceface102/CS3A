IntList& IntList::operator=(const IntList &that)
{
    //In a future revision, consider replacing the
    //RemoveNodesStartingAt() func with RemoveNodesAfter()
    //func, to increase efficiency, and reduce the amount
    //of list traversals I have to do.
    IntNode *current_that;  //PROC - track node from "that"
    IntNode *current;       //PROC - track node from calling obj.

    //avoid case were same object is on both
    //sides of the "=" operator.
    if (this == &that)
        return *this;       //just return the calling object
    
    current = head;
    current_that = that.head;
    while (current_that != nullptr && current != nullptr)
    {   //change the values of existing nodes, don't
        //allocate more memory if you don't need to.
        current->data = current->data;
        current = current->next;
        current_that = current_that->next;
    }

    if (current != current_that)    //lists are not the same size.
    {
        //calling object's list must have been smaller
        if (current == nullptr)
        {
            //current object has no nodes
            if (head == nullptr)
            {
                head = tail = new IntNode(current_that->data);
                current_that = current_that->next;
            }

            //continue moving forward from where left off
            while (current_that != nullptr)
            {
                tail->next = new IntNode(current_that->data);
                tail = tail->next;
                current_that = current_that->next;
            }
        }
        //calling object's list must have been larger than of "that"
        else if (current_that == nullptr)
            /* remove the node that current is pointing at
             * the end of the main while loop, both current
             * and current_that are set to the next node.
             * Therefore the node that current points to here
             * must be the next node. 
             * The only case where this is not true is if 
             * even before going through the while loop,
             * current_that is set to NULL, therefore passed
             * in list is an empty list. Therefore current
             * must be head, and will result in removing
             * all the nodes
             * In the case both current and current_that
             * are NULL, since both are empty list, then
             * the outer if statement wouldn't be true, 
             * and therefore we wouldn't be here.*/
            RemoveNodesStartingAt(current); //quite a bit of inefficiency here
    }
    //else both the lists must have had the same amount of nodes

    return *this;
}