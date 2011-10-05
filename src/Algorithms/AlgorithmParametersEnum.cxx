
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

#include <algorithm>
#define __ALGORITHM_PARAMETERS_ENUM_DECLARE__
#include "AlgorithmParametersEnum.h"
#undef __ALGORITHM_PARAMETERS_ENUM_DECLARE__

#include "CaretAssert.h"

using namespace caret;

    
/**
 * \class AlgorithmParametersEnum 
 * \brief enum for parameter types
 *
 * enum for parameter types
 */
/**
 * Constructor.
 *
 * @param enumValue
 *    An enumerated value.
 * @param integerCode
 *    Integer code for this enumerated value.
 *
 * @param name
 *    Name of enumerated value.
 *
 * @param guiName
 *    User-friendly name for use in user-interface.
 */
AlgorithmParametersEnum::AlgorithmParametersEnum(const Enum enumValue,
                           const int32_t integerCode,
                           const AString& name,
                           const AString& guiName)
{
    this->enumValue = enumValue;
    this->integerCode = integerCode;
    this->name = name;
    this->guiName = guiName;
}

/**
 * Destructor.
 */
AlgorithmParametersEnum::~AlgorithmParametersEnum()
{
}

/**
 * Initialize the enumerated metadata.
 */
void
AlgorithmParametersEnum::initialize()
{
    if (initializedFlag) {
        return;
    }
    initializedFlag = true;

    enumData.push_back(AlgorithmParametersEnum(SURFACE, 
                                    0, 
                                    "Surface File", 
                                    "Surface"));
    
    enumData.push_back(AlgorithmParametersEnum(VOLUME, 
                                    1, 
                                    "Volume File", 
                                    "Volume"));
    
    enumData.push_back(AlgorithmParametersEnum(METRIC, 
                                    2, 
                                    "Metric File", 
                                    "Metric"));
    
    enumData.push_back(AlgorithmParametersEnum(LABEL, 
                                    3, 
                                    "Label File", 
                                    "Label"));
    
    enumData.push_back(AlgorithmParametersEnum(CIFTI, 
                                    4, 
                                    "Cifti File", 
                                    "Cifti"));
    
    enumData.push_back(AlgorithmParametersEnum(DOUBLE, 
                                    5, 
                                    "Floating Point", 
                                    "Floating Point"));
    
    enumData.push_back(AlgorithmParametersEnum(INT, 
                                    6, 
                                    "Integer", 
                                    "Integer"));
    
    enumData.push_back(AlgorithmParametersEnum(STRING, 
                                    7, 
                                    "String", 
                                    "String"));
    
    enumData.push_back(AlgorithmParametersEnum(BOOL, 
                                    8, 
                                    "Boolean", 
                                    "Boolean"));
    
}

/**
 * Find the data for and enumerated value.
 * @param enumValue
 *     The enumerated value.
 * @return Pointer to data for this enumerated type
 * or NULL if no data for type or if type is invalid.
 */
const AlgorithmParametersEnum*
AlgorithmParametersEnum::findData(const Enum enumValue)
{
    if (initializedFlag == false) initialize();

    size_t num = enumData.size();
    for (size_t i = 0; i < num; i++) {
        const AlgorithmParametersEnum* d = &enumData[i];
        if (d->enumValue == enumValue) {
            return d;
        }
    }

    return NULL;
}

/**
 * Get a string representation of the enumerated type.
 * @param enumValue 
 *     Enumerated value.
 * @return 
 *     String representing enumerated value.
 */
AString 
AlgorithmParametersEnum::toName(Enum enumValue) {
    if (initializedFlag == false) initialize();
    
    const AlgorithmParametersEnum* enumInstance = findData(enumValue);
    return enumInstance->name;
}

/**
 * Get an enumerated value corresponding to its name.
 * @param name 
 *     Name of enumerated value.
 * @param isValidOut 
 *     If not NULL, it is set indicating that a
 *     enum value exists for the input name.
 * @return 
 *     Enumerated value.
 */
AlgorithmParametersEnum::Enum 
AlgorithmParametersEnum::fromName(const AString& name, bool* isValidOut)
{
    if (initializedFlag == false) initialize();
    
    bool validFlag = false;
    Enum enumValue = SURFACE;
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        const AlgorithmParametersEnum& d = *iter;
        if (d.name == name) {
            enumValue = d.enumValue;
            validFlag = true;
            break;
        }
    }
    
    if (isValidOut != 0) {
        *isValidOut = validFlag;
    }
    else {
        CaretAssertMessage(0, AString("Name " + name + "failed to match enumerated value for type AlgorithmParametersEnum"));
    }
    return enumValue;
}

/**
 * Get a GUI string representation of the enumerated type.
 * @param enumValue 
 *     Enumerated value.
 * @return 
 *     String representing enumerated value.
 */
AString 
AlgorithmParametersEnum::toGuiName(Enum enumValue) {
    if (initializedFlag == false) initialize();
    
    const AlgorithmParametersEnum* enumInstance = findData(enumValue);
    return enumInstance->guiName;
}

/**
 * Get an enumerated value corresponding to its GUI name.
 * @param s 
 *     Name of enumerated value.
 * @param isValidOut 
 *     If not NULL, it is set indicating that a
 *     enum value exists for the input name.
 * @return 
 *     Enumerated value.
 */
AlgorithmParametersEnum::Enum 
AlgorithmParametersEnum::fromGuiName(const AString& guiName, bool* isValidOut)
{
    if (initializedFlag == false) initialize();
    
    bool validFlag = false;
    Enum enumValue = SURFACE;
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        const AlgorithmParametersEnum& d = *iter;
        if (d.guiName == guiName) {
            enumValue = d.enumValue;
            validFlag = true;
            break;
        }
    }
    
    if (isValidOut != 0) {
        *isValidOut = validFlag;
    }
    else {
        CaretAssertMessage(0, AString("guiName " + guiName + "failed to match enumerated value for type AlgorithmParametersEnum"));
    }
    return enumValue;
}

/**
 * Get the integer code for a data type.
 *
 * @return
 *    Integer code for data type.
 */
int32_t
AlgorithmParametersEnum::toIntegerCode(Enum enumValue)
{
    if (initializedFlag == false) initialize();
    const AlgorithmParametersEnum* enumInstance = findData(enumValue);
    return enumInstance->integerCode;
}

/**
 * Find the data type corresponding to an integer code.
 *
 * @param integerCode
 *     Integer code for enum.
 * @param isValidOut
 *     If not NULL, on exit isValidOut will indicate if
 *     integer code is valid.
 * @return
 *     Enum for integer code.
 */
AlgorithmParametersEnum::Enum
AlgorithmParametersEnum::fromIntegerCode(const int32_t integerCode, bool* isValidOut)
{
    if (initializedFlag == false) initialize();
    
    bool validFlag = false;
    Enum enumValue = SURFACE;
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        const AlgorithmParametersEnum& enumInstance = *iter;
        if (enumInstance.integerCode == integerCode) {
            enumValue = enumInstance.enumValue;
            validFlag = true;
            break;
        }
    }
    
    if (isValidOut != 0) {
        *isValidOut = validFlag;
    }
    else {
        CaretAssertMessage(0, AString("Integer code " + AString::number(integerCode) + "failed to match enumerated value for type AlgorithmParametersEnum"));
    }
    return enumValue;
}

/**
 * Get all of the enumerated type values.  The values can be used
 * as parameters to toXXX() methods to get associated metadata.
 *
 * @param allEnums
 *     A vector that is OUTPUT containing all of the enumerated values.
 */
void
AlgorithmParametersEnum::getAllEnums(std::vector<AlgorithmParametersEnum::Enum>& allEnums)
{
    if (initializedFlag == false) initialize();
    
    allEnums.clear();
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        allEnums.push_back(iter->enumValue);
    }
}

/**
 * Get all of the names of the enumerated type values.
 *
 * @param allNames
 *     A vector that is OUTPUT containing all of the names of the enumerated values.
 * @param isSorted
 *     If true, the names are sorted in alphabetical order.
 */
void
AlgorithmParametersEnum::getAllNames(std::vector<AString>& allNames, const bool isSorted)
{
    if (initializedFlag == false) initialize();
    
    allNames.clear();
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        allNames.push_back(AlgorithmParametersEnum::toName(iter->enumValue));
    }
    
    if (isSorted) {
        std::sort(allNames.begin(), allNames.end());
    }
}

/**
 * Get all of the GUI names of the enumerated type values.
 *
 * @param allNames
 *     A vector that is OUTPUT containing all of the GUI names of the enumerated values.
 * @param isSorted
 *     If true, the names are sorted in alphabetical order.
 */
void
AlgorithmParametersEnum::getAllGuiNames(std::vector<AString>& allGuiNames, const bool isSorted)
{
    if (initializedFlag == false) initialize();
    
    allGuiNames.clear();
    
    for (std::vector<AlgorithmParametersEnum>::iterator iter = enumData.begin();
         iter != enumData.end();
         iter++) {
        allGuiNames.push_back(AlgorithmParametersEnum::toGuiName(iter->enumValue));
    }
    
    if (isSorted) {
        std::sort(allGuiNames.begin(), allGuiNames.end());
    }
}

