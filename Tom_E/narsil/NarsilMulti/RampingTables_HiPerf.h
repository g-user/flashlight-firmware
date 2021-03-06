/****************************************************************************************
 * RampingTables.h
 * ===============
 *
 ****************************************************************************************/

#ifndef RAMPINGTABLES_H_
#define RAMPINGTABLES_H_



//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#if   OUT_CHANNELS == 2			// FET+1 or Buck driver
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
		//---------------------------------------------------------------------
		//  High Performance FET+1 2 channel modes
		//---------------------------------------------------------------------
		#define RAMP_SIZE  150		// (~130 for lower max ramping)

		#define TIMED_STEPDOWN_MIN 110	// min level in ramping the timed stepdown will engage,
		//    level 110 = 102 PWM, this is ~40%
		#define TIMED_STEPDOWN_SET 94		// the level timed stepdown will set,
		//    level 94 = 64 PWM, this is ~25%

#ifdef LUMENS12K_MAX	
		// For FET+1: FET and one 350 mA 7135 for hi performance (12K lumens max):
		//    level_calc.py 2 150 7135 5 2 320 FET 1 10 12000
		#define FET_START_LVL 40
		
		PROGMEM const byte ramp_7135[] = {
			5,6,6,7,8,10,11,13,					15,17,19,22,25,28,31,35,
			40,44,49,54,60,66,73,80,			87,95,104,113,122,132,143,154,
			165,178,190,204,218,233,248,255,	255,255,255,255,255,255,255,255,		// 33-48
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,		// 49-64
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,0
		};

		PROGMEM const byte ramp_FET[]  = {
			0,0,0,0,0,0,0,0,						0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,						0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,1,						2,2,2,3,4,4,5,5,
			6,7,7,8,9,9,10,11,					12,13,14,14,15,16,17,18,				// 49-64
			19,20,22,23,24,25,26,28,			29,30,31,33,34,36,37,39,
			40,42,43,45,47,49,50,52,			54,56,58,60,62,64,66,68,				// 81-96
			70,72,75,77,79,82,84,87,			89,92,94,97,100,102,105,108,			// 97-112
			111,114,117,120,123,126,129,132,	136,139,142,146,149,153,157,160,		// 113-128
			164,168,172,175,179,183,187,191,	196,200,204,208,213,217,222,226,
			231,236,240,245,250,255		
		};

#else
		// For FET+1: FET and one 350 mA 7135 for hi performance (7K lumens max):
		//    level_calc.py 2 150 7135 5 2 320 FET 1 10 7000
		#define FET_START_LVL 48
		
		PROGMEM const byte ramp_7135[] = {
			5,5,6,7,8,8,10,11,					12,13,15,17,19,21,23,26,
			29,32,35,38,42,46,50,54,			59,64,69,75,81,87,94,100,
			108,115,123,131,140,149,158,168,	178,189,200,211,223,235,248,255,		// 33-48
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,		// 49-64
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,255,255,255,	255,255,255,255,255,255,255,255,
			255,255,255,255,255,0			
		};

		PROGMEM const byte ramp_FET[]  = {
			0,0,0,0,0,0,0,0,						0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,						0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,						0,0,0,0,0,0,0,1,
			2,2,3,4,4,5,6,7,						8,9,10,10,11,12,13,15,					// 49-64
			16,17,18,19,20,21,23,24,			25,27,28,29,31,32,34,36,
			37,39,40,42,44,46,47,49,			51,53,55,57,59,61,63,66,				// 81-96
			68,70,72,75,77,80,82,84,			87,90,92,95,98,101,103,106,			// 97-112
			109,112,115,118,121,125,128,131,	134,138,141,145,148,152,156,159,		// 113-128
			163,167,171,175,179,183,187,191,	195,199,204,208,212,217,221,226,
			231,235,240,245,250,255			
		};
#endif
		
//---------------------------------------------------------------------------------------
#elif OUT_CHANNELS == 3		// Triple Channel
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#elif OUT_CHANNELS == 1		// single FET or single bank of 7135's
//---------------------------------------------------------------------------------------
#endif

#endif /* RAMPINGTABLES_H_ */