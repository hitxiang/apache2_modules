/* 
 * File:   mod_foo.hpp
 * Author: ming.zhang
 *
 * Created on May 29, 2014, 11:22 AM
 */

#ifndef MOD_FOO_HPP
#define	MOD_FOO_HPP

#ifdef __cplusplus
#define EXTERN_C_BLOCK_BEGIN    extern "C" {
#define EXTERN_C_BLOCK_END      }
#define EXTERN_C_FUNC           extern "C"
#else
#define EXTERN_C_BLOCK_BEGIN
#define EXTERN_C_BLOCK_END
#define EXTERN_C_FUNC
#endif

#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>

#endif	/* MOD_FOO_HPP */

