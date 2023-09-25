
#include <pybind11/pybind11.h>
#include "pricingutil.h"

namespace py = pybind11;

PYBIND11_MODULE(PricingUtil, m)
{
    m.doc() = "pybind11 pricingutil"; // optional module docstring

    py::class_<PricingUtil>(m, "PricingUtil")
        .def(py::init<>())
        .def("formula", &PricingUtil::formula);
}

int main()
{
    return 0;
}
