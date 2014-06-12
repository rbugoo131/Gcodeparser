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

//Define modal group numbers for checking multiple command violations 
// A modal group is a group of g-c    ode commands that are
// mutually exclusive, or cannot exist on the same line, because they each togg    le a state or execute
// a unique motion. These are defined in the NIST RS274-NGC v3 g-code standard,     available online, 
// and are similar/identical to other g-code interpreters by manufacturers (Haa    s,Fanuc,Mazak,etc).

#define MODAL_GROUP_NONE 0
#define MODAL_GROUP_0 1 // [G4,G10,G27,G28,G30,G53,G70,G71,G72,G73,G74,G75,G76,G92,G92.1] Non-modal
#define MODAL_GROUP_1 2 // [G0,G1,G2,G3,G32,G80,G90,G92,G94] Motion
#define MODAL_GROUP_2 3 // [G17,G18,G19,G96,G97] Plane selection
#define MODAL_GROUP_3 4 // [G90,G91] Distance mode
#define MODAL_GROUP_4 5 // [M0,M1,M2,M30] Stopping
#define MODAL_GROUP_5 6 // [G93,G94,G98,G99] Feed rate mode
#define MODAL_GROUP_6 7 // [G20,G21] Units
#define MODAL_GROUP_7 8 // [G40,G41,G42,M3,M4,M5] Spindle turning
#define MODAL_GROUP_12 9 // [G54,G55,G56,G57,G58,G59] Coordinate system selecti    on





int parse_word(char *letter,float *ptr_float,char *line ,int *line_cnt);
int gc_execute_line(char *line);











#endif
