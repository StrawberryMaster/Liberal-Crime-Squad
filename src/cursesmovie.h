//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//Copyright (c) 2002,2003,2004 by Tarn Adams											//
//																						//
//////////////////////////////////////////////////////////////////////////////////////////
//This file is part of Liberal Crime Squad.												//
//																						//
//    Liberal Crime Squad is free software; you can redistribute it and/or modify		//
//    it under the terms of the GNU General Public License as published by				//
//    the Free Software Foundation; either version 2 of the License, or					//
//    (at your option) any later version.												//
//																						//
//    Liberal Crime Squad is distributed in the hope that it will be useful,			//
//    but WITHOUT ANY WARRANTY; without even the implied warranty of					//
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						//
//    GNU General Public License for more details.										//
//																						//
//    You should have received a copy of the GNU General Public License					//
//    along with Liberal Crime Squad; if not, write to the Free Software				//
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA			//
//////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#define PICMAX 1000
struct filelistst
{
   vector<char *> list;
   ~filelistst() { delete_and_clear(list); }
   void clean() { delete_and_clear(list); }
   void open_diskload(FILE *h);
   void open_disksave(FILE *h);
   void smartappend(filelistst &list2);
};
#define CM_FRAMEFLAG_OVERLAY BIT1
struct CursesMovie_framest
{
   short frame;
   long start,stop;
   short sound,song,effect;
   unsigned short flag;
   CursesMovie_framest() : frame(0),start(0),stop(0),sound(-1),song(-1),effect(-1),flag(0) { }
};
struct CursesMoviest
{
   unsigned char picture[PICMAX][80][25][4];
   int picnum,dimx,dimy;
   filelistst songlist,soundlist;
   vector<CursesMovie_framest *> frame;
   CursesMoviest() : picnum(1),dimx(80),dimy(25) { }
   ~CursesMoviest() { clean(); }
   void savemovie(const char *filename, int flags);
   void loadmovie(const char *filename);
   void clean() { delete_and_clear(frame); }
   void convertindices_song(filelistst &master);
   void convertindices_sound(filelistst &master);
   void playmovie(int x,int y);
};
