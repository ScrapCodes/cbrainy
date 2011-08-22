/**  This is wrapper containing calls to ncurses library. Thus we have
* Ncurses interface for our Aptitude Prepare. 
*
* This file is distributed under GPLv2 http://www.gnu.org/licenses/gpl-2.0.html
* Copyright (C) 2011  Prashant Sharma
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation. 

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
* Also add information on how to contact you by electronic and paper mail.

@author Prashant Sharma
@email prashant dot iiith at gmail dot com
@version 1.0
*/



#include "wrapncs.hpp"
/* only for testing*/
/*
   int main(int argc, char *argv[])
   {
   wrapNcs wp;
   wp.printEquations("45","65","*");
   wp.printInfo("Hello World",1);
   getch();
   return 0;
   }
 */
void wrapNcs::bye(){
 /*This method will replace exitEvent function*/
}
/** A method to give a brief introduction and do some initialization*/
void wrapNcs::introduction(){

}
void wrapNcs::curserReposition()
{
	move(((starty-2)+(height/2))+3,startx+width/2);
}
void  wrapNcs::printEquations(string eqLeft,string eqRight,string operation)
{
	winEQ = create_newwin(height, width+3, starty, startx);
	mvprintw((starty-2)+height/2,startx+width/2,"%s",eqLeft.c_str());
	mvprintw((starty-2)+(height/2) +1,startx+width/2,"%s",eqRight.c_str());
	mvprintw((starty-2)+height/2 +1,((startx)+width/2) -1,"%s",operation.c_str());
	mvprintw(((starty-2)+(height/2))+2,((startx)+width/2) ,"%s","______");
	curserReposition();
	char temp[80];
	getstr(temp);
	str.assign(temp);
}

void wrapNcs::printInfo(string information, int flag)
{

	winINFO = create_newwin(hInfo,wInfo,yInfo,xInfo);

	if(flag==1) //lets use green color for indicating success.
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
	else // lets use red color for indicating error.
		init_pair(1, COLOR_RED, COLOR_BLACK);

	/* Some decoration console can afford*/	
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	mvprintw(yInfo+1,xInfo+1,"%s",information.c_str());
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
}

WINDOW *wrapNcs::create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/
	return local_win;
}

void wrapNcs::destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
