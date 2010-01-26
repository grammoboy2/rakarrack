/*
  Rakarrack Audio FX
 
  Dual_Flange.h - Super Flanger
  Copyright (C) 2010 Ryan Billing
  Author: Ryan Billing

  Higher intensity flanging accomplished by picking two points out of the delay line to create a wider notch filter.
    
  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef DUAL_FLANGE_H
#define DUAL_FLANGE_H

#include "global.h"

#define  FMAX_DELAY 0.05f	// Number of Seconds  - 50ms corresponds to fdepth = 20 (Hz)
class Dflange
{
public:
  Dflange (REALTYPE * efxoutl_, REALTYPE * efxoutr_);
  ~Dflange ();
  void out (REALTYPE * smpsl, REALTYPE * smpr);
  void setpreset (int npreset);
  void changepar (int npar, int value);
  int getpar (int npar);
  void cleanup ();

  int Ppreset;

  REALTYPE *efxoutl;
  REALTYPE *efxoutr;


private:
  //Parameters
  int Pwetdry;		//Wet/Dry mix.  Range -100 to 100 (percent)
  int Ppanning;		//Panning.  Range -100 to 100 (percent)
  int Plrcross;		// L/R Mixing.  Range 0 to 100 (percent)
  int Pdepth;		//Max delay deviation expressed as frequency of lowest frequency notch.  Min = 20, Max = 15000
  int Pwidth;		//LFO amplitude.  Range 0 to 100 (percent)
  int Poffset;		// Offset of notch 1 to notch 2.  Range 0 to 100 (percent)
  int Pfb;		//Feedback parameter.  Range 0 to 100 (percent)
  int Phidamp;		//Lowpass filter delay line.  Range 20 to 20000 (Hz)
  int Psubtract;		//Subtract wet/dry instead of add.  Nonzero is true
  int Pzero;		//Enable through-zero flanging

  REALTYPE fwetdry;		//Wet/Dry mix.  Range -100 to 100 (percent)
  REALTYPE fpanning;		//Panning.  Range -100 to 100 (percent)
  REALTYPE flrcross;		// L/R Mixing.  Range 0 to 100 (percent)
  REALTYPE fdepth;		//Max delay deviation expressed as frequency of lowest frequency notch.  Min = 20, Max = 15000
  REALTYPE fwidth;		//LFO amplitude.  Range 0 to 100 (percent)
  REALTYPE foffset;		// Offset of notch 1 to notch 2.  Range 0 to 100 (percent)
  REALTYPE ffb;			//Feedback parameter.  Range 0 to 100 (percent)
  REALTYPE fhidamp;		//Lowpass filter delay line.  Range 20 to 20000 (Hz)
  REALTYPE fsubtract;		//Subtract wet/dry instead of add.  Nonzero is true
  REALTYPE fzero;		//Enable through-zero flanging

  //Internally used variables

  REALTYPE *ldelay, *rdelay;
  REALTYPE oldl, oldr;		//pt. lpf

};


#endif