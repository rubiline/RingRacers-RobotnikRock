// SONIC ROBO BLAST 2 KART
//-----------------------------------------------------------------------------
// Copyright (C) 2018-2020 by Kart Krew
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  k_race.h
/// \brief Race Mode specific code.

#ifndef __K_RACE__
#define __K_RACE__

#include "r_defs.h"

extern line_t *finishBeamLine;

#define FINISHLINEBEAM_SPACING (48*mapobjectscale)

/*--------------------------------------------------
	void K_ClearFinishBeamLine(void);

		Clears variables for finishBeamLine.
		Separate from K_FreeFinishBeamLine since this
		needs called when PU_LEVEL is freed.

	Input Arguments:-
		None

	Return:-
		None
--------------------------------------------------*/

void K_ClearFinishBeamLine(void);


/*--------------------------------------------------
	boolean K_GenerateFinishBeamLine(void);

		Finds pre-placed "beam points" to create a finish line out of,
		or tries to automatically create it from a finish linedef in the map.
		The result is stored in the "finishBeamLine" variable.

	Input Arguments:-
		None

	Return:-
		True if successful, otherwise false.
--------------------------------------------------*/

boolean K_GenerateFinishBeamLine(void);


/*--------------------------------------------------
	void K_RunFinishLineBeam(void);

		Updates the finish line beam effect.

	Input Arguments:-
		None

	Return:-
		None
--------------------------------------------------*/

void K_RunFinishLineBeam(void);

#endif