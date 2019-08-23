#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <girgs/Generator.h>
#include <hypergirgs/Generator.h>

namespace py = pybind11;

PYBIND11_MODULE(pygirgs, m) {
	py::module m_girgs = m.def_submodule("girgs", "The GIRG generator submodule");
	m_girgs.def("generate_weights", &girgs::generateWeights);
	m_girgs.def("generate_positions", &girgs::generatePositions);
	m_girgs.def("scale_weights", &girgs::scaleWeights);
	m_girgs.def("generate_edges", &girgs::generateEdges);

	py::module m_hypergirgs = m.def_submodule("hypergirgs", "The HRG generator submodule");
	m_hypergirgs.def("calculate_radius", &hypergirgs::calculateRadius);
	m_hypergirgs.def("sample_radii", &hypergirgs::sampleRadii);
	m_hypergirgs.def("sample_angles", &hypergirgs::sampleAngles);
	m_hypergirgs.def("generate_edges", &hypergirgs::generateEdges);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
