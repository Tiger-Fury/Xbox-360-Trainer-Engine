/*

//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Applying All TU Patch");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	DWORD addr;
	DWORD buf[] = {0xFCC74AEE, 0xD0DB0014};
	DWORD money_buf[] = {0x5549003E, 0x915A000C};
	DWORD exp_buf[] = {0xEDA0082A, 0x7DABED2E};
	DWORD renown_buf[] = {0x7D7DE214, 0x556A003E};
	///Search range
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1) - 0x08;
	PatchJump(addr, (DWORD)CodeCave);
	Money_addr = GetAddr(0x82000000, 0x83000000, money_buf, 2, 1) + 0x04;
	Exp_addr = GetAddr(0x82000000, 0x83000000, exp_buf, 2, 1);
	Renown_addr = GetAddr(0x82000000, 0x83000000, renown_buf, 2, 1);
	SetAddr = true;
}
//bool SetAddr = false;
/*if( SetAddr == false )
{
	SearchAddr();
}*/