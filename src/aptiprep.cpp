/** 
* Flash equations generated randomly and expect reply 
* CPP file contains implementation 
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

#include "aptiprep.hpp"
		/** function to generate the addition equations
			@return If the user answered correctly or not.
		*/
bool equations::addition(){

	cout<<"Eq:"<<(i=rand()%(difficulty*10)+1)<<"+"<<(j=rand()%(difficulty*10)+1)<<endl;
	cin>>k;
	if(i+j==k) 
	{	
		correct++;
		return true;
	}
	else if(k==9999) { state=eXit; exitEvent();}
	return false;
}

		/** function to generate the subtraction equaitons 
			@return If the user answered correctly or not.
		*/
bool equations::subtraction(){
	/** ensuring subtraction to be of positive result */
	i=rand()%(difficulty*10)+1;
	j=rand()%(difficulty*10)+1;
	int x,y;
	cout<<"Eq:"<<(x= (i>j) ? i:j) << "-" <<( y=(i>j) ? j:i )<<endl;
	cin>>k;
	if(x-y==k)
	{
		correct++;
		return true;
	}
	else if(k==9999) { state=eXit; exitEvent();}
	return false;
}
		/** function to generate the multiplication equations
			@return If the user answered correctly or not.
		*/
bool equations::multiplication(){
	cout<<"Eq:"<<(i=rand()%(difficulty*10)+1)<<"*"<<(j=rand()%(difficulty*10)+1)<<endl;
	cin>>k;
	if(i*j==k) 
	{
		correct++;
		return true;
	}
	else if(k==9999) { state=eXit; exitEvent();}
	return false;
}
		/** funciton to generate the division equaitons
			@return If the user answered correctly or not.
		*/
bool equations::division(){
	/** Ensuring division by factors only */
	i=rand()%(difficulty*10)+1;
	j=rand()%(difficulty*10)+1;
	cout<<"Eq:"<<i*j<<"/"<<j<<endl;
	cin>>k;
	if(k==i) 
	{
		correct++;
		return true;
	}
	else if(k==9999) { state=eXit; exitEvent();}
	return false;
}

/** Calculate accuracy !*/
double accuracy()
{
	return (correct/(correct+wrong))*100;	
}

void exitEvent(){

	time(&end);
	double diff= difftime(end,start);
	cout<<" Dude you took :"<<diff<<" seconds To solve "<<correct+wrong<<" equations."<<endl;
	double a=accuracy();
	if(a>90 && ((correct+wrong)*100)/diff >5){
		cout<<"\nyou are genius !! your accuracy was :"<<a<<"%"<<" and speed was more than 15 eqs per min"<<endl;
	} 
	else cout<<"\nYour accuracy :"<<a<<"%"<<endl;
	exit(0);
}

int main()
{
	int N=0;
	correct=0;
	wrong=0;

	cout<<"Enter no of equations you would like to solve ! You can quit in the middle by entering 9999"<<endl;
	cin>>N;

	equations set;	
	// set up the random sead and also the starting time for measuing time taken.
	srand(time(&start));
	// Randomly pick the type of question for the user.
	while(N){
		switch((rand()%4+1)){
			case 1: if(!set.addition())	{cout<<"\nWrong!!!\n";wrong++;}
					break;
			case 2: if(!set.multiplication())	{cout<<"\nWrong!!!\n";wrong++;}
					break;
			case 3: if(!set.division())	{cout<<"\nWrong!!!\n";wrong++;}
					break;
			case 4: if(!set.subtraction()) {cout<<"\nWrong!!!\n";wrong++;}
					break;
			default: //not possible
				break;
		}
		N--;
	}

	state=eXit;	
	exitEvent();
	return 0;
}
