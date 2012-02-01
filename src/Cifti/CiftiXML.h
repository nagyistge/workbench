/*LICENSE_START*/
/*
 *  Copyright 1995-2011 Washington University School of Medicine
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
/*LICENSE_END*/
#ifndef __CIFTI_XML
#define __CIFTI_XML
#include "StructureEnum.h"
#include "CiftiXMLElements.h"
#include "CiftiXMLReader.h"
#include "CiftiXMLWriter.h"
#include "VolumeFile.h"
#include <QtCore>

namespace caret {
/// Simple Container class for storing Cifti XML meta data
    struct CiftiSurfaceMap
    {
        int64_t m_ciftiIndex;
        int64_t m_surfaceNode;
    };
    
    struct CiftiVolumeMap
    {
        int64_t m_ciftiIndex;
        int64_t m_ijk[3];
    };
    
    class CiftiXML {
    public:
        //TODO create initializers for various types of XML meta data (Dense Connectivity, Dense Time Series, etc)
        /**
        * Default Constructor
        *
        * Default Constructor
        */
        CiftiXML() { }
        /**
        * Constructor
        *
        * Constructor, create class using already existing Cifti xml tree
        * @param xml_root
        */
        CiftiXML(CiftiRootElement &xml_root) { m_root = xml_root; rootChanged(); }
        /**
        * Constructor
        *
        * Constructor, create class using ASCII formatted byte array that
        * containes xml meta data text
        * @param bytes
        */
        CiftiXML(const QByteArray &bytes) { readXML(bytes); }
        /**
        * Constructor
        *
        * Constructor, create class using QString that contains xml
        * meta data text
        * @param xml_string
        */
        CiftiXML(const QString &xml_string) { readXML(xml_string); }
        /**
        * Constructor
        *
        * Constructor, create class using QXmlStreamReader.
        * QXmlStreamReader is assumed to be reading from Cifti XML
        * Text.
        * @param xml_stream
        */
        CiftiXML(QXmlStreamReader &xml_stream) { readXML(xml_stream); }
        /**
        * readXML
        *
        * readXML, replacing the currently Cifti XML Root, if it exists
        * @param bytes an ASCII formatted byte array that contains Cifti XML data
        */
        void readXML(const QByteArray &bytes) { QString text(bytes);readXML(text);}
        /**
        * readXML
        *
        * readXML, replacing the currently Cifti XML Root, if it exists
        * @param text QString that contains Cifti XML data
        */
        void readXML(const QString &text) {QXmlStreamReader xml(text); readXML(xml);}
        /**
        * readXML
        *
        * readXML, replacing the currently Cifti XML Root, if it exists
        * @param xml_stream
        */
        void readXML(QXmlStreamReader &xml_stream) { parseCiftiXML(xml_stream,m_root); rootChanged(); }
        /**
        * writeXML
        *
        * write the Cifti XML data to the supplied QString
        * @param text
        */
        void writeXML(QString &text) { QXmlStreamWriter xml(&text); writeCiftiXML(xml,m_root);}
        /**
        * writeXML
        *
        * write the Cifti XML data to the supplied byte array.
        * @param bytes
        */
        void writeXML(QByteArray &bytes) { QXmlStreamWriter xml(&bytes); writeCiftiXML(xml,m_root);}

        /**
        * setXMLRoot
        *
        * set the Cifti XML root
        * @param xml_root
        */
        void setXMLRoot (CiftiRootElement &xml_root) { m_root = xml_root; rootChanged(); }
        /**
        * getXMLRoot
        *
        * get a copy of the Cifti XML Root
        * @param xml_root
        */
        void getXMLRoot (CiftiRootElement &xml_root) { xml_root = m_root; }
        
        ///get the row index for a node, returns -1 if it doesn't find a matching mapping
        int64_t getRowIndexForNode(const int64_t node, const StructureEnum::Enum structure) const;
        
        ///get the column index for a node, returns -1 if it doesn't find a matching mapping
        int64_t getColumnIndexForNode(const int64_t node, const StructureEnum::Enum structure) const;
        
        ///SLOW! - get the row index for a voxel, returns -1 if it doesn't find a matching mapping
        int64_t getRowIndexForVoxel(const int64_t* ijk) const;
        
        ///SLOW! - get the column index for a voxel, returns -1 if it doesn't find a matching mapping
        int64_t getColumnIndexForVoxel(const int64_t* ijk) const;
        
        ///SLOW! - get the column index for a voxel coordinate, returns -1 if the closest indexes have no cifti data
        int64_t getRowIndexForVoxelCoordinate(const float* xyz) const;
        
        ///SLOW! - get the column index for a voxel coordinate, returns -1 if the closest indexes have no cifti data
        int64_t getColumnIndexForVoxelCoordinate(const float* xyz) const;
        
        ///get row index for a timepoint
        int64_t getRowIndexForTimepoint(const float seconds) const;
        
        ///get row index for a timepoint
        int64_t getColumnIndexForTimepoint(const float seconds) const;
        
        ///get the mapping for a surface in rows, returns false and empty vector if not found
        bool getSurfaceMapForRows(std::vector<CiftiSurfaceMap>& mappingOut, const StructureEnum::Enum structure) const;
        
        ///get the mapping for a surface in columns, returns false and empty vector if not found
        bool getSurfaceMapForColumns(std::vector<CiftiSurfaceMap>& mappingOut, const StructureEnum::Enum structure) const;
            
        ///get the mapping for a surface in rows, returns false and empty vector if not found
        bool getVolumeMapForRows(std::vector<CiftiVolumeMap>& mappingOut) const;
        
        ///get the mapping for a surface in columns, returns false and empty vector if not found
        bool getVolumeMapForColumns(std::vector<CiftiVolumeMap>& mappingOut) const;
            
        ///get the original number of nodes of the surfaces used to make this cifti, for rows
        int64_t getRowSurfaceNumberOfNodes(const StructureEnum::Enum structure) const;
        
        ///get the original number of nodes of the surfaces used to make this cifti, for columns
        int64_t getColumnSurfaceNumberOfNodes(const StructureEnum::Enum structure) const;
        
        ///get the timestep for rows, returns false if not timeseries
        bool getRowTimestep(float& seconds) const;
        
        ///get the timestep for columns, returns false if not timeseries
        bool getColumnTimestep(float& seconds) const;
        
        ///set the timestep for rows, returns false if not timeseries
        bool setRowTimestep(float& seconds);
        
        ///set the timestep for columns, returns false if not timeseries
        bool setColumnTimestep(float& seconds);
        
        ///get dimensions, spacing, origin for the volume attribute - returns false if not plumb
        bool getVolumeAttributesForPlumb(VolumeFile::OrientTypes orientOut[3], int64_t dimensionsOut[3], float originOut[3], float spacingOut[3]) const;
        
        ///check what types of data it has
        bool hasRowVolumeData() const;
        bool hasColumnVolumeData() const;
        bool hasRowSurfaceData(const StructureEnum::Enum structure) const;
        bool hasColumnSurfaceData(const StructureEnum::Enum structure) const;
        
        CiftiXML& operator=(const CiftiXML& right);
    protected:
        CiftiRootElement m_root;
        CiftiMatrixIndicesMapElement* m_rowMap, *m_colMap;//assumes only one matrix
        int64_t m_rowVoxels, m_colVoxels;
        
        ///updates the member variables associated with our root
        void rootChanged();
        
        ///convenience functions to grab the correct model out of the tree, to replace the rowLeft/rowRight stuff (since we might have other surfaces too)
        const CiftiBrainModelElement* findSurfaceModel(const CiftiMatrixIndicesMapElement* myMap, StructureEnum::Enum structure) const;
        const CiftiBrainModelElement* findVolumeModel(const CiftiMatrixIndicesMapElement* myMap, StructureEnum::Enum structure) const;
        
        ///some boilerplate to get the correct index in a particular mapping
        int64_t getSurfaceIndex(const int64_t node, const CiftiBrainModelElement* myModel) const;
        int64_t getVolumeIndex(const int64_t* ijk, const CiftiMatrixIndicesMapElement* myMap) const;
        int64_t getVolumeIndex(const float* xyz, const CiftiMatrixIndicesMapElement* myMap) const;
        int64_t getTimestepIndex(const float seconds, const CiftiMatrixIndicesMapElement* myMap) const;
        bool getTimestep(float& seconds, const CiftiMatrixIndicesMapElement* myMap) const;
        bool setTimestep(float& seconds, CiftiMatrixIndicesMapElement* myMap);
        
        ///some boilerplate to build mappings
        bool getSurfaceMapping(std::vector<CiftiSurfaceMap>& mappingOut, const CiftiBrainModelElement* myModel) const;
        bool getVolumeMapping(std::vector<CiftiVolumeMap>& mappingOut, const CiftiMatrixIndicesMapElement* myMap, const int64_t myCount) const;
        
        ///boilerplate for has data
        bool hasVolumeData(const CiftiMatrixIndicesMapElement* myMap) const;
    };

}
#endif//__CIFTI_XML
