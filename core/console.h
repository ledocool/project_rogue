#ifndef CONSOLE_H
#define CONSOLE_H

#include "stdafx.h"

struct entry{
    uint key;
    std::string message;
};

class console
{
public:
    console();
    console(int maxEntries);
    void addEntry(const char *entry);
    void resizeQueue(int newMaxEntries);
    std::string getMessageByKey(uint key);
    void getMessageByNumber(uint number);

private:
    std::deque <entry> _entries;

    uint _currentNumber, _maxEntries;
};

#endif // CONSOLE_H
