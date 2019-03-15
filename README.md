# BIH
[Bounded Interval Hierachy](https://en.wikipedia.org/wiki/Bounding_interval_hierarchy) (BIH)
of [Axes Aligned Bounding Boxes](https://en.wikipedia.org/wiki/Bounding_volume) (AABB). 

**Functions:**
- construction of AABB from list of points
- simple operations with AABBs
- construction of BIH from a list of AABBs
- lookup for AABBs containing a givnen point
- lookup for AABBs intersecting with given AABB

C++ implementation with Python binding.

## Python install

    pip3 install bih
    
See 'test/test_bih_tree.py' for usage example.
    
## C++ build

    mkdir build
    cd build
    cmake ..
    make

See 'test/test_bih_tree.cc' for usage example.
    

