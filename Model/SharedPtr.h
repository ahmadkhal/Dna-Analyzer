

#ifndef DNAPROJECT_SHAREDPTR_H
#define DNAPROJECT_SHAREDPTR_H

#include <stdlib.h>
#include<exception>
#include <stdexcept>
#include <iostream>

template<typename T>
class SharedPtr {
public:
    explicit SharedPtr(T *ptr);

    ~SharedPtr();

    T *operator->() const;

    T &operator*() const;

    operator bool() const;

    SharedPtr &operator=(T *p);

    SharedPtr &operator=(SharedPtr const &);

    SharedPtr(SharedPtr const &);

    template<typename U>
    SharedPtr<T> &operator=(const SharedPtr<U> &sp);

    template<typename U>
    SharedPtr(SharedPtr<U> const &);

    T *getPtr() const;

    size_t *getCount() const;

private:

    size_t *m_count;
    T *m_ptr;
};

template<typename T>
SharedPtr<T>::SharedPtr(T *ptr) :
        m_ptr(ptr) {
    m_count = new size_t;    //think about this tomorrow
    *m_count = 1;

}

template<typename T>
SharedPtr<T>::~SharedPtr() {
    if (*m_count == 1) {
        delete m_ptr;
        delete m_count;
    } else
        --*m_count;
}

template<typename T>
T *SharedPtr<T>::operator->() const {
    return m_ptr;
}

template<typename T>
T &SharedPtr<T>::operator*() const {

    return *m_ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const {
    return m_ptr;
}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(T *p) {
    if (m_ptr == p) {
        return *this;
    }
    if (*m_count == 1)
        delete m_ptr;
    else {
        --*m_count;
        m_count = new size_t;
        *m_count = 1;
    }
    m_ptr = p;
    return *this;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &sp) {
    m_count = sp.getCount();

    ++*m_count;
    m_ptr = sp.getPtr();


}

template<typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &sp) {
    if (m_ptr == sp.getPtr()) {
        return *this;
    }
    if (*m_count == 1) {
        delete m_ptr;
        delete m_count;    /////check this!!!!!!!!!!
        m_count = sp.getCount();
        ++*m_count;
    } else {
        --*m_count;
        m_count = sp.getCount();
        ++*m_count;
    }
    m_ptr = sp.getPtr();
    return *this;
}

template<typename T>
template<typename U>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<U> &sp) {
    if (m_ptr == sp.getPtr()) {
        return *this;
    }
    if (*m_count == 1) {
        delete m_ptr;
        delete m_count;    /////check this!!!!!!!!!!
        m_count = sp.getCount();
        ++*m_count;
    } else {
        --*m_count;
        m_count = sp.getCount();
        ++*m_count;
    }
    m_ptr = sp.getPtr();
    return *this;
}

template<typename T>
template<typename U>
SharedPtr<T>::SharedPtr(const SharedPtr<U> &sp) {
    m_count = sp.getCount();
    ++*m_count;
    m_ptr = sp.getPtr();

}


template<typename T>
inline T *SharedPtr<T>::getPtr() const {
    return m_ptr;
}

template<typename T>
inline size_t *SharedPtr<T>::getCount() const {
    return m_count;
}


#endif //DNAPROJECT_SHAREDPTR_H
