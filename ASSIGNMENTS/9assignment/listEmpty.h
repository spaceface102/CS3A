#ifndef LIST_EMPTY_CLASS_H
#define LIST_EMPTY_CLASS_H

#include <string>
class ListEmpty
{
private:
    std::string message;

public:
    ListEmpty(void);
    ListEmpty(const std::string&);
    const std::string& what(void) const;
};

ListEmpty::ListEmpty(void) : message("Empty list!") {}
//EOF

ListEmpty::ListEmpty(const std::string& message) : message(message) {}
//EOF

const std::string& ListEmpty::what(void) const
    {return message;}
//EOF

#endif //LIST_EMPTY_CLASS_H
