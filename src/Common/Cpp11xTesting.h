#ifndef __CPP11X_TESTING_H__
#define __CPP11X_TESTING_H__

/*LICENSE_START*/
/*
 * Copyright 2013 Washington University,
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


//#define HAVE_CXX_11


#ifdef HAVE_CXX_11

namespace caret {

    class Cpp11xTesting {
        
    public:
        Cpp11xTesting();
        
        Cpp11xTesting(const int value);
        
        virtual void methodName() noexcept;
        
        virtual ~Cpp11xTesting();
        
    private:
        Cpp11xTesting(const Cpp11xTesting&);

        Cpp11xTesting& operator=(const Cpp11xTesting&);
        
        void test();

        /*
         * Initialization of a member's value.
         */
        int m_x = 5;
    
        /*
         * Initialize a static members value
         */
        static float s_y = 9.0;
    
    };
    
    class SubClass : public Cp11xTesting {
        
        SubClass() : Cp11xTesting(5) { }
        
        virtual ~SubClass() { }
        
        virtual void methodName() override noexcept;
    }
#ifdef __CPP11X_TESTING_DECLARE__
    // <PLACE DECLARATIONS OF STATIC MEMBERS HERE>
#endif // __CPP11X_TESTING_DECLARE__

} // namespace
#endif  //__CPP11X_TESTING_H__


#endif // HAVE_CXX_11