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

#pragma once

#include <memory>

#include <pdal/PointView.hpp>
#include <pdal/Reader.hpp>
#include <pdal/Streamable.hpp>
#include <pdal/util/ProgramArgs.hpp>

#include <z5/handle.hxx>
#include <z5/factory.hxx>
#include <z5/dataset.hxx>
#include <z5/metadata.hxx>



namespace pdal
{


// class Z5Info
// {
// public:
//     z5::filesystem::handle::File* handle;
//     z5::filesystem::handle::Dataset* dataset;
//     z5::DatasetMetadata* metadata;
//
//     Z5Info() :
//         handle(nullptr),
//         dataset(nullptr)
//     {}
//
//     ~Z5Info();
//
// };

class PDAL_DLL Z5Reader : public pdal::Reader, public pdal::Streamable
{
public:
    Z5Reader()
        : pdal::Reader()
        , pdal::Streamable()
    {}

    std::string getName() const;

private:
    virtual void addArgs(ProgramArgs& args);
    virtual void initialize();
    virtual void addDimensions(PointLayoutPtr layout);
    virtual void ready(PointTableRef table);
    virtual point_count_t read(PointViewPtr view, point_count_t num);
    virtual bool processOne(PointRef& point);
    virtual void done(PointTableRef table);

    std::string m_datasetName;
    std::string m_groupName;
    z5::filesystem::handle::File* m_file;
    z5::filesystem::handle::Group* m_group;;
    z5::filesystem::handle::Dataset* m_dataset;
    z5::DatasetMetadata* m_metadata;

};


} // namespace pdal
