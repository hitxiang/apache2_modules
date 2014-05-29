/* 
 * File:   CApplication.cpp
 * Author: ming.zhang
 * 
 * Created on May 29, 2014, 11:45 AM
 */

#include "CApplication.hpp"

int
CApplication::RunHandler()
{
    int nReturnVal = DECLINED;
	
    if ( m_pRequestRec->handler != NULL && strcmp( m_pRequestRec->handler, "foo" ) == 0 )
    {
        ap_rputs( "Hello World from FOO", m_pRequestRec );
        nReturnVal = OK;
    }

    return nReturnVal;
}
