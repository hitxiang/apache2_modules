/* 
 * File:   CApplication.cpp
 * Author: ming.zhang
 * 
 * Created on May 29, 2014, 11:45 AM
 */

#include "CApplication.hpp"

#include <string>

int
CApplication::RunHandler()
{
    int nReturnVal = DECLINED;
	
    if ( m_pRequestRec->handler != NULL && strcmp( m_pRequestRec->handler, "foo" ) == 0 )
    {
        std::string result = "This is apache foo module\n";
        result += "Client ip:";
        result += m_pRequestRec->connection->remote_ip ;
        result += "\n";
        ap_rputs( result.c_str(), m_pRequestRec );
        nReturnVal = OK;
    }

    return nReturnVal;
}
