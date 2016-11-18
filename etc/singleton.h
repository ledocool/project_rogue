#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T> class Singleton
{
public:
    Singleton();
    virtual ~Singleton();

    static T* get()
    {
        static T theSingleInstance;
        return &theSingleInstance;
    }

private:

    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);

};

#endif // SINGLETON_H
