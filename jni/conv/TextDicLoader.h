#pragma once

#include <vector>
#include <string>

class TextDicLoader
{
public:
    
    TextDicLoader(void);
    
    virtual ~TextDicLoader(void);
    
	virtual bool Open(const std::string &filename, unsigned int nLimit = -1, unsigned char sep = '\t');
    
    void Close();

protected:

	virtual bool ProcessLine(const std::vector<std::string>& fields) = 0;
};
