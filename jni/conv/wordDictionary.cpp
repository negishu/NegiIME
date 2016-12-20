#include "wordDictionary.h"

#ifdef WIN32
#include "./dict.word.h"
#else
#include "./dict.word.h"
#endif

wordDictionary::wordDictionary()
{
	Init();
}

wordDictionary::~wordDictionary(void)
{
}
