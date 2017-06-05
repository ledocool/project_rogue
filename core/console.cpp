#include "console.h"

Console::Console()
{
    _maxEntries = 0;
    _currentNumber = 0;
    _entries.resize(_maxEntries);
}

Console::Console(int maxEntries)
{
    _maxEntries = maxEntries;
    _entries.resize(_maxEntries);
}

void Console::addEntry(const char *entry)
{
    if(_maxEntries == 0)
        return;

    if(_entries.size() >= _maxEntries)
    {
        _entries.pop_back();
    }

    struct Entry a;
    a.message = entry;
    a.key = ++ _currentNumber;
    _entries.push_front(a);
}

void Console::resizeQueue(int newMaxEntries)
{
    _maxEntries = newMaxEntries;
    _entries.resize(_maxEntries);
}

std::string Console::getMessageByKey(uint key)
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
