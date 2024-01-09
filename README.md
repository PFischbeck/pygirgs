This is a fork of the [girgs](https://github.com/chistopher/girgs) package for efficiently generating hyperbolic random graphs and geometric inhomogeneous random graphs.
This repository adds the ability to use the C++ library via Python.

# Installation

Run `pip install .` in this repository.

# Usage

```python
from pygirgs import girgs

dimension = 1

wseed = 123
pseed = 456
sseed = 789

n = 10000
avg_deg = 10.0
beta = 2.5
T = 0.5

alpha = 1 / T

weights = girgs.generate_weights(n, beta, wseed, False)
positions = girgs.generate_positions(n, dimension, pseed, False)
scaling = girgs.scale_weights(weights, avg_deg, dimension, alpha)
weights = [scaling * weight for weight in weights]
edges = girgs.generate_edges(weights, positions, alpha, sseed)

for u, v in edges:
  # Do something with every edge
  pass

```
