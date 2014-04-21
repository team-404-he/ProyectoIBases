#ifndef QANALIZR_H
#define QANALIZR_H

class queryAnalizer
{
	static queryAnalizer* ms_instance;

public:
	static queryAnalizer* Instance();
	static void Release();

private:
	queryAnalizer();
	~queryAnalizer();

};

#endif // QANALIZR_H
