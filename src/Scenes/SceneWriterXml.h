#ifndef __SCENE_WRITER_XML__H_
#define __SCENE_WRITER_XML__H_

/*LICENSE_START*/
/*
 * Copyright 2012 Washington University,
 * All rights reserved.
 *
 * Connectome DB and Connectome Workbench are part of the integrated Connectome 
 * Informatics Platform.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of Washington University nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*LICENSE_END*/


#include "SceneWriterInterface.h"

namespace caret {

    class SceneClass;
    class XmlWriter;
    
    class SceneWriterXml : public SceneWriterInterface {
        
    public:
        SceneWriterXml(XmlWriter& xmlWriter);
        
        virtual ~SceneWriterXml();
        
        /**
         * Write the given scene.
         * @param scene
         *    Scene that is written.
         * @param sceneIndex
         *    Index of the scene.
         * @throws SceneException
         *    If there is an error writing the scene.
         */
        virtual void writeScene(const Scene& scene,
                                const int32_t sceneIndex);
        
    private:
        SceneWriterXml(const SceneWriterXml&);

        SceneWriterXml& operator=(const SceneWriterXml&);
        
        void writeSceneClass(const SceneClass& sceneClass);
        
    public:

        // ADD_NEW_METHODS_HERE

    private:

        // ADD_NEW_MEMBERS_HERE

        XmlWriter& m_xmlWriter;
    };
    
#ifdef __SCENE_WRITER_XML_DECLARE__
    // <PLACE DECLARATIONS OF STATIC MEMBERS HERE>
#endif // __SCENE_WRITER_XML_DECLARE__

} // namespace
#endif  //__SCENE_WRITER_XML__H_
