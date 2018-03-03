/*
 * python_bih_tree.cc
 *
 *  Created on: Aug 30, 2017
 *      Author: jb
 */

#include <pybind11/pybind11.h>
//#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "bih.hh"
#include "bounding_box.hh"

namespace py = pybind11;
using namespace std;



// Python binding BoundingBox wrapper
/*
class AABB : public BoundingBox
{
    AABB()
};

*/

std::vector<unsigned int> tree_find_point(BIHTree *tree, Point &point, bool full_list) {
    std::vector<unsigned int> result;
    tree->find_point(point, result, full_list);
    return result;
}

std::vector<unsigned int> tree_find_box(BIHTree *tree, BoundingBox &box, bool full_list) {
    std::vector<unsigned int> result;
    tree->find_bounding_box(box, result, full_list);
    return result;
}


// TODO: use PYBIND11_MODULE
PYBIND11_MODULE(bih, m) {
    //py::module m( "bih", );
    m.doc() = "Bounding Inteval Hierarchy of Axes Aligned Bounding Boxes.";
    py::class_<BoundingBox>(m, "AABB")
        .def(py::init<const vector<Point> &>())
        .def("min", (const Point&(BoundingBox::*)() const) &BoundingBox::min , py::return_value_policy::reference)  // need conversion to numpy array
        .def("max", (const Point&(BoundingBox::*)() const) &BoundingBox::max , py::return_value_policy::reference)  // need conversion to numpy array
        .def("size", &BoundingBox::size)
        .def("center", &BoundingBox::center) /// return Point, must convert to numpy array
        .def("projection_center", &BoundingBox::projection_center,
                "Return center of projection of the bounding box to given @p axis."
                "Axis coding is: 0 - axis x, 1 - axis y, 2 - axis z.")
        .def("contains_point", &BoundingBox::contains_point,        // need conversion of argument
                "Returns true is the  box element contains point.")

        .def("intersect", &BoundingBox::intersect,                  // hopefully correct
                "Returns true if two bounding boxes have intersection.")
        .def("add_point", (void (BoundingBox::*)(const Point&)) &BoundingBox::expand,
                "Expand bounding box to contain also given @p point.")
        .def("add_box", (void (BoundingBox::*)(const BoundingBox&)) &BoundingBox::expand,
                "Expand bounding box to contain also given @p point.");


//        /**
//         * Returns true if projection of the box to @p axis is an interval
//         * less then (with tolerance) to given @p value.
//         */
//        bool projection_lt(unsigned int axis, double value) const
//        {
//            return max_vertex_[axis] + epsilon < value;
//        }
//
//        /**
//         * Returns true if projection of the box to @p axis is an interval
//         * greater then (with tolerance) to given @p value.
//         */
//        bool projection_gt(unsigned int axis, double value) const
//        {
//            return min_vertex_[axis] - epsilon > value;
//        }

//        /**
//         * Split box into two boxes along @p axis by the
//         * plane going through @p splitting_point on the axis.
//         */
//        void split(unsigned int axis, double splitting_point,
//                BoundingBox &left, BoundingBox &right ) const
//        {
//            ASSERT(axis < dimension, "");
//            if (min_vertex_[axis] <= splitting_point && splitting_point <= max_vertex_[axis] ) {
//                left = *this;
//                right = *this;
//                left.max_vertex_[axis] = splitting_point;
//                right.min_vertex_[axis] = splitting_point;
//            } else {
//                throw;
//                //THROW( ExcSplitting() << EI_interval_left(min_vertex_[axis])
//                //                    << EI_interval_right(max_vertex_[axis])
//                //                    << EI_split_point(splitting_point) );
//            }
//        }

//        /**
//         * Return index of the axis in which the box has longest projection.
//         */
//       unsigned char longest_axis() const {
//           auto diff=max_vertex_ - min_vertex_;
//           return (diff[1] > diff[0])
//                       ?  ( diff[2] > diff[1] ? 2 : 1 )
//                       :  ( diff[2] > diff[0] ? 2 : 0 );
//       }




    py::class_<BIHTree>(m, "BIH")
        .def(py::init<unsigned int>(), py::arg("soft_leaf_size_limit")  = 20)
        .def("add_boxes", &BIHTree::add_boxes)
        .def("construct", &BIHTree::construct)
        .def("find_box", &tree_find_box,
                 py::arg("box"),  py::arg("full_list") = false)
        .def("find_point", &tree_find_point,
                 py::arg("point"),  py::arg("full_list") = false);
    //return m.ptr();
   
}



