/* 
 * File:   CApplication.hpp
 * Author: ming.zhang
 *
 * Created on May 29, 2014, 11:45 AM
 */

#ifndef CAPPLICATION_HPP
#define	CAPPLICATION_HPP

#include "mod_foo.hpp"

class CApplication
{
private:

    request_rec*    m_pRequestRec;
	
public:
	
    CApplication( request_rec* inpRequestRec ) :
        m_pRequestRec( inpRequestRec )
    {}
	
    int RunHandler();
};

#endif	/* CAPPLICATION_HPP */

