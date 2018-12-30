#ifndef DNAPROJECT_UNIQUEPTR_H
#define DNAPROJECT_UNIQUEPTR_H

#include <stdlib.h>
#include<exception>
#include <stdexcept>

template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T *ptr);

    ~UniquePtr();

    T *operator->() const;

    T &operator*() const;

    operator bool() const;

    UniquePtr &operator=(T *p);

    T *get() const;

private:
    // Prevent coping
    UniquePtr(UniquePtr const &);

    UniquePtr &operator=(UniquePtr const &p);

    T *m_ptr;
};

template<typename T>
UniquePtr<T>::UniquePtr(T *ptr) {
    m_ptr = ptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    delete m_ptr;
}

template<typename T>
T *UniquePtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &UniquePtr<T>::operator*() const {

    return *m_ptr;
}

template<typename T>
UniquePtr<T>::operator bool() const {
    return m_ptr;
}

template<typename T>
UniquePtr<T> &UniquePtr<T>::operator=(T *p) {
    if (m_ptr == p) {
        return *this;
    }
    delete m_ptr;
    m_ptr = p;
    return *this;
}

template<typename T>
T *UniquePtr<T>::get() const {
    return m_ptr;
}


#endif //DNAPROJECT_UNIQUEPTR_H
