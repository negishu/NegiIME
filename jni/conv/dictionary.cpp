#include "Dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary(void)
{
}

const U08* Dictionary::GetYomiString(const U32 yomiid, U08& len) const
{
	len = _yomibuflen;

	return (const U08*)_LoudsYomiTrie.Reverse(yomiid, (U08*)_yomibuffer, len);
}

const U08* Dictionary::GetWordString(const U32 wordid, U08& len) const
{
	len = _wordbuflen;

	return (const U08*)_LoudsWordTrie.Reverse(wordid, (U08*)_wordbuffer, len);
}

void Dictionary::DoDebug()
{
	for (U32 n = 0; n < 0xFFFFFFFF; n++) {

		U08 len = 0; const U08* yomi_string = GetYomiString(n, len);

		if (yomi_string) {

            std::string yomi_((char*)yomi_string);

            _wstring wyomi; Utils::ValueToUSC2(yomi_, wyomi);

            std::string yomi; Utils::USC2ToSJIS(wyomi, yomi);

			char buf[4096];

			int u = 0;

            u += ::sprintf_s((char*)(buf+u), 1024, "%d\t%s", (int)n, (char*)yomi.c_str());
		
			printf("%s", buf); 

			printf("\n"); 
		}
		else {

			break;
		}
	}

    for (U32 n = 0; n < 0xFFFFFFFF; n++) {

		U08 len = 0; const U08* word_string = GetWordString(n, len);

		if (word_string) {

			char buf[4096];

			int u = 0;

			u += ::sprintf_s((char*)(buf+u), 1024, "%d:%s", (int)n, (char*)word_string);
		
			printf("%s", buf); 

			printf("\n"); 
		}
		else {

			break;
		}
	}

    const bitvectorbasedarray& yomiinfo = GetYomiInfoBitArray();

    for (U32 n = 0; n < 0xFFFFFFFF; n++) {

        U32 wYomiInfoLength = 0;
        U08 uYomiInfoStep   = 0;
        
        const U08 * pYomiData = yomiinfo.Get(n, wYomiInfoLength, uYomiInfoStep);

        if (pYomiData == 0) break;

        char buf[4096]; int u = 0;

        u += ::sprintf_s((char*)(buf+u), 1024, "%d", (int)n);

        for (U32 nYomiPos = 0; nYomiPos < wYomiInfoLength; nYomiPos += uYomiInfoStep) {

            const U32 wMidaID = (pYomiData[nYomiPos + 7] << 16) + (pYomiData[nYomiPos + 6] << 8) + pYomiData[nYomiPos + 5];

            U08 len = 0; const char* pMida = (const char*)(GetWordString(wMidaID, len));

			u += ::sprintf_s((char*)(buf+u), 1024, "\t%s", (char*)pMida);
		}

        printf("%s", buf); 
		printf("\n"); 
	}

    const bitvectorbasedarray& midainfo = GetMidaInfoBitArray();

    for (U32 n = 0; n < 0xFFFFFFFF; n++) {

        U32 wMidaInfoLength = 0;
        U08 uMidaInfoStep   = 0;
        
        const U08 * pMidaData = midainfo.Get(n, wMidaInfoLength, uMidaInfoStep);

        if (pMidaData == 0) break;

        char buf[4096]; int u = 0;

        u += ::sprintf_s((char*)(buf+u), 1024, "%d", (int)n);

        for (U32 nMidaPos = 0; nMidaPos < wMidaInfoLength; nMidaPos += uMidaInfoStep) {

            const U32 wYomiID = (pMidaData[nMidaPos + 2] << 16) + (pMidaData[nMidaPos + 1] << 8) + pMidaData[nMidaPos + 0];

            U08 len = 0; const char* pYomi = (const char*)(GetYomiString(wYomiID, len));

            std::string yomi_((char*)pYomi);

            _wstring wyomi; Utils::ValueToUSC2(yomi_, wyomi);

            std::string yomi; Utils::USC2ToSJIS(wyomi, yomi);

            u += ::sprintf_s((char*)(buf+u), 1024, "\t%s", (char*)yomi.c_str());
		}

        printf("%s", buf); 
		printf("\n"); 
	}

}
