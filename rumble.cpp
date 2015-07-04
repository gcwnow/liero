#include "rumble.hpp"

Shake_Device *rumbleDevice[RUMBLE_DEVICES];
int rumbleEffectId[RUMBLE_DEVICES][effectCount];
Shake_Effect rumbleEffectGetHurt;
Shake_Effect rumbleEffectExplosion;
Shake_Effect rumbleEffectWeapon;
int numOfDevices;

void initRumble()
{
	Shake_Init();
	numOfDevices = Shake_NumOfDevices();

	if (!numOfDevices)
	{
		return;
	}

	for (int i = 0; i < RUMBLE_DEVICES; ++i)
	{
		if (i >= numOfDevices)
		{
			break;
		}

		rumbleDevice[i] = Shake_Open(i);
		Shake_SetGain(rumbleDevice[i], 15);
	}

	// Init effects
	Shake_SimplePeriodic(&rumbleEffectGetHurt, SHAKE_PERIODIC_SINE, 1.0, 0.0, 0.5, 0.0); 
	Shake_SimplePeriodic(&rumbleEffectExplosion, SHAKE_PERIODIC_SINE, 0.0, 0.0, 0.0, 0.0);
	Shake_SimplePeriodic(&rumbleEffectWeapon, SHAKE_PERIODIC_SINE, 0.6, 0.0, 0.1, 0.1);

	for (int i = 0; i < RUMBLE_DEVICES; ++i)
	{
		rumbleEffectId[i][effectGetHurt] = Shake_UploadEffect(rumbleDevice[i], &rumbleEffectGetHurt);
		rumbleEffectId[i][effectExplosion] = Shake_UploadEffect(rumbleDevice[i], &rumbleEffectExplosion);
		rumbleEffectId[i][effectWeapon] = Shake_UploadEffect(rumbleDevice[i], &rumbleEffectWeapon);
	}
}

void closeRumble()
{
	for (int i = 0; i < RUMBLE_DEVICES; ++i)
	{
		if (i >= numOfDevices)
		{
			break;
		}

		Shake_Close(rumbleDevice[i]);
	}
	Shake_Quit();
}
