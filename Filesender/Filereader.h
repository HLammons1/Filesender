#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



	class Filereader {

	private:

	public:
		std::string ReturnFileString(std::string path);
		Filereader() = default;
	};

#endif // !_FILEREADER_H
