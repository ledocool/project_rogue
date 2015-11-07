#include "console.h"

console::console()
{
    _maxEntries = 0;
    _currentNumber = 0;
    _entries.resize(_maxEntries);
}

console::console(int maxEntries)
{
    _maxEntries = maxEntries;
    _entries.resize(_maxEntries);
}

void console::addEntry(const char *entry)
{
    if(_maxEntries == 0)
        return;

    if(_entries.size() >= _maxEntries)
    {
        _entries.pop_back();
    }

    struct entry a;
    a.message = entry;
    a.key = ++ _currentNumber;
    _entries.push_front(a);
}

void console::resizeQueue(int newMaxEntries)
{
    _maxEntries = newMaxEntries;
    _entries.resize(_maxEntries);
}

std::string console::getMessageByKey(uint key)
{
    uint i;
    for(i=0; i<_entries.size(); i++)
    {
        if(_entries[i].key == key)
            break;
    }

    if(i < _entries.size())
        return _entries[i].message;
    else
    {
        std::string empty = "";
        return empty;
    }
}
