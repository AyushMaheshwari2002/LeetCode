/*  Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.

    Implement the PeekingIterator class:
        * PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
        * int next() Returns the next element in the array and moves the pointer to the next element.
        * boolean hasNext() Returns true if there are still elements in the array.
        * int peek() Returns the next element in the array without moving the pointer.
    
    Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.

              Example 1:
                      Input
                      ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
                      [[[1, 2, 3]], [], [], [], [], []]

                      Output
                      [null, 1, 2, 2, 3, false]

                      Explanation
                      PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
                      peekingIterator.next();    // return 1, the pointer moves to the next element [1,2,3].
                      peekingIterator.peek();    // return 2, the pointer does not move [1,2,3].
                      peekingIterator.next();    // return 2, the pointer moves to the next element [1,2,3]
                      peekingIterator.next();    // return 3, the pointer moves to the next element [1,2,3]
                      peekingIterator.hasNext(); // return False
*/



class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        Iterator it = *this;
        return it.next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        // here we have call parent class method to child class using iterator
	    return Iterator :: next();
	}
	
	bool hasNext() const {
	    return Iterator :: hasNext();
	}
};



/*
class PeekingIterator : public Iterator {
public:
    
    vector<int> v;
    int idx = 0;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    v = nums; // create a copy of nums vector
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        // return element without incrementing the pointer
        return v[idx];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        // return element and increment the pointer
	    return v[idx++];
	}
	
	bool hasNext() const {
	    if(idx < v.size())
            return true;
        return false;
	}
};
*/


