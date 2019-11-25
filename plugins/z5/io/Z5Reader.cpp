/******************************************************************************
* Copyright (c) 2019, Howard Butler (howard@hobu.co)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
*
****************************************************************************/

#include "Z5Reader.hpp"

#include <pdal/util/ProgramArgs.hpp>
#include <pdal/PDALUtils.hpp>
#include <z5/file.hxx>

namespace pdal
{

static PluginInfo const s_info
{
    "readers.z5",
    "Z5 Reader",
    "http://pdal.io/stages/readers.z5.html"
};

CREATE_SHARED_STAGE(Z5Reader, s_info)

std::string Z5Reader::getName() const { return s_info.name; }


void Z5Reader::addArgs(ProgramArgs& args)
{
//     args.add("rdtp", "", m_isRdtp, DEFAULT_IS_RDTP);
//     args.add("sync_to_pps", "Sync to PPS", m_syncToPps, DEFAULT_SYNC_TO_PPS);
//     args.add("reflectance_as_intensity", "Reflectance as intensity", m_reflectanceAsIntensity, DEFAULT_REFLECTANCE_AS_INTENSITY);
//     args.add("min_reflectance", "Minimum reflectance", m_minReflectance, DEFAULT_MIN_REFLECTANCE);
//     args.add("max_reflectance", "Maximum reflectance", m_maxReflectance, DEFAULT_MAX_REFLECTANCE);
}

void Z5Reader::initialize()
{
    if (pdal::Utils::isRemote(m_filename))
        m_filename = pdal::Utils::fetchRemote(m_filename);
}


void Z5Reader::addDimensions(PointLayoutPtr layout)
{
//     layout->registerDims(getZ5Dimensions(m_syncToPps, m_reflectanceAsIntensity));
}


void Z5Reader::ready(PointTableRef table)
{
}


point_count_t Z5Reader::read(PointViewPtr view, point_count_t num)
{
    point_count_t numRead = 0;
    PointRef point(view->point(0));
    while (numRead < num ) {
        point.setPointId(numRead);
        processOne(point);
        ++numRead;
    }
    return numRead;
}


bool Z5Reader::processOne(PointRef& point)
{
//     return m_pointcloud->readOne(point);
    return true;
}


void Z5Reader::done(PointTableRef table)
{
}


} // namespace pdal
