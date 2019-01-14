#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <girgs/Generator.h>

namespace py = pybind11;

PYBIND11_MODULE(pygirgs, m) {
	py::class_<girgs::Generator>(m, "Generator")
		.def(py::init())
		.def("set_weights", (void (girgs::Generator::*)(int, double, int)) &girgs::Generator::setWeights)
		.def("set_positions", (void (girgs::Generator::*)(int, int, int)) &girgs::Generator::setPositions)
		.def("scale_weights", (void (girgs::Generator::*)(double, int, double)) &girgs::Generator::scaleWeights)
		.def("generate", (void (girgs::Generator::*)(double, int)) &girgs::Generator::generate)
		.def("edges", &girgs::Generator::edges)
		.def("edge_list", &girgs::Generator::edgeList)
	;

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}