#ifndef TK_CALIBRATION_H
#define TK_CALIBRATION_H
/*
 * Attiny calibration header.
 * This allows using a single set of hardcoded values across multiple projects.
 *
 * Copyright (C) 2015 Selene Scriven
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/********************** Voltage ADC calibration **************************/
// 5 values are form Dale's wight+1 driver measurements, commented out are values measured using RMM's FET+7135
// See battcheck/readings.txt for reference values.
// the ADC values we expect for specific voltages

#define ADC_44     184	// 205
#define ADC_43     180	// 201
#define ADC_42     175	// 196  100%
#define ADC_41     171	// 191
#define ADC_40     167	// 187   75%
#define ADC_39     163	// 182
#define ADC_38     159	// 177   50%
#define ADC_37     154	// 172
#define ADC_36     150	// 168
#define ADC_35     146	// 163   25%
#define ADC_34     141	// 158
#define ADC_33     136	// 153
#define ADC_32     132	// 149
#define ADC_31     128	// 144
#define ADC_30     124	// 139   0%
#define ADC_29     120	// 134
#define ADC_28     117	// 130  ---
#define ADC_27     112	// 125  ---
#define ADC_26     108	// 120
#define ADC_25     104	// 116
#define ADC_24     100	// 111
#define ADC_23      96	// 106
#define ADC_22      92	// 101
#define ADC_21      88	// 97
#define ADC_20      84	// 92

//#define ADC_100p   ADC_42  // the ADC value for 100% full (resting)
//#define ADC_75p    ADC_40  // the ADC value for 75% full (resting)
//#define ADC_50p    ADC_38  // the ADC value for 50% full (resting)
//#define ADC_25p    ADC_35  // the ADC value for 25% full (resting)
//#define ADC_0p     ADC_30  // the ADC value for 0% full (resting)
//#define ADC_LOW    ADC_28  // When do we start ramping down
//#define ADC_CRIT   ADC_27  // When do we shut the light off


/********************** Offtime capacitor calibration ********************/
// Values are between 1 and 255, and can be measured with offtime-cap.c
// See battcheck/otc-readings.txt for reference values.
// These #defines are the edge boundaries, not the center of the target.
#ifdef OFFTIM3
// The OTC value 0.5s after being disconnected from power
// (anything higher than this is a "short press")
#define CAP_SHORT           190
// The OTC value 1.5s after being disconnected from power
// Between CAP_MED and CAP_SHORT is a "medium press"
#define CAP_MED             94
// Below CAP_MED is a long press
#else
// The OTC value 1.0s after being disconnected from power
// Anything higher than this is a short press, lower is a long press
#define CAP_SHORT           115
#endif


#endif  // TK_CALIBRATION_H
