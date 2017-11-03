/***********************
 * Program: assignment2.cpp
 * Author: Claire Cahill
 * Date: 1/20/2017
 * Description: A user-interactive adventure through Oregon State
 * based on conditional statements and user choice. Users will 
 * either graduate or suddenly drop out, based on the paths they take
 * Input: user enters a number
 * Output: user is given a series 
 * of choices that takes them on their adventure
 * **********************/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

int main (){

   int n,x,a,b,c,d,z;
   srand(time(NULL));

   /*Introduction*/
   cout << "Welcome to your adventure through Oregon State to get to graduation!";
   cout << "Choose your team: Beavers(1) or Ducks(2)?" << endl;
   cin >> x;

   /*Beavers*/
   if( x==1 ){
      cout << "What's your major? Engineering(1) or Business(2)?" << endl;
      cin >> a;

      /*Engineering*/
      if( a==1 ){
	 cout << "Would you like to study(1) or party(2)?" << endl;
	 cin >> b;

	 /*Study*/
	 if( b==1 ){
	    cout << "What's your major? Computer science(1) or Pre-medical(2)?" << endl;
	    cin >> c;

	    /*Computer science*/
	    if( c==1 ){
	       cout << "Do you want to graduate(1) or drop out of school because you are drowning in debt(2)?" << endl;
	       cin >> d;

	       /*Graduate*/
	       if( d==1 ){
		  cout << "Congratulations! You have graduated and your adventure is complete." << endl;
	       }

	       /*debt*/
	       else if( d==2 ){
		  cout << "You lose." << endl;
	       }
	    }

	    /*Pre-med*/
	    else if( c==2 ){
	       cout << "Do you want to graduate(1) or move on to medical school(2)?" << endl;
	       cin >> d;

	       /*Graduate*/
	       if( d==1 ){
		  cout << "Congradulations! You have graduated and your adventure is complete." << endl;
	       }

	       /*Medical school*/
	       else if (d ==2 ){
		  cout << "You gathered too much debt and you were not able to graduate." << endl;
	       }
	    }
	 }

	 /*Party*/
	 else if ( b==2 ){
	    cout << "Do you take the test(1) or sleep in(2)?" << endl;
	    cin >> z;
	    z = (rand()%1+1);
	    if( z==1 || z==2 ){
	       cout << "By random chance, you have been given an opportunity to ";
	       cout << "pursue your dream of becoming a movie star. You drop out of school." << endl;
	    }
	 }
      }


      /*Business*/
      else if( a==2 ){
	 cout << "Would you like to enter the restaurant business(1) " <<
	 cout << "or the computer industry(2)?" << endl;
	 cin >> b;
	 /*Restaurant*/
	 if ( b==1 ){
	    cout << "Will you open a coffee shop(1) or an Italian restaurant(2)?" << endl;
	    cin >> c;

	    /*Coffee*/
	    if ( c==1 ){
	       cout << "Will you earn your degree(1) or drop out and work at Starbucks(2)?" << endl;
	       cin >> d;

	       /*Degree*/
	       if( d==1 ){
		  cout << "Congratulations! You have graduated and completed your adventure." << endl;
	       }

	       /*Starbucks*/
	       else if( d==2 ){
		  cout << "You lose." << endl;
	       }
	    }
	    /*Italian*/
	    else if( c==2 ){
	       cout << "Will you earn your degree(1) or drop out and start your own business(2)?" << endl;
	       cin >> d;
	       /*Degree*/
	       if ( d==1 ){
		  cout << "Congratulations! You have graduated and your adventure is complete." << endl;
	       }
	       /*Own business*/
	       else if ( d==2 ){
		  cout << "You did not graduate; You lose." << endl;
	       }
	    }
	 }

	 /*Computer Industry*/
	 else if( b==2 ){
	    cout << "You have to change your major to engineering in ";
	    cout << "order to enter the computer industry. Try again." << endl;
	 }
      }
   }
   /*Ducks*/
   else if( x==2 ){
      cout << "Wrong choice; You lose." << endl;
   }


   return 0;  
}
