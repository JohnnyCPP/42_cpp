#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

static	bool	notOpen(const std::ifstream& stream, const std::string& fileName)
{
	if (!stream.is_open())
	{
		std::cerr	<< "Error: Could not open file '"
					<< fileName
					<< "'"
					<< std::endl;
		return (true);
	}
	return (false);
}

static	std::string	getContent(const std::string& fileName)
{
	std::ifstream	inputFile(fileName.c_str());
	std::string		content;
	std::string		line;

	if (::notOpen(inputFile, fileName))
		return ("");
	content = "";
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += '\n';
	}
	inputFile.close();
	if (content.empty())
	{
		std::cerr	<< "Error: File '"
					<< fileName
					<< "' is empty"
					<< std::endl;
		return ("");
	}
	return (content);
}

// "std::string::npos" is a special constant value that 
// means "no position" or "not found"
//
// is defined as: static const size_type npos = -1;
//
// indicates the end of a string
static	void	getResult(const std::string& content, const std::string& s1, const std::string& s2, std::string& result)
{
	std::size_t		curr;
	std::size_t		prev;

	result = "";
	curr = 0;
	prev = 0;
	curr = content.find(s1, prev);
	while (curr != std::string::npos)
	{
		result.append(content, prev, curr - prev);
		result.append(s2);
		prev = curr + s1.length();
		curr = content.find(s1, prev);
	}
	result.append(content, prev, std::string::npos);
}

static	bool	writeFile(const std::string& fileName, const std::string& result)
{
	std::ofstream	outputFile(fileName.c_str());

	if (!outputFile.is_open())
	{
		std::cerr	<< "Error: Could not create file '"
					<< fileName
					<< "'"
					<< std::endl;
		return (false);
	}
	outputFile << result;
	outputFile.close();
	return (true);
}

static bool	replaceInFile(const std::string& fileName, const std::string& s1, const std::string& s2)
{
	std::string		outputFileName = fileName + ".replace";
	std::string		content;
	std::string		result;

	content = ::getContent(fileName);
	if (content.empty())
		return (false);
	::getResult(content, s1, s2, result);
	if (!::writeFile(outputFileName, result))
		return (false);
	std::cout	<< "Success: Created '"
				<< outputFileName
				<< "' with replacements"
				<< std::endl;
	return (true);
}

int	main(int argc, char **argv)
{
	std::string	fileName;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cerr	<< "Error: Expected 3 arguments"
					<< std::endl;
		std::cerr	<< "Usage: "
					<< argv[0]
					<< " <filename> <s1> <s2>"
					<< std::endl;
		return (EXIT_FAILURE);
	}
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (fileName.empty() || s1.empty())
	{
		std::cerr << "Error: Filename and s1 cannot be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!::replaceInFile(fileName, s1, s2))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
