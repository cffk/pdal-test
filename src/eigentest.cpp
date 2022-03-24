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
        7.485,  0.0, -0.230, -7.3109205793,  0.0,  0.2246508662,
        0.0,  7.485, -2.500,  0.0, -7.3109205793,  2.4418572409,
        6.875,  0.0, -0.220, -6.1628317877,  0.0,  0.1972106172,
        0.0,  6.875, -2.225,  0.0, -6.1628317877,  1.9945164693,
        6.555,  0.0, -0.215, -4.6196552358,  0.0,  0.1515218727,
        0.0,  6.555, -2.115,  0.0, -4.6196552358,  1.4905523759,
        6.330,  0.0, -0.195, -4.0619919943,  0.0,  0.1251324548,
        0.0,  6.330,  2.670,  0.0, -4.0619919943, -1.7133520735,
        5.725,  0.0, -0.185, -3.3511167068,  0.0,  0.1082893608,
        0.0,  5.725, -1.670,  0.0, -3.3511167068,  0.9775309869;
      B <<
        221.7698,
        -2872.97375,
        163.2455,
        -2595.2225,
        67.3519,
        -2468.8023,
        48.50475,
        629.004,
        13.533,
        -2043.4005;
      // Octave's solution y = A\B;
      y <<
        -14.444,
        -157.613,
        678.657,
        -64.717,
        19.913,
        60.963;

      // Eigen's solution
      z = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);
      std::cout << "y=\n" << y << "\n"
                << "z=\n" << z << "\n";
    }
    PointViewSet viewSet;
    viewSet.insert(input);
    return viewSet;
  }

} // namespace pdal
