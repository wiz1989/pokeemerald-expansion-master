#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

void PlayTimeCounter_Reset(void);
void PlayTimeCounter_Start(void);
void PlayTimeCounter_Stop(void);
void PlayTimeCounter_Update(void);
void PlayTimeCounter_SetToMax(void);
void PlayTimeCounter_AddMin(s8 minutes);

#endif // GUARD_PLAY_TIME_H
