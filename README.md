# std::vector<bool> Gotchas

This repository demonstrates the potential pitfalls of using `std::vector<bool>` in C++.  `std::vector<bool>` is a specialized container designed for compact storage of boolean values, but its implementation using proxy objects can lead to performance issues and unexpected behavior that are not obvious to new C++ developers. 

**Issues:**

* **Proxy Object Overhead:**  Access to elements in `std::vector<bool>` doesn't directly return a boolean, instead it returns a proxy object. This adds overhead to simple operations.
* **Slower Iteration:** Iterating through a `std::vector<bool>` is slower compared to other standard containers.
* **Copy and Assignment:** Copying and assigning `std::vector<bool>` objects is less efficient than with other vector types.

**Solution:**

Consider using `std::vector<char>` (or `std::vector<uint8_t>`) and managing bits yourself if you need memory efficiency, or simply using `std::vector<bool>` carefully understanding the implications.  In many cases, the performance benefits from using `std::vector<bool>` will be negligable, especially when considering the reduced code readability and maintainability it may cause.