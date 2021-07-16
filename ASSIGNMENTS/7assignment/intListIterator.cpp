#include "intListIterator.h"

IntListIterator::IntListIterator(void) : current(nullptr) {}
//EOF

IntListIterator::IntListIterator(IntNode* ptr) : current(ptr) {}
//EOF

int IntListIterator::operator*(void)
{
    return current->data;
}
//EOF

IntListIterator IntListIterator::operator++(void)
{
    current = current->next;
    return *this;
}
//EOF

bool IntListIterator::operator==(const IntListIterator& right) const
{
    return (current == right.current);
}
//EOF

bool IntListIterator::operator!=(const IntListIterator& right) const
{
    return !(*this == right);
}
//EOF