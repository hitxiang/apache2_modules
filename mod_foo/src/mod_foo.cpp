/* 
 * File:   mod_foo.cpp
 * Author: ming.zhang
 * 
 * Created on May 29, 2014, 11:22 AM
 */

#include "mod_foo.hpp"
#include "CApplication.hpp"

/* Custom definition to hold any configuration data we may need.
   At this stage we just use it to keep a copy of the CApplication
   object pointer. Later we will add more when we need specific custom
   configuration information. */
EXTERN_C_BLOCK_BEGIN
typedef struct
{
    void* vpCApplication;
} 
FOOCONFIG_t;
EXTERN_C_BLOCK_END
        
/* Forward reference to our custom function to save the FOOCONFIG_t* 
   configuration pointer with Apache. */
EXTERN_C_FUNC 
void foo_register_config_ptr( request_rec* inpRequest, FOOCONFIG_t* inpFooConfig );

/* Forward reference to our custom function to get the FOOCONFIG_t* 
   configuration pointer when we need it. */
EXTERN_C_FUNC 
FOOCONFIG_t* foo_get_config_ptr( request_rec* inpRequest );

/* Custom function to ensure our CApplication get's deleted at the
   end of the request cycle. */
EXTERN_C_FUNC
apr_status_t foo_delete_capplication_object( void* inPtr )
{
    if ( inPtr )
        delete ( CApplication* )inPtr;
	
    return OK;
}

/* Our custom handler (content generator) */
EXTERN_C_FUNC
int foo_handler( request_rec* inpRequest )
{
//    int nReturnVal = DECLINED;
//	
//    if ( inpRequest->handler != NULL && strcmp( inpRequest->handler, "foo" ) == 0 )
//    {
//        ap_rputs( "Hello World from FOO", inpRequest );
//        nReturnVal = OK;
//    }
//
//    return nReturnVal;
    /* Create an instance of our application. */
    CApplication* pApp = new CApplication( inpRequest );
	
    if ( pApp == NULL )
	    return HTTP_SERVICE_UNAVAILABLE;
		    
    /* Register a C function to delete pApp
       at the end of the request cycle. */
    apr_pool_cleanup_register( 
        inpRequest->pool, 
        ( void* )pApp, 
        foo_delete_capplication_object, 
        apr_pool_cleanup_null 
    );
		
    /* Reserve a temporary memory block from the
       request pool to store data between hooks. */
    FOOCONFIG_t* pFooConfig = 
        ( FOOCONFIG_t* ) apr_palloc( 
            inpRequest->pool, sizeof( FOOCONFIG_t ) );
		
    /* Remember our application pointer for future calls. */
    pFooConfig->vpCApplication = ( void* )pApp;
		
    /* Register our config data structure for our module. */
    foo_register_config_ptr( inpRequest, pFooConfig );
		
    /* Run our application handler. */
    return pApp->RunHandler();   
}

/* Apache callback to register our hooks.*/
EXTERN_C_FUNC
void foo_hooks( apr_pool_t* inpPool )
{
    ap_hook_handler( foo_handler, NULL, NULL, APR_HOOK_MIDDLE );
}

/* Our standard module definition. */
EXTERN_C_BLOCK_BEGIN
module AP_MODULE_DECLARE_DATA foo_module =
{
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    foo_hooks
};
EXTERN_C_BLOCK_END

/* Custom function to register our FOOCONFIG_t* pointer with Apache
   for retrieval later as required. */
EXTERN_C_FUNC
void foo_register_capplication_ptr( request_rec* inpRequest, FOOCONFIG_t* inpPtr )
{
    ap_set_module_config( inpRequest->request_config, &foo_module, ( void* )inpPtr );
}

/* Custom function to retrieve our FOOCONFIG_t* pointer previously
   registered with Apache on this request cycle. */
EXTERN_C_FUNC
FOOCONFIG_t* foo_get_capplication_ptr( request_rec* inpRequest )
{
    FOOCONFIG_t* pReturnValue = NULL;
	
    if ( inpRequest != NULL )
    {
        pReturnValue = 
            ( FOOCONFIG_t* )ap_get_module_config( 
                inpRequest->request_config, &foo_module );
    }
	
    return pReturnValue;
}