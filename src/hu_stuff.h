// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1993-1996 by id Software, Inc.
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2020 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  hu_stuff.h
/// \brief Heads up display

#ifndef __HU_STUFF_H__
#define __HU_STUFF_H__

#include "d_event.h"
#include "w_wad.h"
#include "r_defs.h"
#include "font.h"

//------------------------------------
//           heads up font
//------------------------------------
#define HU_FONTSTART '\x16' // the first font character
#define HU_FONTEND '~'

#define HU_FONTSIZE (HU_FONTEND - HU_FONTSTART + 1)

// SRB2kart
#define KART_FONTSTART '\"' // the first font character
#define KART_FONTEND 'Z'

#define KART_FONTSIZE (KART_FONTEND - KART_FONTSTART + 1)

#define AZ_FONTSTART 'A' // the first font character
#define AZ_FONTEND 'Z'

#define AZ_FONTSIZE (AZ_FONTEND - AZ_FONTSTART + 1)
//

// Level title font
#define LT_FONTSTART '!' // the first font characters
#define LT_FONTEND 'z' // the last font characters
#define LT_FONTSIZE (LT_FONTEND - LT_FONTSTART + 1)

// Under regular circumstances, we'd use the built in font stuff, however this font is a bit messy because of how we're gonna draw shit.
// tc_font[0][n] is used for the "bottom" layer
// tc_font[1][n] is used for the "top" layer
extern patch_t *tc_font[2][LT_FONTSIZE];

#define CRED_FONTSTART '!' // the first font character
#define CRED_FONTEND 'Z' // the last font character
#define CRED_FONTSIZE (CRED_FONTEND - CRED_FONTSTART + 1)

#define X( name ) name ## _FONT
/* fonts */
enum
{
	X        (HU),
	X      (TINY),

	X        (LT),
	X      (CRED),

	X   (TALLNUM),
	X (NIGHTSNUM),
	X   (PINGNUM),

	X      (KART),
	X        (GM),
	X      (FILE),
	X      (LSHI),
	X     (LSLOW),
};
#undef  X

extern char *shiftxform; // english translation shift table
extern char english_shiftxform[];

//------------------------------------
//        sorted player lines
//------------------------------------

typedef struct
{
	UINT32 count;
	INT32 num;
	const char *name;
} playersort_t;

//------------------------------------
//           chat stuff
//------------------------------------
#define HU_MAXMSGLEN 224
#define CHAT_BUFSIZE 64 // that's enough messages, right? We'll delete the older ones when that gets out of hand.
#define NETSPLITSCREEN // why the hell WOULDN'T we want this?
#ifdef NETSPLITSCREEN
#define OLDCHAT (cv_consolechat.value == 1 || dedicated || vid.width < 640)
#else
#define OLDCHAT (cv_consolechat.value == 1 || dedicated || vid.width < 640)
#endif
#define CHAT_MUTE (cv_mute.value && !(server || IsPlayerAdmin(consoleplayer))) // this still allows to open the chat but not to type. That's used for scrolling and whatnot.
#define OLD_MUTE (OLDCHAT && cv_mute.value && !(server || IsPlayerAdmin(consoleplayer))) // this is used to prevent oldchat from opening when muted.

// some functions
void HU_AddChatText(const char *text, boolean playsound);

// set true when entering a chat message
extern boolean chat_on;

// keystrokes in the console or chat window
extern boolean hu_keystrokes;

extern patch_t *pinggfx[5];
extern patch_t *framecounter;
extern patch_t *frameslash;

extern patch_t *rflagico;
extern patch_t *bflagico;
extern patch_t *rmatcico;
extern patch_t *bmatcico;
extern patch_t *tagico;
extern patch_t *tallminus;
extern patch_t *tallinfin;

// set true whenever the tab rankings are being shown for any reason
extern boolean hu_showscores;

// init heads up data at game startup.
void HU_Init(void);

void HU_LoadGraphics(void);

// Load a HUDGFX patch or NULL.
patch_t *HU_CachePatch(const char *format, ...);

// reset heads up when consoleplayer respawns.
void HU_Start(void);

boolean HU_Responder(event_t *ev);
void HU_Ticker(void);
void HU_DrawSongCredits(void);
void HU_Drawer(void);
char HU_dequeueChatChar(void);
void HU_Erase(void);
void HU_clearChatChars(void);
void HU_drawPing(INT32 x, INT32 y, UINT32 ping, INT32 flags); // Lat': Ping drawer for scoreboard.
void HU_drawMiniPing(INT32 x, INT32 y, UINT32 ping, INT32 flags);

INT32 HU_CreateTeamScoresTbl(playersort_t *tab, UINT32 dmtotals[]);

// CECHO interface.
void HU_ClearCEcho(void);
void HU_SetCEchoDuration(INT32 seconds);
void HU_SetCEchoFlags(INT32 flags);
void HU_DoCEcho(const char *msg);

// Demo playback info
extern UINT32 hu_demotime;
extern UINT32 hu_demolap;
#endif
