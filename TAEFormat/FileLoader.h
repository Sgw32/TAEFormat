#include "stdafx.h"
#include "TAE3.h"

#ifndef FILELOADER_H
#define FILELOADER_H

class FileLoader
{
public:
	FileLoader();
	~FileLoader();
	bool parseCommandLine(int argc, char *argv[]);
	string getOutName();
	void loadData();
	TAE3* getTAE3Data();
	void saveTAE3Data();
	string getTAE3File();
	int getColumn()
	{
		return column;
	}
	int getStep()
	{
		return step;
	}
	int getTimeStep()
	{
		return tstep;
	}
private:
	void processToken(string data);
	int strToInt(string myString);
	int column;
	int step;
	int tstep;
	TAE3* rDa;
	string inputFile;
};

#endif