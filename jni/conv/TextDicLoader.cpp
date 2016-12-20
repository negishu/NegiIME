#include "global_utils.h"
#include "TextDicLoader.h"

#include <fstream>
#include <iostream>

TextDicLoader::TextDicLoader(void)
{
}

TextDicLoader::~TextDicLoader(void)
{
}

bool TextDicLoader::Open(const std::string &filename, unsigned int nLimit, unsigned char sep)
{
	Close();

	std::ifstream ifs(filename.c_str());

    std::string line;

	unsigned int count = 0, max = nLimit;

    while (nLimit > 0 && getline(ifs, line)) {

	    std::vector<std::string> fields;

		Split(line, sep, fields);

		if (fields.size() < 1) continue;
		
		if (ProcessLine(fields)) {
	
			nLimit--; count ++;
	    }

		if (count % 2000 == 0) {

			std::cerr << "READ " << count << " lines" << std::endl;
		}
	}

	std::cerr << "READ " << count << " lines" << std::endl;
	std::cerr << "Finish reading..." << std::endl;

	return true;
}

void TextDicLoader::Close()
{
}
