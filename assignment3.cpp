/*Program: assignment3.cpp
 * Name: Claire Cahill
 * Date: 01/30/2017
 * Description: Grade calculator for CS161
 * Input: user inputs the certain amount and their scores
 * and point values for each
 * Output: Program calculates final grades for each category*/

#include <iostream>
#include <string>

using namespace std;

float lab(int);
float assign(int);
float recitation(int);
float enter_points_vary(int, string);
float enter_points_novary(int, string, string);
float average(float, int);
float quiz(int);
float design(int);
float critique(int);
float tests(int);
float the_class();

int main(){

	int a=1, num_labs=0, num_assign=0, num_quiz=0, num_test=0; 
	while(a>0){
   	cout << "Would you like to calculate an average for 1-labs, ";
	cout << "2-assignments, 3-recitations, 4-tests, 5-the class, or 0-quit?" << endl;
	cin >> a;
	
	switch(a){
	   case 1:
	   	lab(num_labs); break;
	   case 2:   
		assign(num_assign); break;
	   case 3:
		recitation(num_quiz); break;
	   case 4:
		tests(num_test); break;
	   case 5:
		the_class(); break;
	   default:;
	}
	return 0;	
	}	
}

float enter_points_vary(int z, string s){ 
//asks the user the score on each, followed by asking how many points it's out of
	
   	float score=0, total_score=0;
	int points=0, total_points=0;
	for(int i=1; i<=z;i++){
	cout << s << i << " score: " << endl;
	cin >> score;
	cout << "How many points is that out of: " << endl;
	cin >> points;
	total_score += score;
	total_points += points;
	}
	return average(total_score, total_points);
}

float enter_points_novary(int z, string r, string s){
//asks the user how many points all are out of, then asks the score on each

  	float score=0, total_score=0;
	int points=0, total_points=0;
   	cout << "How many points is each  " << r << " worth?: " << endl;
   	cin >> points;
	total_points = points*z;
	cout << "What is your score on each?" << endl;
   	for(int i=1; i<=z; i++){
   	cout << s << i << " score: " << endl;
	cin >> score;
   	total_score += score;
   	}	
   	return average(total_score, total_points);

}

float average(float a, int b){
//calculates average, returns that value into above functions in order to calculate based on scores

	float ave = 0;
	ave = (a/b)*100;
	return ave;
}

float lab(int num_labs){ 
//asks how many labs, then calls points function in order to calculate average, then prints average

   int x=0;
   float score=0, points=0, ave=0, lab_ave;

	cout << "How many labs?" << endl;
	cin >> num_labs;
	cout << "Do the values vary? 1-yes or 0-no" << endl;
	cin >> x;
	if (x==1){
	   	int z = num_labs;
		ave = enter_points_vary(num_labs, "Lab ");
	}
	else if (x==0){
	   	int z = num_labs;
		ave = enter_points_novary(num_labs, "lab ", "Lab ");
	}
		cout << "Your lab average is " << ave << endl;
		lab_ave = ave;
	return lab_ave;
}


float assign(int num_assign){
//asks for the number of assignments, sends into points function, prints out average for assignments

   	int x=0;
	float score=0, points=0, ave=0, assign_ave;
	cout << "How many assignments?" << endl;
	cin >> num_assign; 
	cout << "Do the values vary? 1-yes or 0-no" << endl;
	cin >> x;
	if(x==1){
	   	int z=num_assign;
		ave=enter_points_vary(num_assign, "Assignment ");
	}
	else if(x==0){
	   	int z=num_assign;
		ave=enter_points_novary(num_assign, "assignment ", "Assignment ");
	}
	cout << "Your assignment average is " << ave << endl;
	assign_ave=ave;
	
	return assign_ave;
}

float recitation(int num_quiz){
//asks for the weight of each category
//if the weight is >0, then it sends it to sepatate functions to calc average, then prints average

	float wdesign = 0, wquiz = 0, wcritique = 0;
	float quiz_ave = 0, design_ave = 0, critique_ave = 0, rec_ave = 0;
	int x = 0, num_design = 0, num_critique=0;
	cout << "Enter quiz weight: " << endl;
	cin >> wquiz;
	cout << "Enter design weight: " << endl;
	cin >> wdesign;
	cout << "Enter critique weight: " << endl;
	cin >> wcritique;

	if(wquiz>0){
		quiz_ave = quiz(num_quiz);
		cout << "Your quiz average is " << quiz_ave << endl;
	}
	if(wdesign>0){
		design_ave = design(num_design);
		cout << "Your design average is " << design_ave << endl;
	}
	if(wcritique>0){
		critique_ave = critique(num_critique);
		cout << "Your critique average is " << critique_ave << endl;
	}

	rec_ave = (quiz_ave * (wquiz/100)) + (design_ave * (wdesign/100)) + (critique_ave * (wcritique/100));
	cout << "Your recitation average is " << rec_ave << endl;
	return rec_ave;
}

float quiz(int num_quiz){
//asks for the amount of quizzes, calculates average, send average back to recitation function

   int x = 0;
   float quiz_ave = 0;
	cout << "How many quizzes?" << endl;
     	cin >> num_quiz;
	cout << "Do the values vary? 1-yes or 0-no" << endl;	
	cin >> x;
	if(x==1){
	   	int z = num_quiz;
		quiz_ave = enter_points_vary(num_quiz, "Quiz ");
	}
	else if(x==0){
		int z = num_quiz;
		quiz_ave = enter_points_novary(num_quiz, "quiz ", "Quiz ");
	}
	return quiz_ave;
}

float design(int num_design){
//asks for the amount of designs, calculates average, sends back to recitation function

   int x = 0;
   float design_ave = 0;
   	cout << "How many designs?" << endl;
	cin >> num_design;
	cout << "Do the values vary? 1-yes or 0-no" << endl;
	cin >> x;
	if(x==1){
		int z = num_design;
		design_ave = enter_points_vary(num_design, "Design ");
	}
	else if(x==0){
		int z = num_design;
		design_ave = enter_points_novary(num_design, "design ", "Design ");
	}
	return design_ave;
}

float critique(int num_critique){
//asks for the amount of critiques, calculates average, sends back to recitation function

   int x = 0;
   float critique_ave = 0;
   	cout << "How many critiques?" << endl;
	cin >> num_critique;
	cout << "Do the values vary? 1-yes or 0-no" << endl;
	cin >> x;
	if(x==1){
	   	int z = num_critique;
		critique_ave = enter_points_vary(num_critique, "Critique ");
	}
	else if(x==0){
		int z = num_critique;
		critique_ave = enter_points_novary(num_critique, "critique ", "Critique ");
	}
	return critique_ave;
}

float tests(int num_test){
//asks for the amount of tests, uses other functions to calculate average, prints out average   

   int x=0;
   float ave=0, test_ave=0;
	cout << "How many tests?" << endl;
   	cin >> num_test;
	cout << "Do the point values vary? 1-yes or 0-no" << endl;
	cin >>x;
	if(x==1){
		int z=num_test;
		ave=enter_points_vary(num_test, "Test ");
	}
	else if(x==0){
		int z=num_test;
		ave=enter_points_novary(num_test, "test ", "Test ");
	}
	cout << "Your test average is " << ave << endl;
	test_ave=ave;
	return test_ave;
}

float the_class(){
//uses almost all other functions in order to calculate class average   

    int wtest=0, wrecitation=0, wlab=0, wassign=0, wfinal=0, points=0;
    int num_lab=0, num_assign=0, num_quiz=0, num_test=0;
    float average=0, lab_ave=0, assign_ave=0, rec_ave=0, test_ave=0, score=0, final_ave=0;
    cout << "Test weight: " << endl;
    cin >> wtest;
    cout << "Recitation weight: " << endl;
    cin >> wrecitation;
    cout << "Lab weight: " << endl;
    cin >> wlab;
    cout << "Assignment weight:" << endl;
    cin >> wassign;
    cout << "Final exam weight: " << endl;
    cin >> wfinal;

    if(wlab>0){
    	lab_ave=lab(num_lab);
    }
    if (wassign>0){ 
       assign_ave=assign(num_assign);
    }   
    if (wrecitation>0){
       rec_ave=recitation(num_quiz);
    }    
    if (wtest>0){
       test_ave = tests(num_test);
    }   
    if(wfinal>0){
    	cout << "Enter score on final grade: " << endl;
	cin >> score;
	cout << "How many points is that out of?: " << endl;
	cin >> points;
	final_ave = (score/points);
    }

    average = (lab_ave*(wlab/100))+(assign_ave*(wassign/100))+
	  (rec_ave*(wrecitation/100))+(test_ave*(wtest/100) + (final_ave*(wfinal/100)));
    cout << "Your class average is " << average << endl;
    
    return average;
}





