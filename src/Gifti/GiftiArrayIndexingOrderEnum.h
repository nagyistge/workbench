#ifndef __GIFTIARRAYINDEXINGORDER_H__
#define __GIFTIARRAYINDEXINGORDER_H__

/*LICENSE_START*/
/*
 *  Copyright (C) 2014  Washington University School of Medicine
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
/*LICENSE_END*/


#include "GiftiException.h"

#include <stdint.h>
#include <vector>
#include <AString.h>

namespace caret {

/**
 * Type for GIFTI Data Array ArrayIndexingOrder Attribute.
 */
class GiftiArrayIndexingOrderEnum {

public:
    /**  Type for GIFTI Data Array ArrayIndexingOrder Attribute.
 */
    enum Enum {
        /** Column-Major Order (Fortran/Matlab)  */
        COLUMN_MAJOR_ORDER,
        /** Row-Major Order (C/C++/Java)  */
        ROW_MAJOR_ORDER
    };
    
    ~GiftiArrayIndexingOrderEnum();

    static AString toName(Enum e);
    
    static Enum fromName(const AString& s, bool* isValidOut);
    
    static AString toGiftiName(Enum e);
    
    static Enum fromGiftiName(const AString& s, bool* isValidOut);
    

private:
    GiftiArrayIndexingOrderEnum(const Enum e, 
                            const AString& name,
                            const AString& giftiName);

    static const GiftiArrayIndexingOrderEnum* findData(const Enum e);
    
    static std::vector<GiftiArrayIndexingOrderEnum> enumData;

    static void initialize();

    static bool initializedFlag;

    Enum e;

    AString name;

    AString giftiName;
};

#ifdef __GIFTIARRAYINDEXINGORDER_DECLARE__
std::vector<GiftiArrayIndexingOrderEnum> GiftiArrayIndexingOrderEnum::enumData;
bool GiftiArrayIndexingOrderEnum::initializedFlag = false;
#endif // __GIFTIARRAYINDEXINGORDER_DECLARE__

} // namespace

#endif // __GIFTIARRAYINDEXINGORDER_H__
