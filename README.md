# HashMap README

## Overview

The `HashMap` class is a C++ implementation of a hash table data structure, designed to efficiently store and retrieve key-value pairs. It supports basic operations such as insertion, retrieval, removal, and more.

## Constructor

### `HashMap()`

- **Description:** Constructs an empty hash map with an initial size of 7.
- **Usage:** `HashMap<int, std::string> myMap;`

## Core Operations

### `put(const T1& key, const T2& value)`

- **Description:** Inserts a key-value pair into the hash map. If the key already exists, the associated value is updated.
- **Usage:** `myMap.put(1, "one");`

### `get(const T1& key) const`

- **Description:** Retrieves the value associated with the given key.
- **Usage:** `std::string result = myMap.get(1);`

### `remove(const T1& key)`

- **Description:** Removes the key-value pair associated with the given key.
- **Usage:** `myMap.remove(1);`

### `containsKey(const T1& key)`

- **Description:** Checks if the hash map contains the specified key.
- **Usage:** `bool containsKey = myMap.containsKey(1);`

### `containsValue(const T2& value)`

- **Description:** Checks if the hash map contains any key associated with the specified value.
- **Usage:** `bool containsValue = myMap.containsValue("one");`

### `size() const`

- **Description:** Returns the number of key-value pairs in the hash map.
- **Usage:** `int size = myMap.size();`

### `isEmpty() const`

- **Description:** Checks if the hash map is empty.
- **Usage:** `bool isEmpty = myMap.isEmpty();`

### `clear()`

- **Description:** Clears all key-value pairs from the hash map.
- **Usage:** `myMap.clear();`

### `keySet()`

- **Description:** Returns a vector containing all the keys in the hash map.
- **Usage:** `std::vector<int> keys = myMap.keySet();`

### `valueSet()`

- **Description:** Returns a vector containing all the values in the hash map.
- **Usage:** `std::vector<std::string> values = myMap.valueSet();`

### `entrySet()`

- **Description:** Returns a vector containing pairs of the hash map entries (key, list of values).
- **Usage:** `auto entries = myMap.entrySet();`

## Internal Functions

### `rehash()`

- **Description:** Adjusts the size of the hash table and reorganizes the elements to maintain efficiency.
- **Usage:** Automatically called when needed during insertions.

### `hashing(const T1& key) const`

- **Description:** Computes the hash code for a given key.
- **Usage:** Used internally for indexing elements in the hash table.

### `next_prime(int num)`

- **Description:** Finds the next prime number greater than the given number.
- **Usage:** Used internally for resizing the hash table.




## How to Use

### Downloading the Code

1. **Clone the Repository:**
   - Open a terminal or command prompt.
   - Run the following command to clone the repository to your local machine:
     ```
     git clone https://github.com/mparsyan/Hash_Map-Implementation.git
     ```

2. **Navigate to the Project Folder:**
   - Change to the directory where you cloned the repository:
     ```
     cd your-repository
     ```

### Running the Code

1. **Compile the Code:**
   - Use a C++ compiler (e.g., g++) to compile the source files. Assuming you have the `g++` compiler installed, run:
     ```
     g++ main.cpp -o my_program
     ```

2. **Run the Executable:**
   - Execute the compiled program:
     ```
     ./my_program
     ```

3. **Explore the HashMap:**
   - Open the `main.cpp` file to see an example of how to use the `HashMap` class.

```cpp
#include "hash_map.hpp"

int main() {
    // Create a HashMap instance
    HashMap<int, std::string> myMap;

    // Insert key-value pairs
    myMap.put(1, "one");
    myMap.put(2, "two");

    // Retrieve and print a value
    std::string result = myMap.get(1);
    std::cout << "Value for key 1: " << result << std::endl;

    // Check if a key exists
    bool containsKey = myMap.containsKey(1);
    std::cout << "Contains key 1: " << (containsKey ? "Yes" : "No") << std::endl;

    // ...

    return 0;
}
