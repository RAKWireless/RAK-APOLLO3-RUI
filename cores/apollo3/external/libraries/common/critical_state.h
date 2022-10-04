#ifndef CRITICAL_STATE_H_
#define CRITICAL_STATE_H_

#ifdef __cplusplus
extern "C" {
#endif

void critical_state_enter(void);
void critical_state_exit (void);

#ifdef __cplusplus
}
#endif

#endif /* CRITICAL_STATE_H_ */
