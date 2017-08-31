/*
 * test_bih_tree.cc
 *
 *  Created on: Aug 31, 2017
 *      Author: jb
 */




/*
 * bih_tree_test.cpp
 *
 *  Created on: Oct 22, 2012
 *      Author: jb
 */



/*
 * NOTE: This unit test uses asserts defined in namespace feal, not asseerts defined
 * in gtest library.
 */

#include <cmath>
#include <algorithm>
#include <fstream>

#include "bounding_box.hh"
#include "bih_tree.hh"


void test_aabb() {
    BoundingBox a;
    BoundingBox b(Point({0,0,0,}));
    BoundingBox c(Point({0,0,0,}), Point({1,1,1}));
    BoundingBox d(Point({0,0,0,}), Point({1,1,1}));
    BoundingBox e({Point({0,0,0,}), Point({1,1,1}), Point({2,3,-5})});
}

void test_bih_tree() {

}

int main() {
    test_aabb();
    test_bih_tree();

}
