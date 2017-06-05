#ifndef CONSOLE_H
#define CONSOLE_H

#include "stdafx.h"

struct Entry{
    uint key;
    std::string message;
};

class Console
{
public:
    Console();
    Console(int maxEntries);
    void addEntry(const char *Entry);
    void resizeQueue(int newMaxEntries);
    std::string getMessageByKey(uint key);
    void getMessageByNumber(uint number);

private:
    std::deque <Entry> _entries;

    uint _currentNumber, _maxEntries;
};

#endif // CONSOLE_H
