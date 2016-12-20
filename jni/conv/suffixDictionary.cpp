#include "suffixDictionary.h"

#ifdef WIN32
#include "./dict.suffix.h"
#else
#include "./dict.suffix.h"
#endif

suffixDictionary::suffixDictionary()
{
	Init();
}

suffixDictionary::~suffixDictionary(void)
{
}

