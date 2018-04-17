// TAEFormat.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "FileLoader.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FileLoader* fl = new FileLoader();
	fl->parseCommandLine(argc, argv);
	fl->loadData();
	fl->saveTAE3Data();
	return 0;
}

