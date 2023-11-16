#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

void PlayTimeCounter_Reset(void);
void PlayTimeCounter_Start(void);
void PlayTimeCounter_Stop(void);
void PlayTimeCounter_Update(void);
void PlayTimeCounter_SetToMax(void);
void PlayTimeCounter_AddMin(s8 minutes);
void PlayTimeCounter_AddHrs(s8 hours);
void PlayTimeCounter_SubMin(s8 minutes);
void PlayTimeCounter_SubHrs(s8 hours);

#endif // GUARD_PLAY_TIME_H
