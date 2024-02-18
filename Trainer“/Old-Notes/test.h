if(BootInfo != XamGetCurrentTitleId())
{
	SetAddr = false;
	Sleep(500);
	BootInfo = XamGetCurrentTitleId();
	if(BootInfo < 0x80000000 || BootInfo == 0xFFFE07D2)
	{
		for(info = 0; info < sizeof(Game_Init)/8; info++)
		{
			if(Game_Init[i].id == BootInfo)
			{
				(*Game_Init[i].init)();
				SetAddr = true;
				break;
			}
		}
	}
}