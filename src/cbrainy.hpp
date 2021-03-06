
/** 
* @brief Flash equations generated randomly !  
* This HPP file contains declarations of variables functions and classes only. 
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
@email  scrapcodes at gmail dot com
@version 1.0
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <sstream>
#include<ctime>
#include "wrapncs.hpp"

using namespace std;

/** No of correct answers !*/
static unsigned int correct;

/** No of wrong answers !*/
static unsigned int wrong;

/** record the start time */
time_t start;

/** record the end time */
time_t end;

/** Calculate accuracy !*/
double accuracy();

/** Enum ? because we chose for event model to trigger exit */
enum events{
running, /**< indicates state of the program as running*/
eXit, /**< indicates state of the program completed and ready for exit*/
paused, /**< To be implemented */
stopped /**< To be implemented */
};

/** Enum state stores the current state of the program*/
events state;


/** Class equations has functions to generate different types of equations(multiply,addition,subtraction or division and configurable difficulties 
 */
class equations{
	private:
		/** Some temporary variables to be used by the functions internally*/
		unsigned int i,j,k; 

		string add;
		string mul;
		string div;
		string sub;
	public:
		/** difficulty metric*/
		unsigned int difficulty;
		wrapNcs *wraped;
		/**Default contructor to initialize the defaults*/
		equations(const char *intro)
		{
	/*		wraped("Hiii ready for solving some crazy equations  ???...."); */

			wraped= new wrapNcs(intro);
			add=string("+");
			mul=string("*");
			//div=string("÷");
			div=string("/");
			sub=string("-");
			difficulty=1;
			state =running;
		}
		~equations()
		{
			delete wraped;
		}
		/** getter for the string str of wrapper*/	
		string getStr();
		/** function to generate the addition equations
			@return If the user answered correctly or not.
		*/
		bool addition();
		/** function to generate the subtraction equaitons 
			@return If the user answered correctly or not.
		*/
		bool subtraction();
		/** funciton to generate the division equaitons
			@return If the user answered correctly or not.
		*/
		bool division();
		/** function to generate the multiplication equations
			@return If the user answered correctly or not.
		*/
		bool multiplication(); 
};
/** handles the case of both normal and interrupted exits will soon be replaced by something nicer*/
void exitEvent(equations *);
