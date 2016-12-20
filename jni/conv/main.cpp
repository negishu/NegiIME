
#include ".\\global_utils.h"
#include ".\\utils.h"

#include ".\\suffixDictionary.h"
#include ".\\wordDictionary.h"
#include ".\\Converter.h"

#include <iostream>
#include <conio.h>

int main(int argc, char* argv[])
{
    {
        wordDictionary _wordDictionary;
        _wordDictionary.DoDebug();
    }
    {
        suffixDictionary _suffixDictionary;
       _suffixDictionary.DoDebug();
    }
/*

//Converter _Converter;
//_Converter.Debug();

    Converter _Converter;

    std::system("cls");

    std::string hiragana; hiragana = "‚É‚¢‚ª‚½‚¯‚ñ‚³‚ñ‚¶‚å‚¤‚µ‚³‚ñ‚¿‚­‚É‚¿‚å‚¤‚ß";

    std::string yomi; Utils::SJISToUTF8( hiragana, yomi);

    _wstring wyomi; Utils::SJISToUSC2( hiragana, wyomi);
	
    //std::string key; Utils::USC2ToValue(wyomi, key);
    std::string key; Utils::USC2ToSJIS(wyomi, key);

    std::cout << _Converter.Convert(key);

    char input[256] ={0,}, n = 0;
    
	_wstring winput;

	while (1) {

		char c= _getch();

		std::system("cls");

		if (c == 0x0D) {

			n = 0;
		}
		else {

			if (c == 0x08) {

				input[n] = 0;
				if (n > 0) n--;
				input[n] = 0;
			}
			else {

				input[n++] = c; input[n] = 0;
			}

			_wstring romajiinput;

			Utils::SJISToUSC2(input, romajiinput);
			Utils::RomajiToHiragana(romajiinput,winput);

            //std::string key; Utils::USC2ToValue(winput, key);		
			std::string key; Utils::USC2ToSJIS(winput, key);

			if (key.length() > 0) {
		
				std::cout << _Converter.Convert(key) << std::endl;
			}
		}
	}
*/
	return 0;
}

