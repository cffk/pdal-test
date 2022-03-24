#include "eigentest.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <pdal/pdal_internal.hpp>

namespace pdal {

  static PluginInfo const s_info {
    "filters.eigentest",
      "Testing pdal vs eigen",
      "http://link/to/documentation"
      };

  CREATE_SHARED_STAGE(EigenTest, s_info)

  std::string EigenTest::getName() const { return s_info.name; }

  void EigenTest::addArgs(ProgramArgs& args) {
    args.add("eigentest", "Run eigen", m_eigentest, false);
  }

  PointViewSet EigenTest::run(PointViewPtr input) {
    if (m_eigentest) {
      Eigen::MatrixXd A(10,6);
      Eigen::MatrixXd B(10,1);
      Eigen::MatrixXd y(6,1);
      Eigen::MatrixXd z(6,1);
      A <<
        748, 0, -23, -732, 0, 22,
        0, 748, -250, 0, -732, 244,
        687, 0, -22, -617, 0, 19,
        0, 687, -223, 0, -617, 199,
        655, 0, -22, -462, 0, 15,
        0, 655, -212, 0, -462, 149,
        633, 0, -20, -407, 0, 12,
        0, 633, 267, 0, -407, -172,
        572, 0, -19, -336, 0, 10,
        0, 572, -167, 0, -336, 97;
      B <<
        221,
        -2873,
        163,
        -2596,
        67,
        -2469,
        48,
        629,
        13,
        -2044;
      // Octave's solution y = A\B;
      y <<
        -0.146455,
        -1.742942,
        6.276087,
        -0.655561,
        -0.061288,
        -0.183508;

      // Eigen's solution
      z = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);
      std::cout << "z = A\B (pdal eigen) =\n" << z << "\n";
    }
    PointViewSet viewSet;
    viewSet.insert(input);
    return viewSet;
  }

} // namespace pdal
