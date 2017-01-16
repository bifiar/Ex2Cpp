
//
//Created by boaz_bahat on 1/2/17.
//



#ifndef MyAllocator2_H
#define MyAllocator2_H
#include <stdlib.h>
#include <new>
#include <limits>
#include <stddef.h>
namespace JVC {
    template <class T>
    struct MyAllocator {
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;

        template <class U> struct rebind { typedef MyAllocator<U> other; };
        MyAllocator() throw() {}
        MyAllocator(const MyAllocator&) throw() {}

        template <class U> MyAllocator(const MyAllocator<U>&) throw(){}

        ~MyAllocator() throw() {}

        pointer address(reference x) const { return &x; }
        const_pointer address(const_reference x) const { return &x; }

        pointer allocate(size_type s, void const * = 0) {
            if (0 == s)
                return NULL;
            pointer temp = (pointer)malloc(s * sizeof(T));
            if (temp == NULL)
                throw std::bad_alloc();
            return temp;
        }

        void deallocate(pointer p, size_type) {
            free(p);
        }

        size_type max_size() const throw() {
            return std::numeric_limits<size_t>::max() / sizeof(T);
        }

        void construct(pointer p, const T& val) {
            new((void *)p) T(val);


        }


        void destroy(pointer p) {
            p->~T();
        }
    };
}


#endif /* MyAllocator2_H */

