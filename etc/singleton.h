#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T> class singleton
{
public:
    singleton();
    virtual ~singleton();

    static T* get()
    {
        static T theSingleInstance;
        return &theSingleInstance;
    }

private:

    singleton(singleton const&);
    singleton& operator=(singleton const&);

};

#endif // SINGLETON_H
