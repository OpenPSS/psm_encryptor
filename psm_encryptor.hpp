#ifndef _PSM_ENCRYPTOR_H
#define _PSM_ENCRYPTOR_H 1

#include "PsmEdata.hpp"
#include "PsmHkapp.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32

#ifdef _PSM_SIGNTOOL_BUILD
	__declspec(dllexport) ScePsmEdataStatus scePsmEdataEncryptForRetail(const char* infile, const char* outfile, const char* installPath, ScePsmEdataType type, const char* contentId, const unsigned char* gameKey, const unsigned char* vitaHmacKey, const unsigned char* androidHmacKey);
#endif
	__declspec(dllexport) ScePsmEdataStatus scePsmEdataEncrypt(const char* infile, const char* outfile, const char* installPath, ScePsmEdataType type, uint8_t* devPkcs12, std::size_t devPkcs12Size, PsmHkapp* hostKdbg, std::size_t hostKdbgSize);
	__declspec(dllexport) ScePsmEdataStatus scePsmGetVersion(char* buildVersion, char* buildDate);
#else
#ifdef _PSM_SIGNTOOL_BUILD
	ScePsmEdataStatus scePsmEdataEncryptForRetail(const char* infile, const char* outfile, const char* installPath, ScePsmEdataType type, const char* contentId, const unsigned char* gameKey, const unsigned char* vitaHmacKey, const unsigned char* androidHmacKey);
#endif
	ScePsmEdataStatus scePsmEdataEncrypt(const char* infile, const char* outfile, const char* installPath, ScePsmEdataType type, uint8_t* devPkcs12, std::size_t devPkcs12Size, PsmHkapp* hostKdbg, std::size_t hostKdbgSize);
	ScePsmEdataStatus scePsmGetVersion(char* buildVersion, char* buildDate);
#endif /* _WIN32 */

#ifdef __cplusplus
}
#endif


#endif