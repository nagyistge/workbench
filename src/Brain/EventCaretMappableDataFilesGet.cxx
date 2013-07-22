/*LICENSE_START*/ 
/* 
 *  Copyright 1995-2002 Washington University School of Medicine 
 * 
 *  http://brainmap.wustl.edu 
 * 
 *  This file is part of CARET. 
 * 
 *  CARET is free software; you can redistribute it and/or modify 
 *  it under the terms of the GNU General Public License as published by 
 *  the Free Software Foundation; either version 2 of the License, or 
 *  (at your option) any later version. 
 * 
 *  CARET is distributed in the hope that it will be useful, 
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 *  GNU General Public License for more details. 
 * 
 *  You should have received a copy of the GNU General Public License 
 *  along with CARET; if not, write to the Free Software 
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 * 
 */ 

#include <typeinfo>

#include "CaretAssert.h"
#include "CaretMappableDataFile.h"
#include "CiftiBrainordinateDataSeriesFile.h"
#include "CiftiBrainordinateLabelFile.h"
#include "CiftiBrainordinateScalarFile.h"
#include "CiftiFiberTrajectoryFile.h"
#include "CiftiMappableConnectivityMatrixDataFile.h"
#include "EventCaretMappableDataFilesGet.h"
#include "LabelFile.h"
#include "MetricFile.h"
#include "RgbaFile.h"
#include "VolumeFile.h"

using namespace caret;

/**
 * Constructor for ALL map data files.
 */
EventCaretMappableDataFilesGet::EventCaretMappableDataFilesGet()
: Event(EventTypeEnum::EVENT_CARET_MAPPABLE_DATA_FILES_GET)
{
}

/**
 * Destructor.
 */
EventCaretMappableDataFilesGet::~EventCaretMappableDataFilesGet()
{
    
}

/**
 * Add a map data file.
 * @param mapDataFile
 *    Map data file that is added.
 */
void 
EventCaretMappableDataFilesGet::addFile(CaretMappableDataFile* mapDataFile)
{
    CaretAssert(mapDataFile);
    if (mapDataFile->getNumberOfMaps() <= 0) {
        return;
    }
    
    const DataFileTypeEnum::Enum dataFileType = mapDataFile->getDataFileType();
    if (dataFileType == DataFileTypeEnum::SURFACE) {
        return;
    }

    m_allCaretMappableDataFiles.push_back(mapDataFile);
}

/** 
 * Get all map data files.
 *
 * @param allFilesOut
 *    All map data files output.
 */
void 
EventCaretMappableDataFilesGet::getAllFiles(std::vector<CaretMappableDataFile*>& allFilesOut) const
{
    allFilesOut = m_allCaretMappableDataFiles;
}


