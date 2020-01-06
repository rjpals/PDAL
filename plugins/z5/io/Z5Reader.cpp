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

#include <z5/factory.hxx>
namespace pdal
{


// Z5Info::~Z5Info()
// {
//         if (handle)
//             delete handle;
// }


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
    args.add("dataset", "Zarr dataset name", m_datasetName, "");
    args.add("group", "Zarr dataset name", m_groupName, "");
//     args.add("sync_to_pps", "Sync to PPS", m_syncToPps, DEFAULT_SYNC_TO_PPS);
//     args.add("reflectance_as_intensity", "Reflectance as intensity", m_reflectanceAsIntensity, DEFAULT_REFLECTANCE_AS_INTENSITY);
//     args.add("min_reflectance", "Minimum reflectance", m_minReflectance, DEFAULT_MIN_REFLECTANCE);
//     args.add("max_reflectance", "Maximum reflectance", m_maxReflectance, DEFAULT_MAX_REFLECTANCE);
}

void Z5Reader::initialize()
{
    m_file = new z5::filesystem::handle::File(m_filename); //, z5::FileMode::r);
    if (!m_file->isZarr())
        throw pdal_error("File '" + m_filename +"' is not a Zarr!");

    m_group = new z5::filesystem::handle::Group(*m_file, m_groupName);
    if (!m_group->exists())
        throw pdal_error("Group '" + m_groupName +
                         "' does not exist in the '" +
                         m_filename + "' Zarr");
    m_dataset = new z5::filesystem::handle::Dataset(*m_group, m_datasetName);
    if (!m_dataset->exists())
        throw pdal_error("Dataset '" + m_datasetName+
                         "' does not exist in the '" +
                         m_groupName + "' group");
    z5::filesystem::readMetadata(*m_dataset, *m_metadata);
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
    return false;
    return true;
}


void Z5Reader::done(PointTableRef table)
{
}


} // namespace pdal
