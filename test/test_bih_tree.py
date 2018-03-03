import sys
#build_path="/home/jb/workspace/bih/build"
#sys.path+=[build_path]

import pytest
import bih
import numpy as np

points = np.array([[0.0, 0.0, 0.0]])
points = [[0.0, 0.0, 0.0], [1,1,1], [-1, 2, 0]]

# Test basic AABB methods
def test_basic_aabb():
    box=bih.AABB(points)
    assert box.min() == [-1, 0, 0]
    assert box.max() == [1, 2, 1]
    assert box.center() == [0, 1, 0.5]
    box.add_point([3,4,5])
    assert box.max() == [3,4,5]


#Test basic BIH methods
def test_bih():
    tree = bih.BIH()


    coords = [ 0, 0.5, 1, 1.5, 2]

    boxes = [ bih.AABB( [[p,0,0], [p+1, 1,1]]) for p in coords ]
    tree.add_boxes( boxes )
    tree.construct()
    intersect_box_ids = tree.find_point([0.7, 0.5, 0.5])
    intersect_box_ids.sort()
    assert intersect_box_ids == [0, 1]

    box = bih.AABB([[0.7, 0.5, 0.5], [1.3, 0.5,0.5]])
    intersect_box_ids = tree.find_box(box)
    intersect_box_ids.sort()
    assert intersect_box_ids == [0, 1, 2], "intersect_box_ids: {}".format(intersect_box_ids)

