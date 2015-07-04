#ifndef LIERO_RUMBLE_HPP
#define LIERO_RUMBLE_HPP

#include <shake.h>

#define RUMBLE_DEVICES	2

typedef enum rumbleEffectType
{
	effectGetHurt = 0,
	effectExplosion,
	effectWeapon,
	effectCount
} rumbleEffectType;

extern Shake_Device *rumbleDevice[RUMBLE_DEVICES];
extern int rumbleEffectId[RUMBLE_DEVICES][effectCount];

extern Shake_Effect rumbleEffectGetHurt;
extern Shake_Effect rumbleEffectExplosion;
extern Shake_Effect rumbleEffectWeapon;

void initRumble();
void closeRumble();

#endif // LIERO_RUMBLE_HPP
