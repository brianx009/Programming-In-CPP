<span style="color: #3291a8;">
# Introduction to Smart Pointers
</span>
<span style="color: white;">
## Pointers before learning about smart pointers have just been "Raw Pointers".
</span>
 * <span style="color: red;">The memory management of raw pointers is manual, and the developer is responsible for allocating and freeing memory.</span>
 * This makes working with raw pointers prone to memory leaks and other bugs.
 * In modern C++, you rarely work with raw pointers directly and instead work with smart pointers, which take care of the dynamic memory management for you.
 * If using smart pointers there is no reason to be using "New" or "Delete".

# Smart Pointers
* Are used to manage memory allocate on the free store and in more ways act exactly as a raw pointer does.
* Smart pointers are allocated on the Stack, and you do not need to call delete or delete[] to free up memory.
* Errors such as multiple deallocations, memory leaks, and allocation/ deallocation mismatches can be eliminated.
* Uses a technique known as "Resource Acquistion Is Initialization" (RAII).

# RAII
* C++ technique that bings the life cycle of a resource that must be acquired to the lifetime of an object.
* You instantiate and manage the lfetime of an object on the stack.
* The object on the stack takes tcare of managing your dynamically allocated resources.
* Smart pointers are defined templates in the memory header of the C++ Standard Library. (This means this is a built in part of the C++ language)

# RAII Process
* Object is created on the stack \to Constructor acquires resources on the free store \to Destructor frees resources on the free store

# Types of Smart Pointers
##  unique_ptr<T>
* behaves like a pointer to a type T and is unique -- only one pointer containing the memory address can exist.
* A unique pointer exclusively own whatever it points to.
* There can only be one unique pointer pointing to a certain memory address at any point.
* A unique pointer cannot be copied since the compiler will not allow this.

## shared_ptr<T>
* behaves like a pointer to a type T -- there can be any number of shared pointers for the same resource.
* Difference between a shared pointer and a unique pointer is that with a shared pointer there can be any number of shared pointers pointing to the same underlying resource. -- the shared pointer implemention is smart enough to figure out that the underlying resource should not be cleaned up as long as there is at least 1 shared pointer pointing to it.
* How does it know that there is even 1 shared pointer left ? -- because of something known as the resource counting.
* Every shared pointer keeps track of the nuber of "strong" and "weak" references to the underlying memory.
* Strong references are incrememnted each time a new shared pointer references the same memory, such as when a pointer is copied.
* Strong references are decrememnted each time a shared pointer releases memory or goes out of scope. -- underlying memory is only freed when the number of strong references reaches zero. 

## weak_ptr<T>
* is linked to a shared_ptr<T> and points to the same resource -- it does not increment the reference count.
* weak_ptr can not have an independent existance.
* shared_ptr sets a strong reference count, but because weak_ptr does not incrememnt the reference count, this means that we can deallocate/ clean up our references although there are some weak_ptr's that exist.
* Weak pointers exist and are used to mitigate circular references, which cause memory leaks.
