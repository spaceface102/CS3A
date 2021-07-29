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
#endif //LIST_EMPTY_CLASS_H
