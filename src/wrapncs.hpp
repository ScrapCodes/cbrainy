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


#include <ncurses.h>
#include <cstdlib>
#include <string>

using namespace std;
/** Class that wraps the necessary things to give terminal based GUI support for our AP*/
class wrapNcs{
	private:

		WINDOW *winEQ; /**< ncurses windows object for equations */
		WINDOW *winINFO; /**< ncurses windows object for informaiton box */
		int startx, starty, width, height; /**<  < position and dimensions for equation box. */
		int xInfo,yInfo,wInfo,hInfo; /** < position and dimensions for Info box. */
		int row,col;  /**< row and col for positioning the equaitons. */
		/** Function to create and initialize a new window */
		WINDOW *create_newwin(int height, int width, int starty, int startx);
		/** Create an invisible window , usefull for restricting spread of text */
		WINDOW *create_newwinInv(int height, int width, int starty, int startx);
	/** function to delete a  window and do the cleaning stuff */
	void destroy_win(WINDOW *local_win);
	public :
		string str; /** < will be used to store the user replies. Need an alternate approach to this. */
	/** Empty contructor to generate reference */
	wrapNcs(){
		winEQ=NULL;
		winINFO=NULL;
		height=0; //Find an alternate technique
	}
	wrapNcs(const char* introduce)
	{
		initscr();			/* Start curses mode 		*/
		cbreak();			/* Line buffering disabled, Pass on
						 * every thing to me 		*/
		getmaxyx(stdscr,row,col);              /* get the number of rows and columns */
		if(has_colors() == FALSE)
		{       endwin();
			printf("Your terminal does not support color\n");
			exit(1);
		}
		
		start_color();                  /* Start color                  */
		height = 10; /* to be adjusted*/
		width = 12; /* to be adjusted*/
		starty = (LINES - height) / 2;	/* Calculating for a center placement */
		startx = (COLS - width) / 2;	/* of the window		*/
		// Following are for position and dimension of info box
		wInfo=20;
		hInfo=5;
		xInfo= (COLS-wInfo)/2; /** < Let's place it in the centre */
		yInfo= 3;  /** < and 3 rows down the top */
		
		keypad(stdscr, TRUE);		/* enable keyboard shortcuts 	*/
		refresh();
		string temp;
		temp.assign(introduce);
		introduction(temp);
	}
	~wrapNcs()
	{
		if(height!=0){
		destroy_win(winINFO);
		destroy_win(winEQ);
		clear();
		refresh();
		bye();
		endwin();			/* End curses mode		  */
		}
	}

	/** Give an introduction to your program.*/
	void introduction(string text);
	/** Print equations in a nice manner */	
	void printEquations(string eqLeft,string eqRight,string operation);
	/**Reposition to Default position for curser to recieve user input*/
	void curserReposition();
	/** Print Info dialogue box */
	void printInfo(string information, int flag);
	/** Think how you want to say bye bye */
	void bye();
};

