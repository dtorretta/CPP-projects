#include "../includes/Replace.hpp"

Replace::Replace(const std::string file, const std::string s1, const std::string s2)
        : _filename(file), _s1(s1), _s2(s2) {}
        

std::string Replace::getString (const std::string str)
{
    if (str == "s1")
        return(_s1);
    if (str == "s2")
        return(_s2);
    if (str == "name")
        return(_filename);
    return "";
}

std::string Replace::ft_replace (std::string line)
{
    std::string result;
    std::string s1 = getString("s1");
    std::string s2 = getString("s2");
    size_t i = 0;
    
    size_t found = line.find(s1);
    
    if(found == std::string::npos)
        return line;
    while(found != std::string::npos)
	{
		result.append(line, i, found - i);
		result.append(s2);
		
		i = found + s1.length();
		
		found = line.find(s1, i);
	}
	result.append(line, i, found - i);
	return result;
}
