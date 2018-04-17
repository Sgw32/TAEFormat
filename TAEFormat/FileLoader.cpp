#include "stdafx.h"
#include "FileLoader.h"

FileLoader::FileLoader()
{
	rDa = new TAE3();
	column = 0;
	step = 5000;
	tstep = 200;
}

FileLoader::~FileLoader()
{
	if (rDa)
		delete rDa;
}

bool FileLoader::parseCommandLine(int argc, char *argv[])
{
	if (argc > 1)
	{
		inputFile = string(argv[1]);
		for (int i = 0; i != argc - 2; i++)
		{
			processToken(argv[i+2]);
		}
		return true;
	}
	
	return false;
}

int FileLoader::strToInt(string myString)
{
	istringstream buffer(myString);
	int value;
	buffer >> value;
	return value;
}

void FileLoader::processToken(string arg)
{
	
}

string FileLoader::getOutName()
{
	return inputFile + ".csv";
}

string FileLoader::getTAE3File()
{
	std::ifstream t(inputFile);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

void FileLoader::saveTAE3Data()
{
	getTAE3Data()->saveResults(inputFile + ".short");
}

void FileLoader::loadData()
{

	string tae3File = getTAE3File();

	try
	{
		if (tae3File.length() > 0)
		{
			/*
			рюакхжю пегскэрюрнб гнмдхпнбюмхъ рющ-3
			мювюкн мюакчдемхи : 01.03.2017 11:30
			йнмеж мюакчдемхи  : 01.03.2017 12:59
			бшянрю янкмжю : 7 цпюд.
			яхмнорхвеяйхи хмдейя ярюмжхх : 23933
			йнд накювмнярх : 00900
			опхгелмюъ ньхайю релоепюрспш : 0.3 цпюд.
			опхгелмюъ ньхайю бкюфмнярх   : 6.8 %
			H       P       T    U   D    V   TD
			*/
			unsigned int newl = 0;// tae3File.find('\n');

			while (newl < tae3File.length())
			{
				string last_str = tae3File.substr(newl, tae3File.find('\n', newl) - newl);
				rDa->addString(last_str);
				newl = tae3File.find('\n', newl) + 1;
			}

		}
	}
	catch (...)
	{

	}
}

TAE3* FileLoader::getTAE3Data()
{
	return rDa;
}