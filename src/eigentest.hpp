#pragma once

#include <pdal/pdal_internal.hpp>
#include <pdal/Filter.hpp>

namespace pdal {

  class PDAL_DLL EigenTest : public Filter {
  public:
    EigenTest() : Filter() {}
    std::string getName() const;

  private:
    bool m_eigentest;

    virtual void addArgs(ProgramArgs& args);
    virtual PointViewSet run(PointViewPtr view);

    EigenTest& operator=(const EigenTest&); // not implemented
    EigenTest(const EigenTest&); // not implemented
  };

} // namespace pdal
