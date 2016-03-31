#ifndef COMPAT_H
#define COMPAT_H

#ifdef ANDROID
#define NO_TO_STRING
#define NO_STOUL
#endif

#include <string>

#ifdef NO_TO_STRING
#include <sstream>
#endif

#if defined(NO_STOUL) || defined(NO_STOI)
#include <cstdlib>
#endif


namespace cpt
{
	template<typename T>
	static std::string to_string(const T& t)
	{
	#ifdef NO_TO_STRING
		std::stringstream ss;
		ss << t;
		return ss.str();
	#else
		return std::to_string(t);
	#endif
	}

	static long stoul(const std::string& s)
	{
	#ifdef NO_STOUL
		return atol(s.c_str());
	#else
		return std::stoul(s);
	#endif
	}


	static int stoi(const std::string& str)
	{
	#ifdef NO_STOI
		return strtol(str.c_str(), 0, 10);
	#else
		return std::stoi(str);
	#endif
	}
}


#endif

