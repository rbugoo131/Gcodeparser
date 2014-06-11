#ifndef INPUT_H
#define INPUT_H

#include<stdio.h>
#include<string.h>

//define status
#define STATUS_OK 0
#define STATUS_BAD_NUMBER_FORMAT 1
#define STATUS_UNEXPECTED_COMMAND_LETTER 2
#define STATUS_UNSUPPORTED_STATEMENT 3
#define STATUS_ARC_RADIUS_ERROR 4
#define STATUS_MODAL_GROUP_VIOLATION 5
#define STATUS_INVALID_STATEMENT 6
#define STATUS_SETTING_DISABLED 7
#define STATUS_SETTING_VALUE_NEG 8
#define STATUS_SETTING_STEP_PULSE_MIN 9
#define STATUS_SETTING_READ_FAIL 10
#define STATUS_IDLE_ERROR 11
#define STATUS_ALARM_LOCK 12
#define STATUS_OVERFLOW 13

int parse_word(char *letter,float *ptr_float,char *line ,int *line_cnt);












#endif
