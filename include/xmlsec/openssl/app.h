/** 
 * XMLSec library
 *
 * This is free software; see Copyright file in the source
 * distribution for preciese wording.
 * 
 * Copyrigth (C) 2002-2003 Aleksey Sanin <aleksey@aleksey.com>
 */
#ifndef __XMLSEC_OPENSSL_APP_H__
#define __XMLSEC_OPENSSL_APP_H__    

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <openssl/pem.h>

#include <xmlsec/xmlsec.h>
#include <xmlsec/keys.h>
#include <xmlsec/keysmngr.h>
#include <xmlsec/transforms.h>

/**
 * Init/shutdown
 */
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppInit		(const char* config);
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppShutdown	(void);

/** 
 * Keys Manager
 */
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppDefaultKeysMngrInit(xmlSecKeysMngrPtr mngr);
XMLSEC_CRYPTO_EXPORT int 		xmlSecOpenSSLAppDefaultKeysMngrAdoptKey(xmlSecKeysMngrPtr mngr,
									 xmlSecKeyPtr key);
XMLSEC_CRYPTO_EXPORT int 		xmlSecOpenSSLAppDefaultKeysMngrLoad(xmlSecKeysMngrPtr mngr,
									 const char* uri);
XMLSEC_CRYPTO_EXPORT int 		xmlSecOpenSSLAppDefaultKeysMngrSave(xmlSecKeysMngrPtr mngr,
									 const char* filename,
									 xmlSecKeyDataType type);
#ifndef XMLSEC_NO_X509
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppKeysMngrCertLoad(xmlSecKeysMngrPtr mngr, 
									 const char *filename, 
									 xmlSecKeyDataFormat format,
									 xmlSecKeyDataType type);
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppKeysMngrAddCertsPath(xmlSecKeysMngrPtr mngr, 
									 const char *path);
#endif /* XMLSEC_NO_X509 */


/** 
 * Keys
 */
XMLSEC_CRYPTO_EXPORT xmlSecKeyPtr	xmlSecOpenSSLAppKeyLoad		(const char *filename, 
									 xmlSecKeyDataFormat format,
									 const char *pwd,
									 pem_password_cb *pwdCallback,
									 void* pwdCallbackCtx);
#ifndef XMLSEC_NO_X509
XMLSEC_CRYPTO_EXPORT xmlSecKeyPtr	xmlSecOpenSSLAppPkcs12Load	(const char* filename, 
									 const char* pwd,
									 pem_password_cb* pwdCallback, 
									 void* pwdCallbackCtx);
XMLSEC_CRYPTO_EXPORT int		xmlSecOpenSSLAppKeyCertLoad	(xmlSecKeyPtr key,
									 const char* filename,
									 xmlSecKeyDataFormat format);
#endif /* XMLSEC_NO_X509 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_OPENSSL_APP_H__ */

