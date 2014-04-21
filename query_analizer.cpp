#include "query_analizer.h"

queryAnalizer* queryAnalizer::ms_instance = 0;

queryAnalizer::queryAnalizer()
{
}

queryAnalizer::~queryAnalizer()
{
}

queryAnalizer* queryAnalizer::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new queryAnalizer();
	}
	return ms_instance;
}

void queryAnalizer::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

